/****************************************************************************
** Meta object code from reading C++ file 'cliente.h'
**
** Created: Fri Mar 13 21:36:43 2009
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../cliente.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cliente.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Cliente[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // signals: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x05,

 // slots: signature, parameters, type, tag, flags
      21,    8,    8,    8, 0x08,
      32,    8,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Cliente[] = {
    "Cliente\0\0SUserData()\0SLConect()\0"
    "SLSalir()\0"
};

const QMetaObject Cliente::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Cliente,
      qt_meta_data_Cliente, 0 }
};

const QMetaObject *Cliente::metaObject() const
{
    return &staticMetaObject;
}

void *Cliente::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Cliente))
        return static_cast<void*>(const_cast< Cliente*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Cliente::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: SUserData(); break;
        case 1: SLConect(); break;
        case 2: SLSalir(); break;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void Cliente::SUserData()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
