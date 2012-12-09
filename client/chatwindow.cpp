#include "chatwindow.h"
#include "ui_chatwindow.h"

ChatWindow::ChatWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChatWindow)
{
    ui->setupUi(this);

    //Bind stream to buffer
    stream.setString(&buffer);

    QObject::connect(this, SIGNAL(sendMessage(QString,QString)), this, SLOT(userChat(QString,QString)));
}

void ChatWindow::setMyName(QString myName) {
    this->myName = myName;
}

ChatWindow::~ChatWindow()
{
    delete ui;
}

void ChatWindow::on_exitButton_clicked()
{
    //Tell everyone to close the chat down
    emit closeChat();

    //Close the window
    this->close();
}


//A user joined the session
void ChatWindow::userJoined(QString name) {
    stream << name << ": joined.\n";
    ui->chatOutput->setText(buffer);
}


//A user left the session
void ChatWindow::userLeft(QString name) {
    stream << name << ": left.\n";
    ui->chatOutput->setText(buffer);
}

//User said something
void ChatWindow::userChat(QString name, QString msg) {
    stream << name << "> " << msg << '\n';
    ui->chatOutput->setText(buffer);
}

// User clicked send or pressed enter
void ChatWindow::on_sendButton_clicked()
{
    emit sendMessage(myName, ui->messageInput->text());

    //Clear chat
    ui->messageInput->clear();

}
