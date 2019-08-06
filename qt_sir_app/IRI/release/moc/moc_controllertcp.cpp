/****************************************************************************
** Meta object code from reading C++ file 'controllertcp.h'
**
** Created: Wed Feb 22 16:33:43 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/controllertcp.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'controllertcp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_controllerTcp[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   15,   14,   14, 0x05,
      34,   14,   14,   14, 0x05,
      56,   15,   14,   14, 0x05,
      77,   14,   14,   14, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_controllerTcp[] = {
    "controllerTcp\0\0,\0Log(QString,int)\0"
    "sendTrama(QByteArray)\0emitLog(QString,int)\0"
    "emitIsDisconected()\0"
};

const QMetaObject controllerTcp::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_controllerTcp,
      qt_meta_data_controllerTcp, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &controllerTcp::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *controllerTcp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *controllerTcp::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_controllerTcp))
        return static_cast<void*>(const_cast< controllerTcp*>(this));
    return QThread::qt_metacast(_clname);
}

int controllerTcp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: Log((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: sendTrama((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 2: emitLog((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: emitIsDisconected(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void controllerTcp::Log(QString _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void controllerTcp::sendTrama(QByteArray _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void controllerTcp::emitLog(QString _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void controllerTcp::emitIsDisconected()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
