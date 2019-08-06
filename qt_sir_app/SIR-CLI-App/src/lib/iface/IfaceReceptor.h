#ifndef IFACERECEPTOR_H
#define IFACERECEPTOR_H

#include <QtPlugin>

//QT_BEGIN_NAMESPACE
class QString;
class QXmlMetaReader;
//QT_END_NAMESPACE

/**
 *
 * @framework: Qt 4.7.3
 * @package: Driver
 * @subpackage: iface
 * @version: 0.1

 * @description: Define el comportamiento para un driver
 * @authors: ing. Antonio Membrides Espinosa
 * @making-Date: 10/03/2012
 * @update-Date: 10/03/2012
 * @license: GPL v3
 *
 */

class IfaceReceptor
{
        public:
            virtual ~IfaceReceptor() {}
            virtual void on() = 0;
            virtual void off() = 0;
            virtual void setting(QXmlMetaReader)=0;
            virtual void setting(QString)=0;
};

QT_BEGIN_NAMESPACE
Q_DECLARE_INTERFACE(IfaceReceptor, "com.trolltech.PlugAndPaint.BrushInterface/1.0")
QT_END_NAMESPACE

#endif // IFACERECEPTOR_H
