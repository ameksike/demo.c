#ifndef MAINCLIAPP_H
#define MAINCLIAPP_H

/**
 *
 * @framework: Qt 4.7.3
 * @package: app
 * @subpackage: src
 * @version: 0.1
 * @description: MainCLIApp gestiona la contruccion de la aplicacion
 * @authors: ing. Antonio Membrides Espinosa
 * @making-Date: 30/03/2012
 * @update-Date: 30/03/2012
 * @license: GPL v3
 *
 */

#include <QtCore/QCoreApplication>
#include "src/control/IfaceCMDIO.h"
#include "src/control/IfaceCMDNET.h"
#include "src/control/ControlCMD.h"

class MainCLIApp : public QCoreApplication
{
    protected:
        IfaceCMD* ifacecmd;
        ControlCMD* controlcmd;

    protected:
        QString getOption(QString option);
        virtual void buildIfaceCMD();
        virtual void buildControlCMD();
        virtual void buildlinks();

    public:
        MainCLIApp(int argc, char *argv[]);
        void on();
};

#endif // MAINCLIAPP_H
