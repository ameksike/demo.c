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
 
#include "Message.h"

modemess Message::mode = MESS_ALL;
bool Message::endline = true;

void Message::send(QString data, QString source)
{
    switch(mode)
    {
        case MESS_ALL:
            if(!endline) cout << " << " << data.toStdString();
            else   cout << endl << " << " << data.toStdString();
            Log::save(data, source);
        break;

        case MESS_STD:
            if(!endline) cout << " << " << data.toStdString();
            else   cout << endl << " << " << data.toStdString();
        break;

        case MESS_LOG:
            Log::save(data, source);
        break;
    }
}
