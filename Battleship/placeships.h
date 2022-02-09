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

private:
    Ui::PlaceShips *ui;

    int shipNumber;         // sumber of ships per player

    void displayShips();    // show the available ships to place
    void initComboBoxes();  // add coordinant grids to combo boxes

signals:
    void done(bool show);   // emit when player is done placing ships
};

#endif // PLACESHIPS_H
