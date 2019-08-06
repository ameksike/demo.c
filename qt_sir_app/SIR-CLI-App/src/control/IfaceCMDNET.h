#ifndef IFACECMDNET_H
#define IFACECMDNET_H

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

#include "IfaceCMD.h"

class IfaceCMDNET : public IfaceCMD
{
    protected:
        void on();
    public:
        IfaceCMDNET();
};

#endif // IFACECMDNET_H
