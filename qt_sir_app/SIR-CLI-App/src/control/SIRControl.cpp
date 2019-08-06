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
 
#include "SIRControl.h"
#include <QDebug>

SIRControl::SIRControl(QString _filecfg, QString _plugins)
{
    this->filecfg = _filecfg;
    this->plugins = _plugins;
    this->receptors = new QList<IfaceReceptor*>();
    if(!_filecfg.isEmpty()) this->load(_filecfg);
}

void SIRControl::on(int index)
{
    if(index != -1) this->receptors->at(index)->on();
    else for(int i=0; i< this->receptors->count(); i++)
        this->receptors->at(i)->on();
}

void SIRControl::off(int index)
{
    if(index != -1) this->receptors->at(index)->off();
    else for(int i=0; i< this->receptors->count(); i++)
        this->receptors->at(i)->off();
}

void SIRControl::load(QString _filecfg)
{
    this->receptors->clear();
    if(_filecfg.isEmpty()) _filecfg = this->filecfg;
    this->cfg = QXmlMetaReader(_filecfg);

    for(int i=0; i< this->cfg["radar"].count(); i++)
    {
        IfaceReceptor* newreceptor = this->factory(
            this->cfg["radar"][i][CHILD],
            this->cfg["radar"][i][ATTRI]["type"].toUpper()
        );
        if(newreceptor) this->receptors->append( newreceptor );
        else qDebug() << "log::driver" << this->cfg["radar"][i][ATTRI]["type"] << "is not supported";
    }
}

IfaceReceptor* SIRControl::factory(QXmlMetaReader _cfg, QString type)
{
    IfaceReceptor* iReceptor = 0;
    QString path = this->plugins;
    path += type;
    path += ".so";

    QPluginLoader loader(path);
    QObject *plugin = loader.instance();

    if(plugin)
    {
        iReceptor = qobject_cast<IfaceReceptor *>(plugin);
        iReceptor->setting(_cfg);
    }

    return iReceptor;
}

int SIRControl::actives()
{
    return this->receptors->count();
}
