#-------------------------------------------------
#
# Project created by QtCreator 2012-12-04T14:37:38
#
#-------------------------------------------------

QT       += core gui network

TARGET = client
TEMPLATE = app


SOURCES += main.cpp\
    clientlistwindow.cpp \
    connectwindow.cpp \
    chatwindow.cpp \
    controller.cpp \
    connection.cpp \
    ../src/message.cpp

HEADERS  += \
    clientlistwindow.h \
    Client.h \
    connectwindow.h \
    chatwindow.h \
    controller.h \
    connection.h \
    ../src/message.h

FORMS    += \
    clientlistwindow.ui \
    connectwindow.ui \
    chatwindow.ui
