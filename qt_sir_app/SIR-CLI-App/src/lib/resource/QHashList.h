#ifndef QHASHLIST_H
#define QHASHLIST_H

#include <QList>
#include <QStringList>

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

template <class T>
class QHashList : public QList<T>
{
    protected:
        QStringList* keys;

    public:
        inline QHashList(){
            keys = new QStringList();
        }

        inline ~QHashList(){
            delete keys;
        }

        inline T operator [](QString key)
        {
            return this->in(key);
        }

        inline T operator [](int key)
        {
            return this->at(key);
        }

        inline void add(T data, QString key="")
        {
            this->append(data);
            if(key.isEmpty()) key = QString::number(this->length()-1);
            keys->append(key);
        }

        inline T in(QString key)
        {
            int pos = keys->indexOf(key);
            return this->at(pos);
        }
};

#endif // QHASHLIST_H
