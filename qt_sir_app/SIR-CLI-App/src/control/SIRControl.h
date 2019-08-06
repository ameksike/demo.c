#ifndef SIRCONTROL_H
#define SIRCONTROL_H

/**
 *
 * @framework: Qt 4.7.3
 * @package: app
 * @subpackage: src
 * @version: 0.1
 * @description: SIRControl gestiona la instanciacion de drivers
 * @authors: ing. Antonio Membrides Espinosa
 * @making-Date: 30/03/2012
 * @update-Date: 30/03/2012
 * @license: GPL v3
 *
 */

#include "src/lib/xml/QXmlMetaReader.h"
#include "src/lib/iface/IfaceReceptor.h"

#include <QList>
#include <QPluginLoader>

class SIRControl
{
    private:
        QXmlMetaReader cfg;
        QList<IfaceReceptor*>* receptors;

    public:
        SIRControl(QString _filecfg = "", QString _plugins = "plugin/");
        void load(QString _filecfg = "");
        void on(int index=-1);
        void off(int index=-1);
        int actives();

    public:
        QString filecfg;
        QString plugins;

     protected:
        IfaceReceptor* factory(QXmlMetaReader, QString);
};

#endif // SIRCONTROL_H
