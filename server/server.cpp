/****************************************************************************
  From the Qt examples
  Modified to do a secure SSL connection
****************************************************************************/

#include <QtGui>
#include <QtNetwork>
#include <stdlib.h>
#include "server.h"
#include "../src/message.h"
#include <iostream>
#include <QDebug>
using namespace std;

Server::Server(QObject *parent) : QObject(parent)
{
    sslServer = new SSLServer(this);
    if (!sslServer->listen()) {
        QMessageBox::critical(&w, tr("Chat Server"),
                              tr("Unable to start the server: %1.")
                              .arg(sslServer->errorString()));
        w.close();
        return;
    }
    QString ipAddress;
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    // use the first non-localhost IPv4 address
    for (int i = 0; i < ipAddressesList.size(); ++i) {
        if (ipAddressesList.at(i) != QHostAddress::LocalHost
            && ipAddressesList.at(i).toIPv4Address())
        {
            ipAddress = ipAddressesList.at(i).toString();
            break;
        }
    }
    // if we did not find one, use IPv4 localhost
    if (ipAddress.isEmpty())
        ipAddress = QHostAddress(QHostAddress::LocalHost).toString();

    w.setIP(ipAddress);
    w.setPort(QString("%1").arg(sslServer->serverPort()));

    connect(sslServer, SIGNAL(newConnection()), this, SLOT(connectionRecieved()));

    w.show();
}

Server::~Server()
{
    foreach (ClientThread* client, clients)
    {
        delete client;
    }
}

void Server::connectionRecieved()
{
    ClientThread* clientThrd = new ClientThread(this,sslServer->nextPendingConnection());
    QObject::connect(clientThrd, SIGNAL(chatWith(QString,QString)),
                     this, SLOT(startChat(QString,QString)));
    QObject::connect(clientThrd, SIGNAL(loggingOff(QString)),
                     this, SLOT(logoffUser(QString)));

    // add get name and add to hash table.
    QString name = clientThrd->waitForName();

    if (clients.contains(name)) {
        Message m((quint8)Message::ERROR, QString("Username already in use!"));
        clientThrd->sendMessage(m);
        return;
    }

    clientThrd->start();

    for (QHash<QString, ClientThread*>::Iterator it = clients.begin();
         it != clients.end(); ++it)
    {
        Message m;
        m.setMessage((quint8)Message::X_ONLINE, it.key());
        clientThrd->sendMessage(m);

        m.setMessage((quint8)Message::X_ONLINE, name);
        it.value()->sendMessage(m);

        qDebug() << name << "and" << it.key() << "know each other are online.";
    }

    clients[name] = clientThrd;

    w.dispMsg(QString("%1 connected").arg(name));
}

void Server::startChat(QString user1, QString user2)
{
    clients[user2]->buddyStartedChat(user1);
    QObject::disconnect(clients[user1], SIGNAL(chatWith(QString,QString)), this, SLOT(startChat(QString,QString)));
    QObject::disconnect(clients[user2], SIGNAL(chatWith(QString,QString)), this, SLOT(startChat(QString,QString)));
    QObject::connect(clients[user1], SIGNAL(messageToBuddy(Message)), clients[user2], SLOT(sendMessage(Message)));
    QObject::connect(clients[user2], SIGNAL(messageToBuddy(Message)), clients[user1], SLOT(sendMessage(Message)));

    w.dispMsg(QString("%1 started a chat with %2.").arg(user1).arg(user2));
}

void Server::logoffUser(QString user)
{
    delete clients[user];
    clients.remove(user);

    qDebug() << "Disconnecting" << user;

    Message m((quint8)Message::X_OFFLINE, user);

    foreach (ClientThread* client, clients) {
        client->sendMessage(m);
    }

    w.dispMsg(QString("%1 left the server.").arg(user));
}

