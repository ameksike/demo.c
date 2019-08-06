
#ifndef IFACECMDIO_H
#define IFACECMDIO_H

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

#include "IfaceCMD.h"

class IfaceCMDIO : public IfaceCMD
{
    protected:
        void on();
    public:
        IfaceCMDIO();
};

#endif // IFACECMDIO_H
