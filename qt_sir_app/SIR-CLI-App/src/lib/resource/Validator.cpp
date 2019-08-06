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

#include "Validator.h"
#include <QDebug>

Validator::Validator(){
    type << "VARCHAR" << "DOUBLE" << "TIMES" << "TIMESTAMP" << "DATE" << "INTEGER";
}

bool Validator::isDate(QString fields)
{
    QRegExp rx("^([0-9]{2}/[0-9]{2}/[0-9]{4})$");
    return rx.exactMatch(fields);
}
bool Validator::isTimes(QString fields)
{
    QRegExp rx("^([0-9]{2}:[0-9]{2}:[0-9]{2})$");
    return rx.exactMatch(fields);
}
bool Validator::isTimestamp(QString fields)
{
    QRegExp rx("^([0-9]{2}/[0-9]{2}/[0-9]{4}) ([0-9]{2}:[0-9]{2}:[0-9]{2})$");
    return rx.exactMatch(fields);
}

bool Validator::isInteger(QString fields)
{
    QRegExp rx("^(\\d+)$");
    return rx.exactMatch(fields);
}
bool Validator::isDouble(QString fields)
{
    return true;
}
bool Validator::isVarchar(QString fields, int precision)
{
    QString rxstr ("^\\w");
    if(precision){
        rxstr += "{0,";
        rxstr += "8";
        rxstr += "}";
    }
    rxstr += "$";
    QRegExp rx(rxstr);
    return true;
    return rx.exactMatch(fields);
}
bool Validator::isValid(QString fields, int typeval, int precision)
{
    switch(typeval)
    {
        case INTEGER:     return this->isInteger(fields); break;
        case DOUBLE:      return this->isDouble(fields); break;
        case VARCHAR:     return this->isVarchar(fields, precision); break;
        case TIMES:       return this->isTimes(fields); break;
        case TIMESTAMP:   return this->isTimestamp(fields); break;
        case DATE:        return this->isDate(fields); break;
        default:          return false; break;
    }
    return false;
}

bool Validator::isValid(QString fields, QString typeval, int precision)
{
    return this->isValid(fields, this->type.indexOf(typeval), precision);
}
