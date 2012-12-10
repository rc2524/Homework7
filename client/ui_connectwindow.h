/********************************************************************************
** Form generated from reading UI file 'connectwindow.ui'
**
** Created: Sun Dec 9 20:54:42 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTWINDOW_H
#define UI_CONNECTWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConnectWindow
{
public:
    QWidget *centralwidget;
    QTextEdit *nameField;
    QLabel *label;
    QLabel *label_2;
    QTextEdit *portField;
    QTextEdit *ipField;
    QLabel *label_3;
    QPushButton *connectButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ConnectWindow)
    {
        if (ConnectWindow->objectName().isEmpty())
            ConnectWindow->setObjectName(QString::fromUtf8("ConnectWindow"));
        ConnectWindow->resize(331, 236);
        centralwidget = new QWidget(ConnectWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        nameField = new QTextEdit(centralwidget);
        nameField->setObjectName(QString::fromUtf8("nameField"));
        nameField->setGeometry(QRect(110, 40, 201, 31));
        nameField->setTabChangesFocus(true);
        nameField->setAcceptRichText(false);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 50, 62, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 80, 62, 16));
        portField = new QTextEdit(centralwidget);
        portField->setObjectName(QString::fromUtf8("portField"));
        portField->setGeometry(QRect(110, 70, 201, 31));
        portField->setTabChangesFocus(true);
        portField->setAcceptRichText(false);
        ipField = new QTextEdit(centralwidget);
        ipField->setObjectName(QString::fromUtf8("ipField"));
        ipField->setGeometry(QRect(110, 100, 201, 31));
        ipField->setTabChangesFocus(true);
        ipField->setAcceptRichText(false);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 110, 62, 16));
        connectButton = new QPushButton(centralwidget);
        connectButton->setObjectName(QString::fromUtf8("connectButton"));
        connectButton->setGeometry(QRect(120, 140, 114, 32));
        ConnectWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ConnectWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 331, 25));
        ConnectWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(ConnectWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ConnectWindow->setStatusBar(statusbar);

        retranslateUi(ConnectWindow);

        QMetaObject::connectSlotsByName(ConnectWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ConnectWindow)
    {
        ConnectWindow->setWindowTitle(QApplication::translate("ConnectWindow", "Connect", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ConnectWindow", "Name", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ConnectWindow", "Port", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ConnectWindow", "IP", 0, QApplication::UnicodeUTF8));
        connectButton->setText(QApplication::translate("ConnectWindow", "Connect", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ConnectWindow: public Ui_ConnectWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTWINDOW_H
