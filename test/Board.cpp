#include "Board.h"

Board::Board(int size) {
    m_size = size;
    placeGrid = new char*[m_size];
    shotGrid = new char*[m_size];
    for (int i = 0; i < m_size; i++) {
        placeGrid[i] = new char[m_size];
        shotGrid[i] = new char[m_size];
        for (int j = 0; j < m_size; j++) {
            placeGrid[i][j] = '0';
            shotGrid[i][j] = '0';
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
    int x = col;
    int y = row;

    if (dir == 'H') {
      if ((x+1) + size > m_size) {
        return false;
      }
    } else {
      if ((y+1) + size > m_size) {
        return false;
      }
    }

    for (int i = 0; i < size; i++) {
        placeGrid[y][x] = 'X';
        if (dir == 'H') {
            x += 1;
        } else {
            y += 1;
        }
    }
    return true;
}

void Board::printPlaceGrid() {
  for (int i = 0; i < m_size; i++) {
    for (int j = 0; j < m_size; j++) {
      std::cout << placeGrid[i][j] << " ";
    }
    std::cout << '\n';
  }
}
