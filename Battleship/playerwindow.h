#ifndef PLAYERWINDOW_H
#define PLAYERWINDOW_H

#include <QMainWindow>
#include <QString>
#include "Board.h"

namespace Ui {
class PlayerWindow;
}

class PlayerWindow : public QMainWindow
{
    Q_OBJECT

public:
    Board board;

    explicit PlayerWindow(QWidget *parent = nullptr);
    ~PlayerWindow();

    void setShipNumber(int ship);   // set the number of ships per player
    void setPlayer(QString player); // set the name/ID of the player
    void showPlaceShips(bool show); // if true, show the placeShips Widget. Otherwise, show fight widget.

private slots:
    void OnPlayerDone(bool done);   // disable widget when player is done placing ships

private:
    Ui::PlayerWindow *ui;

signals:
    void playerDone(bool done);     // emit when player is done placing ships
};

#endif // PLAYERWINDOW_H
