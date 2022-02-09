#ifndef PLACESHIPS_H
#define PLACESHIPS_H

#include <QWidget>

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
    void on_done_pushButton_clicked();

    void on_place_pushButton_clicked();

private:
    Ui::PlaceShips *ui;

    int shipNumber; // number of ships per player

    bool ship1;     // true when ship has been placed, false otherwise
    bool ship2;     // true when ship has been placed, false otherwise
    bool ship3;     // true when ship has been placed, false otherwise
    bool ship4;     // true when ship has been placed, false otherwise
    bool ship5;     // true when ship has been placed, false otherwise

    void displayShips();    // show the available ships to place
    void initComboBoxes();  // add coordinant grids to combo boxes
    void checkAllShips();   // check if all ships have been placed

signals:
    void done(bool show);   // emit when player is done placing ships
};

#endif // PLACESHIPS_H
