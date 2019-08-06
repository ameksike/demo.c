/****************************************************************************
** Meta object code from reading C++ file 'tcpserver.h'
**
** Created: Wed Feb 22 16:33:41 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/tcpserver.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcpserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TCPServer[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,
      25,   10,   10,   10, 0x05,
      40,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      69,   10,   10,   10, 0x0a,
      87,   10,   10,   10, 0x0a,
     104,   10,   10,   10, 0x0a,
     126,   10,   10,   10, 0x0a,
     137,   10,   10,   10, 0x0a,
     151,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_TCPServer[] = {
    "TCPServer\0\0isConnected()\0isDisconnect()\0"
    "signalsDatosXptu(QByteArray)\0"
    "clientConnected()\0enviados(qint64)\0"
    "clienteDesconectado()\0readData()\0"
    "TimeOutXptu()\0slotDatosProcesadosController()\0"
};

const QMetaObject TCPServer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TCPServer,
      qt_meta_data_TCPServer, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TCPServer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TCPServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TCPServer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TCPServer))
        return static_cast<void*>(const_cast< TCPServer*>(this));
    return QObject::qt_metacast(_clname);
}

int TCPServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: isConnected(); break;
        case 1: isDisconnect(); break;
        case 2: signalsDatosXptu((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 3: clientConnected(); break;
        case 4: enviados((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 5: clienteDesconectado(); break;
        case 6: readData(); break;
        case 7: TimeOutXptu(); break;
        case 8: slotDatosProcesadosController(); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void TCPServer::isConnected()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void TCPServer::isDisconnect()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void TCPServer::signalsDatosXptu(QByteArray _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
