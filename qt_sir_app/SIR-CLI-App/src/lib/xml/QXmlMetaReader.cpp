
/**
 *
 * @framework: Qt 4.7.3
 * @package: xml
 * @subpackage: QXmlMetaReader
 * @version: 0.1

 * @description: Define una capa de abstracción que permite leer un xml en forma de arreglo asociativo, las claves son VALUE: valor, ATTRI: valor de una propiedad determnida, CHILD: listado de elementos hijos   
		ejemplo:
			<root inf = "roots-inf"> 
				<tmp inf = "r2.0" value="tmp-val1"> data1 </tmp>
				<tmp inf = "tmp-val2"		  > data2 </tmp>
				<tst val = "mist"> 
					<tm1> tm1A </tm1>
					<tm1> tm1B </tm1>
					<tm1> tm1C </tm1>
					<tm1> tm1D </tm1>
				</tst>
			</root>
		source:
			QXmlMetaReader reader("lconfig.xml");
			qDebug() << "CHILDR--->:" << reader[VALUE];
			qDebug() << "ATTRIR--->:" << reader[ATTRI]["inf"];

			qDebug() << "VALUE---->:" << reader["tst"][0][VALUE];
			qDebug() << "ATTRI---->:" << reader["tst"][0][ATTRI]["val"];

			for(int i=0; i< reader["tst"][0][CHILD]["tm1"].count(); i++)
				qDebug() << "CHILD---->:" << reader["tst"][0][CHILD]["tm1"][i][VALUE];

		pendiente: se debe corregir en función de minimizar costos por concepto de memoria, debe orientarse al trabajo con *
 * @authors: ing. Antonio Membrides Espinosa
 * @making-Date: 30/03/2012
 * @update-Date: 30/03/2012
 * @license: GPL v3
 *
 */
 
#include "QXmlMetaReader.h"
#include <QDebug>
//----------------------------------------------------- QXmlMetaItem
QXmlMetaItem::QXmlMetaItem(QDomElement _elm)
{
    this->elm = _elm;
}

QXmlMetaReader QXmlMetaItem::operator [](double child)
{
    QXmlMetaReader reader(this->elm);
    return  reader;
}

QXmlMetaAttribute QXmlMetaItem::operator [](char attribute)
{
    QXmlMetaAttribute out(this->elm);
    return out;
}

QString QXmlMetaItem::operator [](int value)
{
    return  this->elm.text();
}
//----------------------------------------------------- QXmlMetaAttribute
QXmlMetaAttribute::QXmlMetaAttribute(QDomElement _conten)
{
    this->elm = _conten;
}

QString QXmlMetaAttribute::operator [](QString _attribute)
{
    return this->elm.attribute(_attribute);
}
//------------------------------------------------------ QXmlMetaTags
QXmlMetaTags::QXmlMetaTags(QDomNodeList _lst)
{
    this->lst = _lst;
}

QXmlMetaItem QXmlMetaTags::operator [](int index)
{
    QDomElement el = this->lst.at(index).toElement();
    QXmlMetaItem item(el);
    return item;
}

int QXmlMetaTags::count()
{
    return this->lst.count();
}
//------------------------------------------------------ QXmlMetaReader
QXmlMetaReader::QXmlMetaReader(QString source)
{
    if(!source.isEmpty())
        if(!this->load(source)) qDebug("log::error at load file xml");
        else qDebug("log::file xml is loaded");
}

QXmlMetaReader::QXmlMetaReader(QDomElement _elm)
{
    this->elm = _elm;
}

bool QXmlMetaReader::load(QString source)
{
    QFile file(source);
    if (!file.open(QIODevice::ReadOnly)) return false;
    if (!this->doc.setContent(&file)) return false;
    this->elm = this->doc.documentElement();
    return true;
}

QDomNodeList QXmlMetaReader::at(QString tag)
{
    return elm.elementsByTagName(tag);
}

QDomElement QXmlMetaReader::at(QString tag, int index)
{
    return this->at(tag).at(index).toElement();
}

QXmlMetaTags QXmlMetaReader::operator [](QString tag)
{
    QXmlMetaTags tags(elm.elementsByTagName(tag));
    return tags;
}

QString QXmlMetaReader::operator[](int value)
{
    return  this->elm.text();
}

QXmlMetaAttribute QXmlMetaReader::operator[](char attribute)
{
    QXmlMetaAttribute out(this->elm);
    return  out;
}
//--------------------------------------------------------
