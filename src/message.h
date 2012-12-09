#ifndef MESSAGE_H
#define MESSAGE_H

#include <QByteArray>
#include <QString>
#include <QDataStream>

class Message
{
public:
    Message();
    Message(quint8 type, QString msg);

    enum MessageType {
        LOGON,
        LOGOFF,
        X_ONLINE,
        X_OFFLINE,
        CHAT_WITH_X,
        MESSAGE,
        ERROR
    };

    void setMessage(quint8 type, QString msg);

    quint8 getType() const;
    QString getMessage() const;

    QByteArray getBlock();

private:
    quint8 msgType;
    QString message;
};

#endif // MESSAGE_H
