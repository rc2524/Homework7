#ifndef CONNECTION_H
#define CONNECTION_H

#include <QObject>
#include <QSslSocket>
#include <QString>
#include "../src/message.h"

class Connection : public QObject
{
    Q_OBJECT
public:
    Connection();

    void openConnection(QString& IP, int port);

    void waitForTransfer();

signals:
    void messageReceived(Message msg);

public slots:
    void sendMessage(Message msg);

private slots:
    void receiveData();

private:
    QSslSocket socket;

    quint16 blockSize;
};

#endif // CONNECTION_H
