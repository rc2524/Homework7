#include "connection.h"
#include <QDataStream>
#include <QDebug>

Connection::Connection()
{
    QObject::connect(&socket, SIGNAL(readyRead()), this, SLOT(receiveData()));
}

void Connection::openConnection(QString &IP, int port)
{
    socket.abort();
    socket.setPeerVerifyMode(QSslSocket::QueryPeer);
    socket.connectToHostEncrypted(IP, port);
    if (!socket.waitForEncrypted(1000)) {
//         QMessageBox::critical(this, "ERROR", "ERROR: Could not connect to host");
         return;
    }

    blockSize = 0;
}

void Connection::waitForTransfer()
{
    socket.waitForBytesWritten(2000);
}

void Connection::receiveData()
{
     QDataStream in(&socket);
     in.setVersion(QDataStream::Qt_4_0);

     if (blockSize == 0) {
         if (socket.bytesAvailable() < (int)sizeof(quint16))
             return;
         in >> blockSize;
     }

     if (socket.bytesAvailable() < blockSize)
         return;

     quint8 type;
     in >> type;

     QString msg;
     in >> msg;

     emit messageReceived(Message(type, msg));

     blockSize = 0;
}

void Connection::sendMessage(Message msg)
{
    socket.write(msg.getBlock());
    qDebug() << "Wrote" << msg.getType() << msg.getMessage();
}
