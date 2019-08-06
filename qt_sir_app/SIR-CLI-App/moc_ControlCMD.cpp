/****************************************************************************
** Meta object code from reading C++ file 'ControlCMD.h'
**
** Created: Fri May 4 17:05:06 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/control/ControlCMD.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ControlCMD.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ControlCMD[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      34,   22,   11,   11, 0x0a,
      59,   54,   11,   11, 0x2a,

       0        // eod
};

static const char qt_meta_stringdata_ControlCMD[] = {
    "ControlCMD\0\0exiting()\0_cmd,params\0"
    "listen(int,QString)\0_cmd\0listen(int)\0"
};

const QMetaObject ControlCMD::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_ControlCMD,
      qt_meta_data_ControlCMD, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ControlCMD::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ControlCMD::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ControlCMD::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ControlCMD))
        return static_cast<void*>(const_cast< ControlCMD*>(this));
    return QThread::qt_metacast(_clname);
}

int ControlCMD::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: exiting(); break;
        case 1: listen((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: listen((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void ControlCMD::exiting()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
