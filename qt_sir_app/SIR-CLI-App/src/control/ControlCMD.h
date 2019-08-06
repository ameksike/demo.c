
#ifndef CONTROLCMD_H
#define CONTROLCMD_H

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

#include <stdio.h>
#include <QThread>
#include "src/lib/resource/Message.h"
#include "src/control/SIRControl.h"

class ControlCMD : public QThread
{
        Q_OBJECT
    public:
       QString data;
       QString mode;
       QString helpath;

    protected:
       SIRControl* control;
       QFile* helpdoc;

    public:
       ControlCMD(QString configpath, QString pluginpath, QString mode, QString helppath);
       void run();

    public slots:
       void listen(int _cmd, QString params="");

    signals:
       void exiting();
};

#endif // CONSUMER_H
