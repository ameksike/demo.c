/****************************************************************************
** Meta object code from reading C++ file 'chat.h'
**
** Created: Fri Mar 13 21:02:21 2009
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../chat.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chat.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Chat[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // signals: signature, parameters, type, tag, flags
       6,    5,    5,    5, 0x05,
      22,    5,    5,    5, 0x05,
      36,    5,    5,    5, 0x05,

 // slots: signature, parameters, type, tag, flags
      53,    5,    5,    5, 0x0a,
      62,    5,    5,    5, 0x0a,
      80,    5,    5,    5, 0x0a,
      98,    5,    5,    5, 0x0a,
     116,    5,    5,    5, 0x0a,
     131,    5,    5,    5, 0x0a,
     149,    5,    5,    5, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Chat[] = {
    "Chat\0\0Send_UserData()\0SConectarse()\0"
    "SDesconectarse()\0Enviar()\0Set_Test(QString)\0"
    "Set_User(QString)\0Del_User(QString)\0"
    "SLConectarse()\0SLDesconectarse()\0"
    "SLSalir()\0"
};

const QMetaObject Chat::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Chat,
      qt_meta_data_Chat, 0 }
};

const QMetaObject *Chat::metaObject() const
{
    return &staticMetaObject;
}

void *Chat::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Chat))
        return static_cast<void*>(const_cast< Chat*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Chat::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: Send_UserData(); break;
        case 1: SConectarse(); break;
        case 2: SDesconectarse(); break;
        case 3: Enviar(); break;
        case 4: Set_Test((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: Set_User((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: Del_User((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: SLConectarse(); break;
        case 8: SLDesconectarse(); break;
        case 9: SLSalir(); break;
        }
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void Chat::Send_UserData()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Chat::SConectarse()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void Chat::SDesconectarse()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
