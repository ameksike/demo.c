/****************************************************************************
** Meta object code from reading C++ file 'lig.h'
**
** Created: Wed Feb 22 16:33:45 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/lig.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lig.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LIG[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
       5,    4,    4,    4, 0x05,

 // slots: signature, parameters, type, tag, flags
      37,   35,    4,    4, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_LIG[] = {
    "LIG\0\0signalsReciveData(QByteArray)\0e\0"
    "proccessEvent(QX2Event*)\0"
};

const QMetaObject LIG::staticMetaObject = {
    { &QCoreApplication::staticMetaObject, qt_meta_stringdata_LIG,
      qt_meta_data_LIG, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LIG::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LIG::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LIG::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LIG))
        return static_cast<void*>(const_cast< LIG*>(this));
    return QCoreApplication::qt_metacast(_clname);
}

int LIG::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QCoreApplication::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: signalsReciveData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: proccessEvent((*reinterpret_cast< QX2Event*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void LIG::signalsReciveData(QByteArray _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
