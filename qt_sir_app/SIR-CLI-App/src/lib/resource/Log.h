#ifndef LOG_H
#define LOG_H

/**
 *
 * @framework: Qt 4.7.3
 * @package: Driver
 * @subpackage: resource
 * @version: 0.1

 * @description: Mecanismo para generación de ficheros log
 * @authors: ing. Antonio Membrides Espinosa
 * @making-Date: 10/04/2012
 * @update-Date: 10/04/2012
 * @license: GPL v3
 *
 */

#include <QDateTime>
#include <QFile>
#include <QTextStream>
#include <QString>

class Log
{
    public:
        static void save(QString data, QString source="trace.log");
};

#endif // LOG_H
