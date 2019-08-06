#ifndef CONTROLLERTCP_H
#define CONTROLLERTCP_H

#include <QThread>

#include <QtNetwork>
#include "src/tcpserver.h"
#include "src/Controler.h"

class controllerTcp : public QThread
{
    Q_OBJECT

   void setController(Controller *controller);
    Controller*    controladora;
public:
    controllerTcp(QObject *parent = 0);

protected:
    void run();

signals:

    void Log(QString,int);
    void sendTrama(QByteArray);
    void emitLog(QString,int);
    void emitIsDisconected();
};

#endif // CONTROLLERTCP_H
