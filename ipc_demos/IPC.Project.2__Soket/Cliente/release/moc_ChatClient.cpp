/****************************************************************************
** Meta object code from reading C++ file 'ChatClient.h'
**
** Created: Fri Mar 13 21:36:44 2009
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ChatClient.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ChatClient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ChatClient[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,
      34,   11,   11,   11, 0x05,
      53,   11,   11,   11, 0x05,
      71,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      94,   11,   11,   11, 0x0a,
     107,   11,   11,   11, 0x0a,
     118,   11,   11,   11, 0x0a,
     134,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ChatClient[] = {
    "ChatClient\0\0SDesconexion(QString)\0"
    "SConexion(QString)\0SEscaner(QString)\0"
    "SConversacion(QString)\0SLConectar()\0"
    "SLEnviar()\0SLDesconectar()\0Start()\0"
};

const QMetaObject ChatClient::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ChatClient,
      qt_meta_data_ChatClient, 0 }
};

const QMetaObject *ChatClient::metaObject() const
{
    return &staticMetaObject;
}

void *ChatClient::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ChatClient))
        return static_cast<void*>(const_cast< ChatClient*>(this));
    if (!strcmp(_clname, "SockView"))
        return static_cast< SockView*>(const_cast< ChatClient*>(this));
    return QObject::qt_metacast(_clname);
}

int ChatClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: SDesconexion((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: SConexion((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: SEscaner((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: SConversacion((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: SLConectar(); break;
        case 5: SLEnviar(); break;
        case 6: SLDesconectar(); break;
        case 7: Start(); break;
        }
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void ChatClient::SDesconexion(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ChatClient::SConexion(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ChatClient::SEscaner(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ChatClient::SConversacion(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
