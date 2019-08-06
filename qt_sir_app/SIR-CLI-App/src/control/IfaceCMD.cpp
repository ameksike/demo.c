/**
 *
 * @framework: Qt 4.7.3
 * @package: app
 * @subpackage: src
 * @version: 0.1
 * @description: IfaceCMD define el comportamiento CLI del sistema
 * @authors: ing. Antonio Membrides Espinosa
 * @making-Date: 30/03/2012
 * @update-Date: 30/03/2012
 * @license: GPL v3
 *
 */
#include "IfaceCMD.h"

IfaceCMD::IfaceCMD():QThread()
{
    this->clicmdlst << "on" << "off" << "info" << "exit" << "help" << "load";
    this->status = 1;
}

void IfaceCMD::run()
{
    this->on();
}
