/****************************************************************************
** Meta object code from reading C++ file 'chatwindow.h'
**
** Created: Sun Dec 9 20:54:46 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "chatwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chatwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ChatWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,
      24,   11,   11,   11, 0x05,
      40,   31,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      69,   11,   11,   11, 0x08,
      93,   11,   11,   11, 0x08,
     117,   11,   11,   11, 0x08,
     146,  141,   11,   11, 0x0a,
     166,  141,   11,   11, 0x0a,
     184,   31,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ChatWindow[] = {
    "ChatWindow\0\0closeChat()\0quit()\0name,msg\0"
    "sendMessage(QString,QString)\0"
    "on_exitButton_clicked()\0on_sendButton_clicked()\0"
    "on_quitButton_clicked()\0name\0"
    "userJoined(QString)\0userLeft(QString)\0"
    "userChat(QString,QString)\0"
};

void ChatWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ChatWindow *_t = static_cast<ChatWindow *>(_o);
        switch (_id) {
        case 0: _t->closeChat(); break;
        case 1: _t->quit(); break;
        case 2: _t->sendMessage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->on_exitButton_clicked(); break;
        case 4: _t->on_sendButton_clicked(); break;
        case 5: _t->on_quitButton_clicked(); break;
        case 6: _t->userJoined((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->userLeft((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->userChat((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ChatWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ChatWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ChatWindow,
      qt_meta_data_ChatWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ChatWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ChatWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ChatWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ChatWindow))
        return static_cast<void*>(const_cast< ChatWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int ChatWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void ChatWindow::closeChat()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void ChatWindow::quit()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void ChatWindow::sendMessage(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
