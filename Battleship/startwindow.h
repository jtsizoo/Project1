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
    void on_ship1_radioButton_toggled(bool checked);
    void on_ship2_radioButton_toggled(bool checked);
    void on_ship3_radioButton_toggled(bool checked);
    void on_ship4_radioButton_toggled(bool checked);
    void on_ship5_radioButton_toggled(bool checked);

    void on_start_pushButton_clicked();

    void OnPlayer1Done_Ships(bool);
    void OnPlayer2Done_Ships(bool);

private:
    Ui::StartWindow *ui;

    bool shipSelectStatus;  // true when the user selects how many ships to play with
    int shipNumber;         // the number of ships that the user selects

    PlayerWindow * player1;
    PlayerWindow * player2;

    void startEnable(bool status);  // allow the start button to be clicked or not
    bool areShipsSelected();        // check if the user has selected how many ships to play with
};

#endif // STARTWINDOW_H
