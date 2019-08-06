/****************************************************************************
** Meta object code from reading C++ file 'deliveryfunction.h'
**
** Created: Wed Feb 22 16:33:47 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/deliveryfunction.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'deliveryfunction.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DeliveryFunctionPrivate[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      25,   24,   24,   24, 0x05,

 // slots: signature, parameters, type, tag, flags
      58,   24,   24,   24, 0x08,
      95,   85,   24,   24, 0x08,
     180,  140,   24,   24, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DeliveryFunctionPrivate[] = {
    "DeliveryFunctionPrivate\0\0"
    "signalsSendQIRIEvent(QIRIEvent*)\0"
    "slotNuevoEvento(QX2Event*)\0estado,id\0"
    "slotCambioEstadoCentroMonitoreo(int,quint16)\0"
    "idServicio,numTransf,errorTransferencia\0"
    "slotFinTransferencia(quint16,quint64,bool)\0"
};

const QMetaObject DeliveryFunctionPrivate::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_DeliveryFunctionPrivate,
      qt_meta_data_DeliveryFunctionPrivate, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DeliveryFunctionPrivate::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DeliveryFunctionPrivate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DeliveryFunctionPrivate::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DeliveryFunctionPrivate))
        return static_cast<void*>(const_cast< DeliveryFunctionPrivate*>(this));
    return QObject::qt_metacast(_clname);
}

int DeliveryFunctionPrivate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: signalsSendQIRIEvent((*reinterpret_cast< QIRIEvent*(*)>(_a[1]))); break;
        case 1: slotNuevoEvento((*reinterpret_cast< QX2Event*(*)>(_a[1]))); break;
        case 2: slotCambioEstadoCentroMonitoreo((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2]))); break;
        case 3: slotFinTransferencia((*reinterpret_cast< quint16(*)>(_a[1])),(*reinterpret_cast< quint64(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void DeliveryFunctionPrivate::signalsSendQIRIEvent(QIRIEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
static const uint qt_meta_data_DeliveryFunction[] = {

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
      18,   17,   17,   17, 0x05,
      47,   17,   17,   17, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_DeliveryFunction[] = {
    "DeliveryFunction\0\0signalNuevoEvento(QX2Event*)\0"
    "signalDeliveryFunctionReady()\0"
};

const QMetaObject DeliveryFunction::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_DeliveryFunction,
      qt_meta_data_DeliveryFunction, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DeliveryFunction::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DeliveryFunction::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DeliveryFunction::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DeliveryFunction))
        return static_cast<void*>(const_cast< DeliveryFunction*>(this));
    return QThread::qt_metacast(_clname);
}

int DeliveryFunction::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: signalNuevoEvento((*reinterpret_cast< QX2Event*(*)>(_a[1]))); break;
        case 1: signalDeliveryFunctionReady(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void DeliveryFunction::signalNuevoEvento(QX2Event * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DeliveryFunction::signalDeliveryFunctionReady()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
