#ifndef PLAYERWINDOW_H
#define PLAYERWINDOW_H

#include <QMainWindow>
#include <QString>

namespace Ui {
class PlayerWindow;
}

class PlayerWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PlayerWindow(QWidget *parent = nullptr);
    ~PlayerWindow();

    void setShipNumber(int ship);
    void setPlayer(QString player);

private:
    Ui::PlayerWindow *ui;

};

#endif // PLAYERWINDOW_H
