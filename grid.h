#ifndef GRID_H
#define GRID_H

#include <QWidget>

namespace Ui {
class Grid;
}

class Grid : public QWidget
{
    Q_OBJECT

public:
    explicit Grid(QWidget *parent = nullptr);
    ~Grid();

    void setEmpty(int row, int col);    // make cell blue
    void setShip(int row, int col);     // make cell gray
    void setMiss(int row, int col);     // make cell white
    void setHit(int row, int col);      // make cell red
    void cleanBoard();                  // make all cells blue

private:
    Ui::Grid *ui;

    void init();    // initialize the board
};

#endif // GRID_H
