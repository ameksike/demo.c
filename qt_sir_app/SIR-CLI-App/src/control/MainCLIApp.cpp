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
 
#include "MainCLIApp.h"
#include <QDebug>

MainCLIApp::MainCLIApp(int argc, char *argv[]): QCoreApplication(argc, argv)
{
    this->buildIfaceCMD();
    this->buildControlCMD();
    this->buildlinks();
 }

void MainCLIApp::on()
{
    this->ifacecmd->start();
    this->controlcmd->start();
}

QString MainCLIApp::getOption(QString option)
{
    QString out = "";
    for(int i=1; i<this->argc(); i++){
        QStringList arg = arguments().at(i).split("=");
        if(option == arg[0])  return arg[1];
    }
    return out;
}

void MainCLIApp::buildIfaceCMD()
{
    this->ifacecmd = 0;
    QString modecontrol = this->getOption("mode");
    if(modecontrol.isEmpty()) modecontrol = "local";

    if(modecontrol == "remote") this->ifacecmd = new IfaceCMDNET ();
    else if(modecontrol == "local") this->ifacecmd = new IfaceCMDIO();
}

void MainCLIApp::buildControlCMD()
{
    this->controlcmd = 0;
    QString configpath = this->getOption("config");
    QString pluginpath = this->getOption("plugin");
    QString modecontrol = this->getOption("mode");
    QString helpath = this->getOption("helpdoc");

    if(modecontrol.isEmpty()) modecontrol = "local";
    if(configpath.isEmpty()) configpath = "cfg/config.xml";
    if(pluginpath.isEmpty()) pluginpath = "plugin/";
    if(helpath.isEmpty()) helpath = "cfg/help";

    this->controlcmd = new ControlCMD(configpath, pluginpath, modecontrol, helpath);
}

void MainCLIApp::buildlinks()
{
    if(ifacecmd && controlcmd){
        this->connect(ifacecmd, SIGNAL(onListen(int, QString)),  controlcmd, SLOT(listen(int, QString)));
        this->connect(controlcmd, SIGNAL(terminated()), ifacecmd, SLOT(quit()));
        this->connect(controlcmd, SIGNAL(exiting()), this, SLOT(quit()));
    }
}
