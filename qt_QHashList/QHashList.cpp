/**
 *
 * @framework: Qt 4.7.3
 * @package: Driver
 * @subpackage: resource
 * @version: 0.1

 * @description: librería que permite crear una capa de abstracción para utilizar las listas hash, e indexar elementos a traves de calvez semánticas
        ejemplo:
            QHashList<Person*> list = new QHashList<Person*>();

            list->add(new Person("Juan",  23), "juan");
            list->add(new Person("Julia", 12), "julia");
            list->add(new Person("johan", 50), "johan");

            Person* juanObj = (*list)["juan"];
            Person* juanObj = (*list)[0];

 * @authors: ing. Antonio Membrides Espinosa
 * @making-Date: 10/04/2012
 * @update-Date: 10/04/2012
 * @license: GPL v3
 *
 */
 

#include "QHashList.h"

QHashList::QHashList()
{
}
