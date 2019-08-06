
#ifndef IFACECMD_H
#define IFACECMD_H

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

#include <QThread>
#include <QStringList>
#include <iostream>
#include <iomanip>
using namespace std;

class IfaceCMD : public QThread
{
        Q_OBJECT

    protected:
        QStringList clicmdlst;
        int status;

    protected:
        void run();
        virtual void on()=0;

    public:
        IfaceCMD();

    signals:
        void onListen(int cmd, QString params);
};

#endif // SIRAPPCLI_H



