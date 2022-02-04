
#include "Board.h"

Board::Board(int size, std::string playerNum) {
	player = playerNum;
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

    if (dir == 'h') {
      if (x + size > m_size || x < 0) {
        return false;
      }
    } else {
      if (y + size > m_size || y < 0) {
        return false;
      }
    }

    for (int i = 0; i < size; i++) {
		if(placeGrid[y][x] == 'X')
		{
			return false;
		}
		else
		{
			placeGrid[y][x] = 'X';
			if (dir == 'h') {
				x += 1;
			} else {
				y += 1;
			}
		}
    }
    return true;
}

bool Board::shootShot(int row, int col, Board* opBoard) {
  if (opBoard->isHit(row, col)) {
    shotGrid[row][col] = 'H';
    return true;
  } else {
    shotGrid[row][col] = 'M';
    return false;
  }
}

bool Board::isHit(int row, int col) {
  if (placeGrid[row][col] == 'X') {
    placeGrid[row][col] = 'S';
    return true;
  } else {
    return false;
  }
}

bool Board::checkWin() {
  for (int i = 0; i < m_size; i++) {
    for (int j = 0; j < m_size; j++) {
      if (placeGrid[i][j] == 'X') {
        return false;
      }
    }
  }
  return true;
}

void Board::printShotGrid() {
	std::cout << "\n" << this->player <<"'s " << "Shot Grid\n\n";
	for(int i=0; i<=m_size; i++)
	{
		if(i==1) std::cout << "\n";
		if(i != 0) std::cout << printCol[i-1] << " ";
		for(int j=0; j<=m_size; j++)
		{
			if(i==0 && j==0 && i!= m_size) std::cout << "  ";
			if(j == 0 && i != m_size) std::cout << " ";
			if(i==0 && j != 0) std::cout << printRow[j-1] << " ";
			else if(i != 0 && j!= m_size) std::cout << shotGrid[i-1][j] << " ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";	
}

void Board::printPlaceGrid() {
	std::cout << "\n" << this->player <<"'s " << "Place Grid\n\n";
	for(int i=0; i<=m_size; i++)
	{
		if(i==1) std::cout << "\n";
		if(i != 0) std::cout << printCol[i-1] << " ";
		for(int j=0; j<=m_size; j++)
		{
			if(i==0 && j==0 && i!= m_size) std::cout << "  ";
			if(j == 0 && i != m_size) std::cout << " ";
			if(i==0 && j != 0) std::cout << printRow[j-1] << " ";
			else if(i != 0 && j!= m_size) std::cout << placeGrid[i-1][j] << " ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";	
}

void Board::printInitialBoard() {
	std::cout << "\n";
	for(int i=0; i<=m_size; i++)
	{
		if(i==1) std::cout << "\n";
		if(i != 0) std::cout << printCol[i-1] << " ";
		for(int j=0; j<=m_size; j++)
		{
			if(i==0 && j==0 && i!= m_size) std::cout << "  ";
			if(j == 0 && i != m_size) std::cout << " ";
			if(i==0 && j != 0) std::cout << printRow[j-1] << " ";
			else if(i != 0 && j!= m_size) std::cout << "0 ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}