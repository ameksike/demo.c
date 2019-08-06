#ifndef MESSAGE_H
#define MESSAGE_H

/**
 *
 * @framework: Qt 4.7.3
 * @package: Driver
 * @subpackage: resource
 * @version: 0.1

 * @description: Mecanismo para generación de mensages
 * @authors: ing. Antonio Membrides Espinosa
 * @making-Date: 03/05/2012
 * @update-Date: 03/05/2012
 * @license: GPL v3
 *
 */

#include "src/lib/resource/Log.h"
#include <iostream>
using namespace std;

enum modemess { MESS_ALL, MESS_STD, MESS_LOG };
class Message
{
    public:
        static modemess mode;
        static bool endline;

    public:
        static void send(QString data, QString source="trace.log");
};

#endif // MESSAGE_H
