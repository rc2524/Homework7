#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "connectwindow.h"
#include "clientlistwindow.h"
#include "chatwindow.h"
#include "Client.h"
#include "connection.h"

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = 0);
    
signals:
    void displayBuddyMessage(QString name, QString msg);
    
public slots:
    //Connect window -> Client List
    void ConnectWindowAttemptConnection(Client c); //Pressed connected

    //Client list -> Chat Window
    void ClientListAttemptConnection(Client c); //Pressed connect

    //Chat Window -> Client list
    void BackToClientList();

    //Asynchronous callbacks
    void OnUserMessage(QString name, QString msg); //User sent a message in the chat window

    // Process message from server
    void receiveMsg(Message msg);

private:
    ConnectWindow *connectWindow;
    ClientListWindow *clientListWindow;
    ChatWindow *chatWindow;

    Client myInfo;
    Client buddy;

    Connection connection;

signals:
    //Client window (****NOT CHAT) meant to be called async
    void newClientOnServer(Client c); //Transmit when user joins
    void clientLeftServer(Client c);  //Transmit when user leaves

    //Chat window related
    void userJoined(QString name); //User X joined
    void userLeft(QString name);  //User X left
    void userChat(QString name, QString msg); //name> msg

};

#endif // CONTROLLER_H
