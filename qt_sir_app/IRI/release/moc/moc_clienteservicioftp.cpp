/****************************************************************************
** Meta object code from reading C++ file 'clienteservicioftp.h'
**
** Created: Wed Feb 22 16:33:44 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/clienteservicioftp.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'clienteservicioftp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ClienteFTP[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,
      32,   11,   11,   11, 0x05,
      48,   11,   11,   11, 0x05,
      61,   11,   11,   11, 0x05,
      74,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      93,   11,   11,   11, 0x09,
     128,  122,   11,   11, 0x09,
     167,  160,   11,   11, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_ClienteFTP[] = {
    "ClienteFTP\0\0connectionTimeout()\0"
    "connected(bool)\0logged(bool)\0closed(bool)\0"
    "connectionBroken()\0inicioEjecuacionComando(int)\0"
    "error\0finEjecucionUltimoComando(bool)\0"
    "estado\0cambioEstado(int)\0"
};

const QMetaObject ClienteFTP::staticMetaObject = {
    { &QFtp::staticMetaObject, qt_meta_stringdata_ClienteFTP,
      qt_meta_data_ClienteFTP, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ClienteFTP::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ClienteFTP::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ClienteFTP::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ClienteFTP))
        return static_cast<void*>(const_cast< ClienteFTP*>(this));
    return QFtp::qt_metacast(_clname);
}

int ClienteFTP::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFtp::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: connectionTimeout(); break;
        case 1: connected((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: logged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: closed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: connectionBroken(); break;
        case 5: inicioEjecuacionComando((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: finEjecucionUltimoComando((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: cambioEstado((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void ClienteFTP::connectionTimeout()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void ClienteFTP::connected(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ClienteFTP::logged(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ClienteFTP::closed(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ClienteFTP::connectionBroken()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}
static const uint qt_meta_data_ClienteServicioFTP[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      22,   20,   19,   19, 0x05,
      56,   20,   19,   19, 0x05,
      90,   87,   19,   19, 0x05,

 // slots: signature, parameters, type, tag, flags
     129,   20,   19,   19, 0x09,
     159,   19,   19,   19, 0x09,
     191,   19,   19,   19, 0x09,
     219,   19,   19,   19, 0x09,
     249,  244,   19,   19, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ClienteServicioFTP[] = {
    "ClienteServicioFTP\0\0,\0"
    "cambioEstadoServicio(int,quint16)\0"
    "coneccionCerrada(quint16,bool)\0,,\0"
    "finTransferencia(quint16,quint64,bool)\0"
    "finEjecucionComando(int,bool)\0"
    "finEjecucionUltimoComando(bool)\0"
    "coneccionFallidaPorTiempo()\0"
    "desconeccionInesperada()\0ftpE\0"
    "procesarEventos(QIRIEvent*)\0"
};

const QMetaObject ClienteServicioFTP::staticMetaObject = {
    { &ClienteFTP::staticMetaObject, qt_meta_stringdata_ClienteServicioFTP,
      qt_meta_data_ClienteServicioFTP, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ClienteServicioFTP::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ClienteServicioFTP::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ClienteServicioFTP::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ClienteServicioFTP))
        return static_cast<void*>(const_cast< ClienteServicioFTP*>(this));
    return ClienteFTP::qt_metacast(_clname);
}

int ClienteServicioFTP::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ClienteFTP::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: cambioEstadoServicio((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2]))); break;
        case 1: coneccionCerrada((*reinterpret_cast< quint16(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 2: finTransferencia((*reinterpret_cast< quint16(*)>(_a[1])),(*reinterpret_cast< quint64(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 3: finEjecucionComando((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 4: finEjecucionUltimoComando((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: coneccionFallidaPorTiempo(); break;
        case 6: desconeccionInesperada(); break;
        case 7: procesarEventos((*reinterpret_cast< QIRIEvent*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void ClienteServicioFTP::cambioEstadoServicio(int _t1, quint16 _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ClienteServicioFTP::coneccionCerrada(quint16 _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ClienteServicioFTP::finTransferencia(quint16 _t1, quint64 _t2, bool _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
