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

    void setShipNumber(int num);

private:
    Ui::PlaceShips *ui;

    int shipNumber;

    void displayShips();
    void initComboBoxes();
};

#endif // PLACESHIPS_H
