#ifndef BOARD_H
#define BOARD_H

#include <iostream>

class Board {
    private:
    int m_size;
    char** placeGrid;
    char** shotGrid;

    public:
    Board(int size);
    ~Board();
    bool insertShip(int size, int row, int col, char dir);
    bool shootShot(int row, int col, Board* opBoard);
    bool isHit(int row, int col);
    bool checkWin();
    void printShotGrid();
    void printPlaceGrid();
};

#endif
