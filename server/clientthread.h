#ifndef CLIENTTHREAD_H
#define CLIENTTHREAD_H

#include <QThread>
#include <QSslSocket>
#include <QString>
#include "../src/message.h"

class ClientThread : public QThread
{
    Q_OBJECT
public:
    explicit ClientThread(QObject *parent = 0, QSslSocket* socket = 0);
    ~ClientThread();
    
    QString waitForName();

signals:
    
public slots:
    void sendMessage(Message msg);
    void dataReceived();

private:
    QSslSocket* connection;

    quint16 blockSize;
};

#endif // CLIENTTHREAD_H
