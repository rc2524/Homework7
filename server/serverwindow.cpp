#include "serverwindow.h"
#include "ui_serverwindow.h"

ServerWindow::ServerWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ServerWindow)
{
    ui->setupUi(this);
}

ServerWindow::~ServerWindow()
{
    delete ui;
}

void ServerWindow::setIP(QString IP_adr)
{
    ui->IP_disp->setText(IP_adr);
}

void ServerWindow::setPort(QString port)
{
    ui->Port_disp->setText(port);
}

void ServerWindow::dispMsg(QString msg)
{
    ui->textEdit->append(msg);
}
