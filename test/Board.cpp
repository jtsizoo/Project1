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

bool Board::insertShip(int size, int row, int col, char dir) {
    int x = row;
    int y = col;

    if (dir == 'H') {
      if ((x+1) + size > m_size || (y+1) + size > m_size) {
        return false;
      }
    }
    for (int i = 0; i < size; i++) {
        placeGrid[x][y] = 'O';
        if (dir == 'V') {
            y += 1;
        } else {
            x += 1;
        }
    }
    return true;
}

bool checkValidLoc() {

}
