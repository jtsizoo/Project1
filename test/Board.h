#ifndef BOARD_H
#define BOARD_H

#include <iostream>

class Board {
    private:
	std::string player;
    int m_size;
    char** placeGrid;
    char** shotGrid;
	int printCol[10] = {1,2,3,4,5,6,7,8,9,10};
	char printRow[10] = {'A','B','C','D','E','F','G','H','I','J'};

    public:
    Board(int size, std::string playerNum);
    ~Board();
    bool insertShip(int size, int row, int col, char dir);
    bool shootShot(int row, int col, Board* opBoard);
    bool isHit(int row, int col);
    bool checkWin();
    void printShotGrid();
    void printPlaceGrid();
	void printInitialBoard();
};

#endif