
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
 
#include "Log.h"

void Log::save(QString data, QString source)
{
    QFile file(source);
    if (!file.open(QIODevice::Append | QIODevice::Text))
        return;

    QTextStream out(&file);
    out <<  " Date:" << QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm:ss AP");
    out << ", Data:" << data << "\n";
}
