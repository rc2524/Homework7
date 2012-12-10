#include "controller.h"
#include "../src/message.h"

Controller::Controller(QObject *parent) :
    QObject(parent)
{
    //Show connect window at start
    connectWindow = new ConnectWindow;
    connectWindow->show();

    //Connect window
    QObject::connect(connectWindow, SIGNAL(AttemptConnection(Client)), this, SLOT(ConnectWindowAttemptConnection(Client)));

    QObject::connect(&connection, SIGNAL(messageReceived(Message)), this, SLOT(receiveMsg(Message)));

    //Client list window
}

void Controller::ConnectWindowAttemptConnection(Client c) {
    //Handle connection
    connection.openConnection(c.ip, c.port);

    Message m(Message::LOGON, c.name);
    connection.sendMessage(m);

    connectWindow->close();

    //Keep my name around
    myInfo = c;

    //Start client list window
    clientListWindow = new ClientListWindow;
    clientListWindow->show();

    //Connect routes
    QObject::connect(clientListWindow, SIGNAL(quit()), this, SLOT(quit()));
    QObject::connect(this, SIGNAL(newClientOnServer(Client)), clientListWindow, SLOT(addClient(Client)));
    QObject::connect(this, SIGNAL(clientLeftServer(Client)), clientListWindow, SLOT(removeClient(Client)));
    QObject::connect(clientListWindow, SIGNAL(connectToClient(Client)), this, SLOT(ClientListAttemptConnection(Client))); //User presses conenct on client list

}

void Controller::ClientListAttemptConnection(Client c) {
    //Handle connection
    Message m(Message::CHAT_WITH_X, c.name);
    connection.sendMessage(m);

    buddy = c;
    //if (error) {
    //    QMessageBox msgBox;
    //    msgBox.setText("Some Error");
    //    msgBox.show();
    //

    clientListWindow->close();
    delete clientListWindow;

    //Start client list window
    chatWindow = new ChatWindow;
    chatWindow->setMyName(myInfo.name);
    chatWindow->show();

    //Connect routes
    QObject::connect(chatWindow, SIGNAL(closeChat()), this, SLOT(BackToClientList()));
    QObject::connect(chatWindow, SIGNAL(quit()), this, SLOT(quit()));
    QObject::connect(this, SIGNAL(displayBuddyMessage(QString,QString)), chatWindow, SLOT(userChat(QString,QString)));
    QObject::connect(chatWindow, SIGNAL(sendMessage(QString,QString)), this, SLOT(OnUserMessage(QString,QString)));
    QObject::connect(this, SIGNAL(clientLeftServer(Client)), this, SLOT(buddyDisconnect(Client)));
}

void Controller::BackToClientList()
{
    quit();

    QObject::disconnect(this, SIGNAL(clientLeftServer(Client)), this, SLOT(buddyDisconnect(Client)));

    connection.waitForTransfer();

    //Act like we just started again
    connectWindow = new ConnectWindow;  //Next line expects this to exist
    connectWindow->show();
    chatWindow->close();
    delete chatWindow;
    ConnectWindowAttemptConnection(myInfo);
}

void Controller::quit()
{
    Message m((quint8)Message::LOGOFF, myInfo.name);
    connection.sendMessage(m);
}


void Controller::OnUserMessage(QString name, QString msg) {
    Message m((quint8)Message::MESSAGE, msg);
    connection.sendMessage(m);
}

void Controller::receiveMsg(Message msg)
{
    if (msg.getType() == Message::MESSAGE) {
        emit displayBuddyMessage(buddy.name, msg.getMessage());
    }
    else if (msg.getType() == Message::X_ONLINE) {
        Client c;
        c.name = msg.getMessage();
        emit newClientOnServer(c);
    }
    else if (msg.getType() == Message::X_OFFLINE) {
        Client c;
        c.name = msg.getMessage();
        emit clientLeftServer(c);
    }
    else if (msg.getType() == Message::CHAT_WITH_X) {
        Client c;
        c.name = msg.getMessage();
        ClientListAttemptConnection(c);
    }
}

void Controller::buddyDisconnect(Client c)
{
    if (c.name == buddy.name) {
        BackToClientList();
    }
}
