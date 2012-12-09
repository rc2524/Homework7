#ifndef SERVERWINDOW_H
#define SERVERWINDOW_H

#include <QWidget>
#include <QString>

namespace Ui {
class ServerWindow;
}

class ServerWindow : public QWidget
{
    Q_OBJECT
    
public:
    explicit ServerWindow(QWidget *parent = 0);
    ~ServerWindow();
    
    void setIP(QString IP_adr);
    void setPort(QString port);

    void dispMsg(QString msg);

private:
    Ui::ServerWindow *ui;
};

#endif // SERVERWINDOW_H
