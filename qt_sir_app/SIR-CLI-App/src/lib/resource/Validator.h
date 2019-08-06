/**
 *
 * @framework: Qt 4.7.3
 * @package: Driver
 * @subpackage: resource
 * @version: 0.1

 * @description: Define los mecanismos de validacion de trama
 * @authors: ing. Antonio Membrides Espinosa
 * @making-Date: 15/03/2012
 * @update-Date: 15/03/2012
 * @license: GPL v3
 *
 */

#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <QString>
#include <QStringList>
#include <QRegExp>

enum type { VARCHAR, DOUBLE, TIMES, TIMESTAMP, DATE, INTEGER };

class Validator
{
    private:
        QStringList type;

    public:
        Validator();
        virtual bool isValid(QString, int typeval=VARCHAR, int precision=-1);
        virtual bool isValid(QString, QString typeval="VARCHAR", int precision=-1);

        virtual bool isDate(QString);
        virtual bool isTimes(QString);
        virtual bool isTimestamp(QString);

        virtual bool isInteger(QString);
        virtual bool isDouble(QString);
        virtual bool isVarchar(QString, int precision=-1);
};

#endif // VALIDATOR_H
