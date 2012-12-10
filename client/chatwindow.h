#ifndef CHATWINDOW_H_
#define CHATWINDOW_H_

#include <QMainWindow>
#include <QTextStream>
#include <stdio.h>
#include "Client.h"

namespace Ui {
class ChatWindow;
}

class ChatWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChatWindow(QWidget *parent = 0);

    //Configure sending user name (my name)
    void setMyName(QString myName);

    ~ChatWindow();


private slots:
    //User pressed exit button
    void on_exitButton_clicked();

    //User pressed send button
    void on_sendButton_clicked();

    void on_quitButton_clicked();

public slots:
    //A user joined the session
    void userJoined(QString name);

    //A user left the session
    void userLeft(QString name);

    //User said something
    void userChat(QString name, QString msg);

private:
    Ui::ChatWindow *ui;

    //Keep track of my name
    QString myName;

    //Text buffer
    QTextStream stream;
    QString buffer;
signals:
    //User pressed back button
    void closeChat();
    //User pressed the Quitbutton
    void quit();

    //User sent a message
    void sendMessage(QString name, QString msg);
};

#endif // MAINWINDOW_H
