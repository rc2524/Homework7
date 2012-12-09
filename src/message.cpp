#include "message.h"

Message::Message()
{
}

Message::Message(quint8 type, QString msg)
{
    msgType = type;
    message = msg;
}

void Message::setMessage(quint8 type, QString msg)
{
}

quint8 Message::getType() const
{
    return msgType;
}

QString Message::getMessage() const
{
    return message;
}

QByteArray Message::getBlock()
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);

    out.setVersion(QDataStream::Qt_4_0);
    out << (quint16)0;

    out << msgType;
    out << message;
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));

    return block;
}
