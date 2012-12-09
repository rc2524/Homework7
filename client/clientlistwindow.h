#ifndef CLIENTLISTWINDOW_H
#define CLIENTLISTWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QList>
#include <QMessageBox>
#include "Client.h"

struct ClientListWidget {
    Client c;

    //Widget that refers to a client
    QListWidgetItem *item;
};

namespace Ui {
class ClientListWindow;
}

class ClientListWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit ClientListWindow(QWidget *parent = 0);

private:
    Ui::ClientListWindow *ui;

    //Keep track of all clients and associated list items
    QList<ClientListWidget> clientList;

//public slots:
public slots:
    //Add a client to the list
    void addClient(Client c);

    //Remove a client from the list
    void removeClient(Client c);

signals:
    //User pressed connect button
    void connectToClient(Client c);
private slots:
    //Connect button
    void on_pushButton_clicked();
};

#endif // CLIENTLISTWINDOW_H
