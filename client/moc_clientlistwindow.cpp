/****************************************************************************
** Meta object code from reading C++ file 'clientlistwindow.h'
**
** Created: Sun Dec 9 20:54:45 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "clientlistwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'clientlistwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ClientListWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      20,   18,   17,   17, 0x05,
      44,   17,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
      51,   18,   17,   17, 0x0a,
      69,   18,   17,   17, 0x0a,
      90,   17,   17,   17, 0x08,
     114,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ClientListWindow[] = {
    "ClientListWindow\0\0c\0connectToClient(Client)\0"
    "quit()\0addClient(Client)\0removeClient(Client)\0"
    "on_pushButton_clicked()\0on_quitButton_clicked()\0"
};

void ClientListWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ClientListWindow *_t = static_cast<ClientListWindow *>(_o);
        switch (_id) {
        case 0: _t->connectToClient((*reinterpret_cast< Client(*)>(_a[1]))); break;
        case 1: _t->quit(); break;
        case 2: _t->addClient((*reinterpret_cast< Client(*)>(_a[1]))); break;
        case 3: _t->removeClient((*reinterpret_cast< Client(*)>(_a[1]))); break;
        case 4: _t->on_pushButton_clicked(); break;
        case 5: _t->on_quitButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ClientListWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ClientListWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ClientListWindow,
      qt_meta_data_ClientListWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ClientListWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ClientListWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ClientListWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ClientListWindow))
        return static_cast<void*>(const_cast< ClientListWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int ClientListWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void ClientListWindow::connectToClient(Client _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ClientListWindow::quit()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
