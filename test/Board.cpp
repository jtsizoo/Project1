#include "Board.h"

Board::Board(int size) {
    m_size = size;
    placeGrid = new char*[m_size];
    shotGrid = new char*[m_size];
    for (int i = 0; i < m_size; i++) {
        placeGrid[i] = new char[m_size];
        shotGrid[i] = new char[m_size];
        for (int j = 0; j < m_size; j++) {
            placeGrid[i][j] = '\0';
            shotGrid[i][j] = '\0';
        }
    }
}

Board::~Board() {
    for (int i = 0; i < m_size; i++) {
        delete[] placeGrid[i];
        delete[] shotGrid[i];
    }
    delete[] placeGrid;
    delete[] shotGrid;
}

void Board::insertShip(int size, int row, int col, char dir) {
    int x = row;
    int y = col;
    int move = 0;
    bool vertical = false;
    
    if (dir == 'N' || dir == 'S') {
        vertical = true;
        if (dir == 'N') {
            move = 1;
        } else {
            move = -1;
        }
    } else {
        if (dir == 'E') {
            move = 1;
        } else {
            move = -1;
        }
    }
    for (int i = 0; i < size; i++) {
        placeGrid[x][y] = 'F';
        if (vertical) {
            y += move;
        } else {
            x += move;
        }
    }
}