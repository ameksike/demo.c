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

#include <QApplication>
#include <QtCore>
#include <QTimer>
#include <stdlib.h>

#include "server.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Server server;
#ifdef Q_OS_SYMBIAN
    server.showMaximized();
#else
    server.show();
#endif
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    //QTimer::singleShot(6000, &app, SLOT(quit()));
    return server.exec();

}
