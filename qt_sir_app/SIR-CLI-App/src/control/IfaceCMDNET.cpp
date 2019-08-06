/**
 *
 * @framework: Qt 4.7.3
 * @package: app
 * @subpackage: src
 * @version: 0.1
 * @description: IfaceCMD define el comportamiento CLI del sistema, basado en los mecanismos de comunicacion por TCP/UDP
 * @authors: ing. Antonio Membrides Espinosa
 * @making-Date: 30/03/2012
 * @update-Date: 30/03/2012
 * @license: GPL v3
 *
 */

#include "IfaceCMDNET.h"

IfaceCMDNET::IfaceCMDNET()
{
}

void IfaceCMDNET::on()
{
    while(this->status){
        emit onListen(5, "IO");
        sleep(1);
    }
}
