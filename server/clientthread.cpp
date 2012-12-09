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

    return name;
}

void ClientThread::sendMessage(Message msg)
{
    connection->write(msg.getBlock());
}

void ClientThread::dataReceived()
{
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

    QString nextFortune;
    in >> nextFortune;
}



