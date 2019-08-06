/**
 *
 * @framework: Qt 4.7.3
 * @package: app
 * @subpackage: src
 * @version: 0.1
 * @description: IfaceCMD define el comportamiento CLI del sistema, basado en los mecanismos de entrada y salida estandar
 * @authors: ing. Antonio Membrides Espinosa
 * @making-Date: 30/03/2012
 * @update-Date: 30/03/2012
 * @license: GPL v3
 *
 */
 
#include "IfaceCMDIO.h"

#include <QDebug>

IfaceCMDIO::IfaceCMDIO():IfaceCMD()
{
}

void IfaceCMDIO::on()
{
    char _cmd[255];
    while(this->status)
    {
            cout << "\n >> ";
            cin.getline(_cmd, 255, '\n');
            QStringList ccmds = QString(_cmd).toLower().split(" ");
            QString param = ccmds.count()>1 ? ccmds[1] : "";
            int ccmd = this->clicmdlst.indexOf(ccmds[0]);
            emit onListen(ccmd, param);
            sleep(1);
    }
}
