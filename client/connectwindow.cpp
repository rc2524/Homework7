#include "connectwindow.h"
#include "ui_connectwindow.h"
#include <QtNetwork>

ConnectWindow::ConnectWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ConnectWindow)
{
    ui->setupUi(this);

    // Fill in ipAddress in textbox
    QString ipAddress;
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    // use the first non-localhost IPv4 address
    for (int i = 0; i < ipAddressesList.size(); ++i) {
        if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
            ipAddressesList.at(i).toIPv4Address()) {
            ipAddress = ipAddressesList.at(i).toString();
            break;
        }
    }
    // if we did not find one, use IPv4 localhost
    if (ipAddress.isEmpty())
        ipAddress = QHostAddress(QHostAddress::LocalHost).toString();
    ui->ipField->setText(ipAddress);
}

ConnectWindow::~ConnectWindow()
{
    delete ui;
}

void ConnectWindow::on_connectButton_clicked()
{
    Client c;
    c.name = ui->nameField->toPlainText();
    c.ip = ui->ipField->toPlainText();
    c.port = ui->portField->toPlainText().toInt();

    emit AttemptConnection(c);
}
