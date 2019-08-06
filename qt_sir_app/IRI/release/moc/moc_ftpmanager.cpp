/****************************************************************************
** Meta object code from reading C++ file 'ftpmanager.h'
**
** Created: Wed Feb 22 16:33:48 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/ftpmanager.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ftpmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QMonFtp[] = {

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
       9,    8,    8,    8, 0x05,

 // slots: signature, parameters, type, tag, flags
      41,   39,    8,    8, 0x0a,
      78,    8,    8,    8, 0x0a,
     114,  108,    8,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QMonFtp[] = {
    "QMonFtp\0\0signalServicioActivo(quint16)\0"
    "e\0slotNuevoServicioMonitorear(QEvent*)\0"
    "slotFallaConeccionPorTiempo()\0error\0"
    "finMonitorearServicio(bool)\0"
};

const QMetaObject QMonFtp::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QMonFtp,
      qt_meta_data_QMonFtp, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QMonFtp::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QMonFtp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QMonFtp::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QMonFtp))
        return static_cast<void*>(const_cast< QMonFtp*>(this));
    return QObject::qt_metacast(_clname);
}

int QMonFtp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: signalServicioActivo((*reinterpret_cast< quint16(*)>(_a[1]))); break;
        case 1: slotNuevoServicioMonitorear((*reinterpret_cast< QEvent*(*)>(_a[1]))); break;
        case 2: slotFallaConeccionPorTiempo(); break;
        case 3: finMonitorearServicio((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void QMonFtp::signalServicioActivo(quint16 _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
static const uint qt_meta_data_QMonServicio[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   14,   13,   13, 0x05,
      50,   13,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      95,   84,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QMonServicio[] = {
    "QMonServicio\0\0,\0signalServicioActivo(int,quint16)\0"
    "signalMonitorearServicio(QEvent*)\0"
    "idServicio\0slotActivarServicio(quint16)\0"
};

const QMetaObject QMonServicio::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_QMonServicio,
      qt_meta_data_QMonServicio, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QMonServicio::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QMonServicio::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QMonServicio::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QMonServicio))
        return static_cast<void*>(const_cast< QMonServicio*>(this));
    return QThread::qt_metacast(_clname);
}

int QMonServicio::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: signalServicioActivo((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2]))); break;
        case 1: signalMonitorearServicio((*reinterpret_cast< QEvent*(*)>(_a[1]))); break;
        case 2: slotActivarServicio((*reinterpret_cast< quint16(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void QMonServicio::signalServicioActivo(int _t1, quint16 _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QMonServicio::signalMonitorearServicio(QEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
static const uint qt_meta_data_FTPManager[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,
      39,   11,   11,   11, 0x05,
      66,   11,   11,   11, 0x05,
      91,   89,   11,   11, 0x05,
     128,  125,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
     175,  173,   11,   11, 0x0a,
     222,  201,   11,   11, 0x08,
     268,  251,   11,   11, 0x08,
     304,  173,   11,   11, 0x0a,
     325,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_FTPManager[] = {
    "FTPManager\0\0signalNuevoEvento(QEvent*)\0"
    "signalNuevoIRI(QIRIEvent*)\0"
    "cerrarPorInactividad()\0,\0"
    "cambioEstadoServicio(int,quint16)\0,,\0"
    "signalFinTransferencia(quint16,quint64,bool)\0"
    "e\0slotsNuevoIRI(QIRIEvent*)\0"
    "estadoFtp,idServicio\0cambioEstadoFtp(int,quint16)\0"
    "idServicio,error\0slotCerrarFTPInactivo(quint16,bool)\0"
    "customEvent(QEvent*)\0timerEvent(QTimerEvent*)\0"
};

const QMetaObject FTPManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_FTPManager,
      qt_meta_data_FTPManager, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FTPManager::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FTPManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FTPManager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FTPManager))
        return static_cast<void*>(const_cast< FTPManager*>(this));
    return QObject::qt_metacast(_clname);
}

int FTPManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: signalNuevoEvento((*reinterpret_cast< QEvent*(*)>(_a[1]))); break;
        case 1: signalNuevoIRI((*reinterpret_cast< QIRIEvent*(*)>(_a[1]))); break;
        case 2: cerrarPorInactividad(); break;
        case 3: cambioEstadoServicio((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2]))); break;
        case 4: signalFinTransferencia((*reinterpret_cast< quint16(*)>(_a[1])),(*reinterpret_cast< quint64(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 5: slotsNuevoIRI((*reinterpret_cast< QIRIEvent*(*)>(_a[1]))); break;
        case 6: cambioEstadoFtp((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2]))); break;
        case 7: slotCerrarFTPInactivo((*reinterpret_cast< quint16(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 8: customEvent((*reinterpret_cast< QEvent*(*)>(_a[1]))); break;
        case 9: timerEvent((*reinterpret_cast< QTimerEvent*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void FTPManager::signalNuevoEvento(QEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FTPManager::signalNuevoIRI(QIRIEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void FTPManager::cerrarPorInactividad()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void FTPManager::cambioEstadoServicio(int _t1, quint16 _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void FTPManager::signalFinTransferencia(quint16 _t1, quint64 _t2, bool _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
