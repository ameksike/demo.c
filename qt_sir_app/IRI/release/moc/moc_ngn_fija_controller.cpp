/****************************************************************************
** Meta object code from reading C++ file 'ngn_fija_controller.h'
**
** Created: Wed Feb 22 16:33:42 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/ngn_fija_controller.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ngn_fija_controller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_NGN_FIJA_Controller[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      21,   20,   20,   20, 0x05,
      48,   20,   20,   20, 0x05,
      76,   20,   20,   20, 0x05,

 // slots: signature, parameters, type, tag, flags
     115,   20,   20,   20, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_NGN_FIJA_Controller[] = {
    "NGN_FIJA_Controller\0\0signalsQX2Event(QX2Event*)\0"
    "signalsQX2Events(QX2Event*)\0"
    "signalsQX2EventByteAarray(QByteArray*)\0"
    "slotProcesarDatos(QByteArray)\0"
};

const QMetaObject NGN_FIJA_Controller::staticMetaObject = {
    { &Controller::staticMetaObject, qt_meta_stringdata_NGN_FIJA_Controller,
      qt_meta_data_NGN_FIJA_Controller, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &NGN_FIJA_Controller::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *NGN_FIJA_Controller::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *NGN_FIJA_Controller::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NGN_FIJA_Controller))
        return static_cast<void*>(const_cast< NGN_FIJA_Controller*>(this));
    return Controller::qt_metacast(_clname);
}

int NGN_FIJA_Controller::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Controller::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: signalsQX2Event((*reinterpret_cast< QX2Event*(*)>(_a[1]))); break;
        case 1: signalsQX2Events((*reinterpret_cast< QX2Event*(*)>(_a[1]))); break;
        case 2: signalsQX2EventByteAarray((*reinterpret_cast< QByteArray*(*)>(_a[1]))); break;
        case 3: slotProcesarDatos((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void NGN_FIJA_Controller::signalsQX2Event(QX2Event * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void NGN_FIJA_Controller::signalsQX2Events(QX2Event * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void NGN_FIJA_Controller::signalsQX2EventByteAarray(QByteArray * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
