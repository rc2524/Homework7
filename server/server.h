/****************************************************************************
  From Qt Examples
****************************************************************************/

#ifndef SERVER_H
#define SERVER_H

#include "SSLServer.h"
#include <QObject>
#include <QHash>
#include <QString>
#include <QSslSocket>
#include "serverwindow.h"
#include "clientthread.h"


class Server : public QObject
{
    Q_OBJECT

public:
    Server(QObject *parent = 0);
    ~Server();

signals:
    void sendMsg(QString msg);

private slots:
    void connectionRecieved();
    void startChat(QString user1, QString user2);
    void logoffUser(QString user);

private:
    ServerWindow w;
    SSLServer *sslServer;
    QHash<QString, ClientThread*> clients;
};

#endif
