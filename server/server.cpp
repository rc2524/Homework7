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
    for (QHash<QString, ClientThread*>::Iterator it = clients.begin();
         it != clients.end(); ++it)
    {
        delete it.value();
    }
}

void Server::connectionRecieved()
{
    ClientThread* clientThrd = new ClientThread(this,sslServer->nextPendingConnection());
    connect(this, SIGNAL(sendMsg(QString)), clientThrd, SLOT(sendMessage(QString)));

    // add get name and add to hash table.
    QString name = clientThrd->waitForName();

    QList<QString> onlineClients = clients.keys();
    for (QList<QString>::Iterator it = onlineClients.begin();
         it != onlineClients.end(); ++it)
    {
        Message m((quint8)Message::X_ONLINE, *it);
        clientThrd->sendMessage(m);
    }

    clients[name] = clientThrd;

    w.dispMsg(QString("%1 connected").arg(name));
}

