/********************************************************************************
** Form generated from reading UI file 'clientlistwindow.ui'
**
** Created: Sun Dec 9 16:25:20 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTLISTWINDOW_H
#define UI_CLIENTLISTWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientListWindow
{
public:
    QWidget *centralwidget;
    QListWidget *listWidget;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ClientListWindow)
    {
        if (ClientListWindow->objectName().isEmpty())
            ClientListWindow->setObjectName(QString::fromUtf8("ClientListWindow"));
        ClientListWindow->resize(378, 586);
        centralwidget = new QWidget(ClientListWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(10, 10, 251, 531));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(260, 510, 114, 32));
        ClientListWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ClientListWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 378, 23));
        ClientListWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(ClientListWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ClientListWindow->setStatusBar(statusbar);

        retranslateUi(ClientListWindow);

        QMetaObject::connectSlotsByName(ClientListWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ClientListWindow)
    {
        ClientListWindow->setWindowTitle(QApplication::translate("ClientListWindow", "Clients", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("ClientListWindow", "Connect!", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ClientListWindow: public Ui_ClientListWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTLISTWINDOW_H
