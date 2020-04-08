/****************************************************************************
** Meta object code from reading C++ file 'ChatClient.h'
**
** Created: Sat Mar 7 16:36:17 2009
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ChatClient.h"
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
       2,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      25,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ChatClient[] = {
    "ChatClient\0\0SLConectar()\0SLEnviar()\0"
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
    return QObject::qt_metacast(_clname);
}

int ChatClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: SLConectar(); break;
        case 1: SLEnviar(); break;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
