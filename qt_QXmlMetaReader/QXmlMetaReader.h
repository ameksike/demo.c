#ifndef QXMLMETAREADER_H
#define QXMLMETAREADER_H

#include <QtXml/QDomDocument>
#include <QtXml/QDomElement>
#include <QString>
#include <QFile>

#define VALUE 5   //... QString
#define CHILD 5.5 //... QXmlMetaReader
#define ATTRI 'A' //... QXmlMetaAttribute

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

class QXmlMetaReader;
class QXmlMetaAttribute
{
    protected:
        QDomElement elm;
    public:
        QXmlMetaAttribute(QDomElement conten=0);
        QString operator[](QString);
};

class QXmlMetaItem
{
    protected:
        QDomElement elm;

    public:
        QXmlMetaItem(QDomElement _elm=0);

        virtual QString operator[](int value);
        virtual QXmlMetaReader operator[](double child);
        virtual QXmlMetaAttribute operator[](char attribute);
};

class QXmlMetaTags
{
    protected:
        QDomNodeList lst;

    public:
        QXmlMetaTags(QDomNodeList _lst);
        QXmlMetaItem operator[](int value);
        int count();
};

class QXmlMetaReader : public QXmlMetaItem
{
    protected:
        QDomDocument doc;
        QDomElement it;

    public:
        QXmlMetaReader(QString source="");
        QXmlMetaReader(QDomElement _iterator);
        bool load(QString);
        QDomNodeList at(QString);
        QDomElement  at(QString, int);

        QXmlMetaTags operator[](QString);
        QString operator[](int value);
        QXmlMetaAttribute operator[](char attribute);
};

#endif // QXMLMETAREADER_H
