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
 
#include "ControlCMD.h"

enum CLICMD{ CMD_ON, CMD_OFF, CMD_INFO, CMD_EXIT, CMD_HELP, CMD_LOAD };

ControlCMD::ControlCMD(QString configpath, QString pluginpath, QString modecontrol, QString _helpath)
{
    this->control = new SIRControl(configpath, pluginpath);
    Message::send( "Welcome to SIR system version 1.0");
    helpdoc = new QFile(_helpath);
    this->mode = modecontrol;
    this->helpath = _helpath;
}

void ControlCMD::run() { }

void ControlCMD::listen(int _cmd, QString params)
{

    switch(_cmd)
    {
            case CMD_ON:
                    this->control->on();
            break;

            case CMD_OFF:
                    this->control->off();
            break;

            case CMD_LOAD:
                    this->control->load();
            break;

            case CMD_INFO:
                if(params.isEmpty() || params=="-all"){
                    Message::send( ".................................");
                    Message::send( "  Information of SIR system v1.0:");
                    Message::send( ".................................");
                    Message::send(QString(" * the control mode is >> ") + this->mode);
                    Message::send(QString(" * receptor's actives  >> ") + QString::number(this->control->actives()));
                    Message::send(QString(" * plugin's dir are in >> ") + this->control->plugins);
                    Message::send(QString(" * file config are in  >> ") + this->control->filecfg);
                    Message::send(QString(" * file of help are in >> ") + this->helpath);
                    Message::send(QString(".........................."));
                }else{
                    if(params=="-active") Message::send(QString::number(this->control->actives()));
                    else if(params=="-config") Message::send(this->control->filecfg);
                    else if(params=="-plugins") Message::send(this->control->plugins);
                    else if(params=="-mode") Message::send(this->mode);
                }
            break;

            case CMD_HELP:

                    if (!helpdoc->isOpen() && !helpdoc->open(QIODevice::ReadOnly | QIODevice::Text)) {
                        Message::send( ".................................");
                        Message::send( "  Help of SIR system v1.0:");
                        Message::send( ".................................");
                        Message::send( " document of help its not found");
                        Message::send( ".................................");
                    }else{
                        Message::endline = false;
                        while (!helpdoc->atEnd()) {
                            QByteArray line = helpdoc->readLine();
                            Message::send( line.data() );
                        }
                        Message::endline = true;
                        helpdoc->close();
                    }

            break;

            case CMD_EXIT:
                Message::send( "Out of SIR system version 1.0");
                emit exiting();
            break;

            default:
                Message::send( "Invalid comand, please try against");
            break;
    }
}
