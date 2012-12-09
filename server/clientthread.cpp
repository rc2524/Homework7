#include "clientthread.h"
#include <QDataStream>

ClientThread::ClientThread(QObject *parent, QSslSocket *socket) :
    QThread(parent)
{
    connection = socket;
    if (!connection->waitForEncrypted(1000)){
        qDebug() << "Waited for 1 second for encryption handshake without success";
        return;
    }
    qDebug() << "Successfully waited for secure handshake...";
    connect(connection, SIGNAL(disconnected()),
            connection, SLOT(deleteLater()));
}

ClientThread::~ClientThread()
{
    connection->disconnectFromHost();
}

QString ClientThread::waitForName()
{
    // Wait for the connecting client to send its username
    QDataStream in(connection);
    in.setVersion(QDataStream::Qt_4_0);

    QString name;

    connection->waitForReadyRead(5000);

    quint16 blockSize = 0;
    while (connection->bytesAvailable() < (int)sizeof(quint16));

    in >> blockSize;

    while (connection->bytesAvailable() < blockSize);

    quint8 type;
    in >> type;
    in >> name;

    connect(connection, SIGNAL(readyRead()), this, SLOT(dataReceived()));

    username = name;

    return name;
}

void ClientThread::buddyStartedChat(QString buddy)
{
    chatBuddy = buddy;
    Message m(Message::CHAT_WITH_X, buddy);
    sendMessage(m);
}

void ClientThread::sendMessage(Message msg)
{
    connection->write(msg.getBlock());
}

void ClientThread::dataReceived()
{
    quint16 blockSize = 0;

    // Read message
    QDataStream in(connection);
    in.setVersion(QDataStream::Qt_4_0);

    if (blockSize == 0) {
        if (connection->bytesAvailable() < (int)sizeof(quint16))
            return;
        in >> blockSize;
    }

    if (connection->bytesAvailable() < blockSize)
        return;

    quint8 type;
    in >> type;

    QString msg;
    in >> msg;

    // Handle/respond to message
    if (type == Message::MESSAGE) {
        emit messageToBuddy(Message(type, msg));
    }
    else if (type == Message::CHAT_WITH_X) {
        chatBuddy = msg;
        emit chatWith(username, chatBuddy);
    }
    else if (type == Message::LOGOFF) {

    }
    else if (type == Message::ERROR) {

    }
}



