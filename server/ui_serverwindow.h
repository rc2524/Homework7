/********************************************************************************
** Form generated from reading UI file 'serverwindow.ui'
**
** Created: Sun Dec 9 02:36:06 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVERWINDOW_H
#define UI_SERVERWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFormLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ServerWindow
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *IP_label;
    QLabel *IP_disp;
    QLabel *Port_label;
    QLabel *Port_disp;
    QTextEdit *textEdit;
    QPushButton *quitButton;

    void setupUi(QWidget *ServerWindow)
    {
        if (ServerWindow->objectName().isEmpty())
            ServerWindow->setObjectName(QString::fromUtf8("ServerWindow"));
        ServerWindow->resize(400, 300);
        verticalLayout = new QVBoxLayout(ServerWindow);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        IP_label = new QLabel(ServerWindow);
        IP_label->setObjectName(QString::fromUtf8("IP_label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, IP_label);

        IP_disp = new QLabel(ServerWindow);
        IP_disp->setObjectName(QString::fromUtf8("IP_disp"));

        formLayout->setWidget(0, QFormLayout::FieldRole, IP_disp);

        Port_label = new QLabel(ServerWindow);
        Port_label->setObjectName(QString::fromUtf8("Port_label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, Port_label);

        Port_disp = new QLabel(ServerWindow);
        Port_disp->setObjectName(QString::fromUtf8("Port_disp"));

        formLayout->setWidget(1, QFormLayout::FieldRole, Port_disp);


        verticalLayout->addLayout(formLayout);

        textEdit = new QTextEdit(ServerWindow);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setReadOnly(true);

        verticalLayout->addWidget(textEdit);

        quitButton = new QPushButton(ServerWindow);
        quitButton->setObjectName(QString::fromUtf8("quitButton"));

        verticalLayout->addWidget(quitButton);


        retranslateUi(ServerWindow);

        QMetaObject::connectSlotsByName(ServerWindow);
    } // setupUi

    void retranslateUi(QWidget *ServerWindow)
    {
        ServerWindow->setWindowTitle(QApplication::translate("ServerWindow", "Chat Server", 0, QApplication::UnicodeUTF8));
        IP_label->setText(QApplication::translate("ServerWindow", "IP Address:", 0, QApplication::UnicodeUTF8));
        IP_disp->setText(QApplication::translate("ServerWindow", "0.0.0.0", 0, QApplication::UnicodeUTF8));
        Port_label->setText(QApplication::translate("ServerWindow", "Port:", 0, QApplication::UnicodeUTF8));
        Port_disp->setText(QApplication::translate("ServerWindow", "00000", 0, QApplication::UnicodeUTF8));
        quitButton->setText(QApplication::translate("ServerWindow", "Quit", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ServerWindow: public Ui_ServerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERWINDOW_H
