#include "src/controllertcp.h"
#include <QDebug>
#include <QtNetwork>
controllerTcp::controllerTcp(QObject *parent)

{

}
void controllerTcp::run()
{
    TCPServer newTCPServer("XPTU_NGN_FIJA");
    connect(&newTCPServer,SIGNAL(signalsDatosXptu(QByteArray)),this,SIGNAL(sendTrama(QByteArray)));
    connect(&newTCPServer,SIGNAL(isDisconnect()),this,SIGNAL(emitIsDisconected()));
    newTCPServer.start();
    exec();
}
