 #include "clientlistwindow.h"
#include "ui_clientlistwindow.h"

ClientListWindow::ClientListWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ClientListWindow)
{
    ui->setupUi(this);
}

void ClientListWindow::addClient(Client c) {
    //Create a new widget item based on client's name
    //and bind it to a struct that represents both
    //the client and list item so we can delete
    //it late
    QListWidgetItem *item = new QListWidgetItem();
    item->setText(c.name);
    ClientListWidget clw;
    clw.c = c;
    clw.item = item;
    clientList.push_back(clw);
    ui->listWidget->addItem(item);
}

void ClientListWindow::removeClient(Client c) {
    //Find the client in the list
    int matchingItemPos = -1;
    for (int i = 0; i < clientList.size(); ++i) {
        if (clientList[i].c.name == c.name) {
            //Get matching item position
            matchingItemPos = i;

            //Remove item from list
            clientList.removeAt(i);

            break;
        }
    }

    //Didn't find anything
    if (matchingItemPos == -1) {
        QMessageBox msgBox;
        msgBox.setText("Tried to remove a non existant item");
        msgBox.exec();
        exit(-1);
    }

    //Remove item from view
    ui->listWidget->takeItem(matchingItemPos);
}

void ClientListWindow::on_pushButton_clicked()
{
    QModelIndex pos = ui->listWidget->currentIndex();

    //Make sure an item is selected
    if (pos.row() < 0 || pos.row() > (clientList.size()-1)) {
        QMessageBox msgBox;
        msgBox.setText("Please select an item...");
        msgBox.exec();
        return;
    }

    emit connectToClient(clientList[pos.row()].c);
}
