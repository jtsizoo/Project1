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

private slots:
    void OnPlayerDone(bool done);

private:
    Ui::PlayerWindow *ui;

    void showPlaceShips(bool show);
signals:
    void playerDone(bool done);
};

#endif // PLAYERWINDOW_H
