#ifndef BOARD_H
#define BOARD_H

#include <iostream>

class Board {
    private:
    int m_size;
    char** placeGrid;
    char** shotGrid;
	int printCol[10] = {1,2,3,4,5,6,7,8,9,10};
	char printRow[10] = {'A','B','C','D','E','F','G','H','I','J'};

    public:
    Board(int size);
    ~Board();
    bool insertShip(int size, int row, int col, char dir);
	void printInitialBoard();
    void printPlaceGrid();
};

#endif
