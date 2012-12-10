/****************************************************************************
** Meta object code from reading C++ file 'connectwindow.h'
**
** Created: Sun Dec 9 20:54:46 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "connectwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'connectwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ConnectWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   15,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      43,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ConnectWindow[] = {
    "ConnectWindow\0\0c\0AttemptConnection(Client)\0"
    "on_connectButton_clicked()\0"
};

void ConnectWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ConnectWindow *_t = static_cast<ConnectWindow *>(_o);
        switch (_id) {
        case 0: _t->AttemptConnection((*reinterpret_cast< Client(*)>(_a[1]))); break;
        case 1: _t->on_connectButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ConnectWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ConnectWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ConnectWindow,
      qt_meta_data_ConnectWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ConnectWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ConnectWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ConnectWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ConnectWindow))
        return static_cast<void*>(const_cast< ConnectWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int ConnectWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void ConnectWindow::AttemptConnection(Client _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
