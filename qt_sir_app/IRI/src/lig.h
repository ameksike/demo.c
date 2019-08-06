#ifndef LIG_H
#define LIG_H

#include <QSettings>
#include <QFile>
#include <QCoreApplication>
#include <QDebug>
#include <QtGlobal>
#include <QMutexLocker>
#include <QReadLocker>
#include "src/controllertcp.h"
#include "src/controllertcp.h"
#include "src/controllerNgn.cpp.h"
#include "src/deliveryfunction.h"
#
class CoreEventDistpatcher;

class LIG : public QCoreApplication
{
    Q_OBJECT
private:
    controllerTcp *TCP_Server;
    controllerNgn *NgnQEvent;
    DeliveryFunction *df;//envio de iris al ftp o rose
public:
    LIG(int argc, char* argv[]);

    QSettings* getSettings();

    int run();

    ~LIG();



private:
    void init();

    void setDefaultConfiguration();
    QSettings*settings;
    void loadConfiguration();
private slots:
    void proccessEvent(QX2Event*e);

signals :
        void  signalsReciveData(QByteArray);

};

#endif // LIG_H
