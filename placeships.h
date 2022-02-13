#ifndef PLACESHIPS_H
#define PLACESHIPS_H

#include <QWidget>
#include "Board.h"

namespace Ui {
class PlaceShips;
}

class PlaceShips : public QWidget
{
    Q_OBJECT

public:
    explicit PlaceShips(QWidget *parent = nullptr);
    ~PlaceShips();

    void setShipNumber(int num);    // set the number of ships to play with

private slots:
    void on_done_pushButton_clicked();  // done placing all ships
    void on_place_pushButton_clicked(); // place ship

    void on_ship1_radioButton_clicked();    // check for valid coordinant
    void on_ship2_radioButton_clicked();    // check for valid coordinant
    void on_ship3_radioButton_clicked();    // check for valid coordinant
    void on_ship4_radioButton_clicked();    // check for valid coordinant
    void on_ship5_radioButton_clicked();    // check for valid coordinant

    void on_col_comboBox_setValue();
    void on_row_comboBox_setValue();
    void on_dir_comboBox_setValue();

private:
    Ui::PlaceShips *ui;

    Board checkBoard;
    int shipNumber; // number of ships per player
    int currentShip;

    bool ship1;     // true when ship has been placed, false otherwise
    bool ship2;     // true when ship has been placed, false otherwise
    bool ship3;     // true when ship has been placed, false otherwise
    bool ship4;     // true when ship has been placed, false otherwise
    bool ship5;     // true when ship has been placed, false otherwise

    void displayShips();    // show the available ships to place
    void initComboBoxes();  // add coordinant grids to combo boxes
    void checkAllShips();   // check if all ships have been placed
    void checkCoordinant(int row, int col, int shipSize, bool isHorizontal);    // check if ship can be placed

    int getRowCoordinant(); // get row (1-10) coordinant (0-9) from combo box
    int getColCoordinant(); // get col (A-J) coordinant (0-9) from combo box
    bool getDirection();    // get direction, false is vertical and true is horizontal

signals:
    void done(bool show);   // emit when player is done placing ships
};

#endif // PLACESHIPS_H
