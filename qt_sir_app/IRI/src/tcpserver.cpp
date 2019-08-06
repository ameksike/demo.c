#include "src/tcpserver.h"

#include <QtNetwork>

TCPServer::TCPServer(QString serviceName, QObject *parent): serviceName(serviceName)
{

}

TCPServer::~TCPServer()
{

}
void TCPServer::start()
{
    tcpServer = new QTcpServer(this);

    this->setController(ControllerFactory::getController( this->serviceName ) );

    if (!tcpServer->listen( QHostAddress::Any, 8888))
    {
        qDebug() << tcpServer->errorString();
        return;
    }
    QString ipAddress;
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();

    for (int i = 0; i < ipAddressesList.size(); ++i)
    {
        if (ipAddressesList.at(i) != QHostAddress::LocalHost &&	ipAddressesList.at(i).toIPv4Address())
            ipAddress = ipAddressesList.at(i).toString();
    }

    if (ipAddress.isEmpty())
        ipAddress = QHostAddress(QHostAddress::Any).toString();

    qDebug("Port: %d", tcpServer->serverPort());
    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(clientConnected()));
    // this->tcpServer->setMaxPendingConnections(1);

    connect(&this->timer,SIGNAL(timeout()),this,SLOT(TimeOutXptu()));
//    this->timer.start(290000);
}
void TCPServer::clientConnected()
{
    qDebug() << "Cliente conectado";
    client = tcpServer->nextPendingConnection();
    connect(client, SIGNAL(disconnected()), this, SLOT(clienteDesconectado()));
    connect(client, SIGNAL(bytesWritten(qint64)), this, SLOT(enviados(qint64)));
    connect(client,SIGNAL(readyRead()), this,SLOT(readData()));
}


void TCPServer::enviados(qint64 bytesTrans)
{
    qDebug() << "enviados :" << bytesTrans << endl;
}

void TCPServer::clienteDesconectado()
{
  qDebug()<<"void TCPServer::clienteDesconectado()";
}

void TCPServer::TimeOutXptu()
{
    qDebug()<<"Comprobando cx";
    timer.stop();
    qDebug()<<"Cerrando el Servidor";

    tcpServer->close();
    sleep(5);
    qDebug()<<"Iniciando el Servidor";
    if (!tcpServer->listen( QHostAddress::Any, 8888))
    {
        qDebug() << tcpServer->errorString();
    }
    timer.start(290000);

}
void TCPServer::readData()
{

    QByteArray data;
    qDebug()<<"void TCPServer::readData()";

    this->setEstado( TCPServer::RECIBIENDO_DATOS );
    QTcpSocket* dev = (QTcpSocket*)sender();
    data=dev->readAll();
    if( data.length()>10 )
    {
        emit signalsDatosXptu( data );
         qDebug()<<" //emit signalsDatosXptu( data );"<<cont++;
         if(cont==100000)
             cont=0;
        emit  this->isDisconnect();
    }

   //dev->deleteLater();
    this->setEstado( TCPServer::IDLE );

     qDebug()<<"fin void TCPServer::readData()";

}
void  TCPServer::setController(Controller *controller)
{

//    this->controladora = controller;
//    this->controladora->setParent( this );
//    connect(this, SIGNAL(signalsDatosXptu(QByteArray)), this->controladora, SIGNAL(signalProcesarDatos(QByteArray)));
//    connect(this->controladora, SIGNAL(signalDatosProcesados()), this, SLOT(slotDatosProcesadosController()));
//    this->setEstado( TCPServer::activa);

}
