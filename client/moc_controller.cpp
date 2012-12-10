/****************************************************************************
** Meta object code from reading C++ file 'controller.h'
**
** Created: Sun Dec 9 20:54:47 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "controller.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'controller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Controller[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   12,   11,   11, 0x05,
      40,   12,   11,   11, 0x05,
      70,   65,   11,   11, 0x05,
      90,   65,   11,   11, 0x05,
     117,  108,   11,   11, 0x05,
     143,  108,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
     180,   12,   11,   11, 0x0a,
     219,   12,   11,   11, 0x0a,
     255,   11,   11,   11, 0x0a,
     274,   11,   11,   11, 0x0a,
     281,  108,   11,   11, 0x0a,
     316,  312,   11,   11, 0x0a,
     336,   12,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Controller[] = {
    "Controller\0\0c\0newClientOnServer(Client)\0"
    "clientLeftServer(Client)\0name\0"
    "userJoined(QString)\0userLeft(QString)\0"
    "name,msg\0userChat(QString,QString)\0"
    "displayBuddyMessage(QString,QString)\0"
    "ConnectWindowAttemptConnection(Client)\0"
    "ClientListAttemptConnection(Client)\0"
    "BackToClientList()\0quit()\0"
    "OnUserMessage(QString,QString)\0msg\0"
    "receiveMsg(Message)\0buddyDisconnect(Client)\0"
};

void Controller::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Controller *_t = static_cast<Controller *>(_o);
        switch (_id) {
        case 0: _t->newClientOnServer((*reinterpret_cast< Client(*)>(_a[1]))); break;
        case 1: _t->clientLeftServer((*reinterpret_cast< Client(*)>(_a[1]))); break;
        case 2: _t->userJoined((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->userLeft((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->userChat((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 5: _t->displayBuddyMessage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 6: _t->ConnectWindowAttemptConnection((*reinterpret_cast< Client(*)>(_a[1]))); break;
        case 7: _t->ClientListAttemptConnection((*reinterpret_cast< Client(*)>(_a[1]))); break;
        case 8: _t->BackToClientList(); break;
        case 9: _t->quit(); break;
        case 10: _t->OnUserMessage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 11: _t->receiveMsg((*reinterpret_cast< Message(*)>(_a[1]))); break;
        case 12: _t->buddyDisconnect((*reinterpret_cast< Client(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Controller::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Controller::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Controller,
      qt_meta_data_Controller, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Controller::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Controller::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Controller::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Controller))
        return static_cast<void*>(const_cast< Controller*>(this));
    return QObject::qt_metacast(_clname);
}

int Controller::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void Controller::newClientOnServer(Client _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Controller::clientLeftServer(Client _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Controller::userJoined(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Controller::userLeft(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Controller::userChat(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Controller::displayBuddyMessage(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
