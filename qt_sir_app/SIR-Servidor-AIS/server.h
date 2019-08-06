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

#ifndef SERVER_H
#define SERVER_H

#include <QDialog>
#include <QtNetwork>

QT_BEGIN_NAMESPACE
class QLabel;
class QPushButton;
class QTcpServer;
class QNetworkSession;
QT_END_NAMESPACE

//! [0]
class Server : public QDialog
{
    Q_OBJECT

public:
    Server(QWidget *parent = 0);
    QList<QTcpSocket*>* clients;
    QStringList* tramas;
    int pos;
    int port;

public slots:
    void sessionOpened();
    void sendFortune();
    void slotOnRead();
    void sendMess();
    void onDisconnect();

private:
    QLabel *statusLabel;
    QPushButton *quitButton;
    QTcpServer *tcpServer;
    QStringList fortunes;
    QNetworkSession *networkSession;
};
//! [0]

#endif
