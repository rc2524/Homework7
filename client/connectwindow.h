#ifndef CONNECTWINDOW_H_
#define CONNECTWINDOW_H_

#include <QMainWindow>
#include <stdio.h>
#include "Client.h"

namespace Ui {
class ConnectWindow;
}

class ConnectWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ConnectWindow(QWidget *parent = 0);
    ~ConnectWindow();


private slots:
    void on_connectButton_clicked();

private:
    Ui::ConnectWindow *ui;

signals:
    //User pressed connect button, relay information
    void AttemptConnection(Client c);
};

#endif // MAINWINDOW_H
