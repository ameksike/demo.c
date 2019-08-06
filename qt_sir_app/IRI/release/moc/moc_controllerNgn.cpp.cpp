/****************************************************************************
** Meta object code from reading C++ file 'controllerNgn.cpp.h'
**
** Created: Wed Feb 22 16:33:44 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/controllerNgn.cpp.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'controllerNgn.cpp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_controllerNgn[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x05,
      37,   14,   14,   14, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_controllerNgn[] = {
    "controllerNgn\0\0signalMgs(QByteArray)\0"
    "signalsQX2Events(QX2Event*)\0"
};

const QMetaObject controllerNgn::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_controllerNgn,
      qt_meta_data_controllerNgn, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &controllerNgn::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *controllerNgn::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *controllerNgn::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_controllerNgn))
        return static_cast<void*>(const_cast< controllerNgn*>(this));
    return QThread::qt_metacast(_clname);
}

int controllerNgn::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: signalMgs((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: signalsQX2Events((*reinterpret_cast< QX2Event*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void controllerNgn::signalMgs(QByteArray _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void controllerNgn::signalsQX2Events(QX2Event * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
