/**
 *
 * @framework: Qt 4.7.3
 * @package: app
 * @subpackage: src
 * @version: 0.1
 * @description: ControlCMD gestiona la invocacion de comandos
 * @authors: ing. Antonio Membrides Espinosa
 * @making-Date: 30/03/2012
 * @update-Date: 30/03/2012
 * @license: GPL v3
 *
 */

#include <QtGui>


#include <stdlib.h>

#include "server.h"

Server::Server(QWidget *parent)
:   QDialog(parent), tcpServer(0), networkSession(0)
{
    this->clients = new QList<QTcpSocket*>();
    this->tramas = new QStringList();
    this->port = 5000;

    QFile file("AIS-TRAMA.log");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    while (!file.atEnd()) {
        QByteArray line = file.readLine();
        this->tramas->append(line.data());
    }

    /*for(int i=0; i< this->tramas->size(); i++){
        qDebug() << this->tramas->at(i);
    }*/

    this->pos = 0;


    //----------------------------------
    statusLabel = new QLabel;
    quitButton = new QPushButton(tr("Quit"));
    quitButton->setAutoDefault(false);

    QNetworkConfigurationManager manager;
    if (manager.capabilities() & QNetworkConfigurationManager::NetworkSessionRequired) {
        // Get saved network configuration
        QSettings settings(QSettings::UserScope, QLatin1String("Trolltech"));
        settings.beginGroup(QLatin1String("QtNetwork"));
        const QString id = settings.value(QLatin1String("DefaultNetworkConfiguration")).toString();
        settings.endGroup();

        // If the saved network configuration is not currently discovered use the system default
        QNetworkConfiguration config = manager.configurationFromIdentifier(id);
        if ((config.state() & QNetworkConfiguration::Discovered) !=
            QNetworkConfiguration::Discovered) {
            config = manager.defaultConfiguration();
        }

        networkSession = new QNetworkSession(config, this);
        connect(networkSession, SIGNAL(opened()), this, SLOT(sessionOpened()));

        statusLabel->setText(tr("Opening network session."));
        networkSession->open();
    } else {
        sessionOpened();
    }

    //! [2]
        fortunes << tr("You've been leading a dog's life. Stay off the furniture.")
                 << tr("You've got to think about tomorrow.")
                 << tr("You will be surprised by a loud noise.")
                 << tr("You will feel hungry again in another hour.")
                 << tr("You might have mail.")
                 << tr("You cannot kill time without injuring eternity.")
                 << tr("Computers are not intelligent. They only think they are.");
    //! [2]

        connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
    //! [3]
        connect(tcpServer, SIGNAL(newConnection()), this, SLOT(sendFortune()));
    //! [3]

        QHBoxLayout *buttonLayout = new QHBoxLayout;
        buttonLayout->addStretch(1);
        buttonLayout->addWidget(quitButton);
        buttonLayout->addStretch(1);

        QVBoxLayout *mainLayout = new QVBoxLayout;
        mainLayout->addWidget(statusLabel);
        mainLayout->addLayout(buttonLayout);
        setLayout(mainLayout);

        setWindowTitle(tr("AIS Server"));
}

void Server::sessionOpened()
{
    // Save the used configuration
    if (networkSession) {
        QNetworkConfiguration config = networkSession->configuration();
        QString id;
        if (config.type() == QNetworkConfiguration::UserChoice)
            id = networkSession->sessionProperty(QLatin1String("UserChoiceConfiguration")).toString();
        else
            id = config.identifier();

        QSettings settings(QSettings::UserScope, QLatin1String("Trolltech"));
        settings.beginGroup(QLatin1String("QtNetwork"));
        settings.setValue(QLatin1String("DefaultNetworkConfiguration"), id);
        settings.endGroup();
    }
    //----------------------------------- get ip ---------------------
    QString ipAddress;
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    // use the first non-localhost IPv4 address
    for (int i = 0; i < ipAddressesList.size(); ++i) {
        if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
            ipAddressesList.at(i).toIPv4Address()) {
            ipAddress = ipAddressesList.at(i).toString();
            break;
        }
    }
    // if we did not find one, use IPv4 localhost
    if (ipAddress.isEmpty())
        ipAddress = QHostAddress(QHostAddress::LocalHost).toString();

//! [0] //! [1]
    tcpServer = new QTcpServer(this);
    //-------------------------------------- do connect ------------------
    if (!tcpServer->listen(QHostAddress(ipAddress), this->port)) {
        QMessageBox::critical(this, tr("AIS Server"),
                              tr("Unable to start the server: %1.")
                              .arg(tcpServer->errorString()));
        close();
    //---------------------------------------------------- ------------------
        //QObject::connect(tcpServer, SIGNAL(readyRead()), this, SLOT(slotOnRead()));
        return;
    }
//! [0]

    statusLabel->setText(tr("The server is running on\n\nIP: %1\nport: %2\n\n"
                            "Run the Fortune Client example now.")
                         .arg(ipAddress).arg(tcpServer->serverPort()));
//! [1]
}

//! [4]
void Server::sendFortune()
{
//! [5]
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_0);
//! [4] //! [6]
    out << (quint16)0;
    out << fortunes.at(qrand() % fortunes.size());
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));
//! [6] //! [7]

    QTcpSocket *clientConnection = tcpServer->nextPendingConnection();
    connect(clientConnection,SIGNAL(readyRead()), this, SLOT(slotOnRead()));
    connect(clientConnection, SIGNAL(disconnected()), this, SLOT(onDisconnect()));
//! [7] //! [8]
    this->clients->append(clientConnection);

    qDebug() << "clien:" << clientConnection->socketDescriptor() << "conected from:" << clientConnection->localAddress().toString();
    QTimer::singleShot(9000, this, SLOT(sendMess()));

//! [5]
}
//! [8]


void Server::slotOnRead()
{
    qDebug("OnRead ... ");
    QByteArray data;
    QTcpSocket* dev = (QTcpSocket*)sender();
    if(dev) {
        data = dev->readAll().data();
        qDebug()  << "say me: " << data;
        if(data == "cmd") dev->write("svr: tomaaaaaaa");
    }
}

void Server::sendMess()
{
    QTimer::singleShot(9000, this, SLOT(sendMess()));
    QString _data;
    for(int i=0; i< this->clients->size(); i++)
    {
        if(this->pos < this->tramas->size())
        {
            _data = this->tramas->at(this->pos++);

            if(this->clients->at(i))
            {
                if(this->clients->at(i)->isWritable())
                {
                          this->clients->at(i)->write(_data.toLocal8Bit());
                }else{
                    qDebug() << "client at: " << i << "of: " << this->clients->size() << "was disconected";
                }
            }else {
                    qDebug() << "client at: " << i << "of: " << this->clients->size() << "was undefined";
            }
        }

        qDebug() << "ping:" << i << "id:" << this->clients->at(i)->socketDescriptor() << " from:" << this->clients->at(i)->localAddress().toString();
    }
}

void Server::onDisconnect()
{
        QTcpSocket* dev = (QTcpSocket*)sender();

        for(int i=0; i< this->clients->size(); i++)
            if(this->clients->at(i)->socketDescriptor() == dev->socketDescriptor())
            {
                qDebug() << "id:" << this->clients->at(i)->socketDescriptor() << "disconet from:" << dev->localAddress().toString();
                this->clients->at(i)->close();
                this->clients->removeAt(i);
            }
}
