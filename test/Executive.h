#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <iostream>
#include <string>
#include "Board.h"

class Executive {
    private:
    int m_size;
    Board* p1Board;
    Board* p2Board;
    int pTurn;

    public:
    Executive(int numShips);
    ~Executive();
    void chooseShipLoc(Board* board, int numShips);
    void run();
    void printBoard();
    int charToInt(char c);
    std::string validateLoc(std::string input);
    char validateDirection(char input);
};

#endif