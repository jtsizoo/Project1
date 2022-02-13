#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QMainWindow>

#include "playerwindow.h"

namespace Ui {
class StartWindow;
}

class StartWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit StartWindow(QWidget *parent = nullptr);
    ~StartWindow();

private slots:
    void on_ship1_radioButton_toggled(bool checked);    // 1 ship is selected
    void on_ship2_radioButton_toggled(bool checked);    // 2 ships are selected
    void on_ship3_radioButton_toggled(bool checked);    // 3 ships are selected
    void on_ship4_radioButton_toggled(bool checked);    // 4 ships are selected
    void on_ship5_radioButton_toggled(bool checked);    // 5 ships are selected

    void on_start_pushButton_clicked();     // start game, open ship placement

    void OnPlayer1Done_Ships(bool done);    // player 1 done placing ships
    void OnPlayer2Done_Ships(bool done);    // player 2 done placing ships

private:
    Ui::StartWindow *ui;

    bool shipSelectStatus;  // true when the user selects how many ships to play with
    int shipNumber;         // the number of ships that the user selects

    PlayerWindow * player1; // player 1 window
    PlayerWindow * player2; // player 2 window

    bool player1_shipsDone; // true when player 1 is done placing ships, false otherwise
    bool player2_shipsDone; // true when player 1 is done placing ships, false otherwise

    void startEnable(bool status);  // allow the start button to be clicked or not
    bool areShipsSelected();        // check if the user has selected how many ships to play with

    void showGameMode();    // show ship placement or fight widget based on if players are done with ship placement
};

#endif // STARTWINDOW_H
