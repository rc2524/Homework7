/****************************************************************************
** Meta object code from reading C++ file 'clientthread.h'
**
** Created: Sun Dec 9 15:37:13 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "clientthread.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'clientthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ClientThread[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      25,   14,   13,   13, 0x05,
      55,   51,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      79,   51,   13,   13, 0x0a,
     100,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ClientThread[] = {
    "ClientThread\0\0name,buddy\0"
    "chatWith(QString,QString)\0msg\0"
    "messageToBuddy(Message)\0sendMessage(Message)\0"
    "dataReceived()\0"
};

void ClientThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ClientThread *_t = static_cast<ClientThread *>(_o);
        switch (_id) {
        case 0: _t->chatWith((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->messageToBuddy((*reinterpret_cast< Message(*)>(_a[1]))); break;
        case 2: _t->sendMessage((*reinterpret_cast< Message(*)>(_a[1]))); break;
        case 3: _t->dataReceived(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ClientThread::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ClientThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_ClientThread,
      qt_meta_data_ClientThread, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ClientThread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ClientThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ClientThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ClientThread))
        return static_cast<void*>(const_cast< ClientThread*>(this));
    return QThread::qt_metacast(_clname);
}

int ClientThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void ClientThread::chatWith(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ClientThread::messageToBuddy(Message _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
