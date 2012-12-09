TEMPLATE = app
TARGET = server
DEPENDPATH += .
INCLUDEPATH += ../src
QT           += network

# Input
HEADERS += server.h \
    serverwindow.h \
    ../src/message.h \
    clientthread.h \
    SSLServer.h
SOURCES += main.cpp server.cpp ../src/SSLServer.cpp \
    serverwindow.cpp \
    ../src/message.cpp \
    clientthread.cpp \
    SSLServer.cpp

FORMS += \
    serverwindow.ui
