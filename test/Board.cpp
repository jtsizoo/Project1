/*-------------------------------------------------------
 *      File Name: Board.cpp
 *      Authors: Alice Kuang, Thresa Kelly, Minwoo Lee, Justin Sizoo, Maggie Swartz (Group #14)
 *      Assignment: EECS_448 Project #1
 *      Description: This is the executable file for the Board class
 *      Date Last Modified: 02/06/2022
 *-----------------------------------------------------*/

#include "Board.h"

Board::Board(int size, std::string playerNum) { //Constructor for Board class, passes in parameters: size of board (always 10x10) and string representing player name/#.
	player = playerNum; //Sets member variable player = to playerNum argument (so either Player 1 or Player 2).
	m_size = size; //Sets member variable m_size = to size argument passed in.
	
    initialGrid = new char* [m_size]; //Creates array of characters to store the players initial placement of ship
	placeGrid = new char*[m_size]; //Creates array of characters to represent player's own ships and how they have decided to place them.
	shotGrid = new char*[m_size]; //Creates array of characters to represent player's shots at opponent's grid and their locations.
	for (int i = 0; i < m_size; i++) { //Nested for loop traverses size of battleship board 2D array.
		initialGrid[i] = new char[m_size];
		placeGrid[i] = new char[m_size]; //First pass creates new array for both boards, finishing creation of a 2D array.
		shotGrid[i] = new char[m_size]; //2D array for both placeGrid and shotGrid.
        		for (int j = 0; j < m_size; j++) { //For loop traverse both placeGrid and shotGrid arrays and initialized all entries to character '0'.
					initialGrid[i][j] = '0';
           			placeGrid[i][j] = '0';
            		shotGrid[i][j] = '0';
        		}
    	}	
}

Board::~Board() { //Destructor for Board class, deletes placeGrid and shotGrid 2D arrays.
	for (int i = 0; i < m_size; i++) { //For loop traverses size of both placeGrid and shotGrid.
		delete[] placeGrid[i]; //Deletes arrays which make both objects 2D.
		delete[] shotGrid[i];
		delete[] initialGrid[i];
	}
	delete[] placeGrid; //Deletes final array placeGrid.
	delete[] shotGrid; //Deletes final array shotGrid.
	delete[] initialGrid; //Deletes final array initialGrid.
}

bool Board::insertShip(int size, int row, int col, char dir) { //insertShip takes in size, row, col, and dir to produce Boolean logic on whether ship can be inserted.
	int x = col; //Set integer x equal to parameter integer col
	int y = row; //Set integer y equal to parameter integer row
	if (dir == 'h') { //If the player desires to orient their ship in the horizontal direction...
		if (x + size > m_size || x < 0) { //If the x location + size of ship is greater than x size of board, or if it's less then zero...
			return false; //Return false because the ship placement exceeds the limits of the board.
      		}
	} else { //Else if the player desires to orient their ship in the vertical direction or input or inputs an invalid character...
		if (y + size > m_size || y < 0) { //If the y location + size of ship is greater than y size of board, or if it's less than zero...
			return false; //Return false because the ship placement exceeds the limits of the board.
		}
	}
	for (int i = 0; i < size; i++) { //For loop traverses size of current ship looking to be placed.
			if (placeGrid[y][x]>= '1' && placeGrid[y][x] >= '5') { //If within the placeGrid board an [i][j] location already contains an ship
			return false; //Return false, because a ship is already present and anothre cannot be placed.
		} else {
		
			char shipNum = '0' + size; //convert the ship number into a char, '0' + number
			placeGrid[y][x] = shipNum; //Else, store the ship location with the ship number.
			initialGrid[y][x] = shipNum; //also update the initialGrid with the shipNumber
			
			if (dir == 'h') { //If desired horizontal orientation, then increase x by 1.
				x += 1;
			} else { //Else if desired vertical orientation, then increase y by 1.
				y += 1;
			}
		}
	}
	return true; //Return true here because the ship was successfully inserted at the desired location.
}

bool Board::shootShot(int row, int col, Board* opBoard) { //shootShot takes in row/col/pointer to opponent's board, returns boolean indicating hit or miss.
	if (opBoard->isHit(row, col)) { //If there was a hit on the opponent's board at the designed row and col location...
		shotGrid[row][col] = 'H'; //Then insert an H in the own player's corresponding shot grid to represent a hit...
		return true; //And return true because the player successfully hit an opponent's battleship.
	} else {
		shotGrid[row][col] = 'M'; //Else, insert a M in own player's corresponding shot grid to represent a miss...
		return false; //And return false because no ship was hit.
	}
}

bool Board::isHit(int row, int col) { //isHit takes in row/col location and returns boolean value indicating whether a ship was hit or not.
	if (placeGrid[row][col] >='1' && placeGrid[row][col] <= '5') { //If within the placeGrid, the row/col location encounters an 'X'...
		placeGrid[row][col] = 'S'; //Then on the placeGrid at the same location, input a character 'S' to represent presence of a shot...
		return true; //And return true becuase there was a hit at the corresponding location.
	} else {
		return false; //Else, the spot was empty and return false as not hit occurred.
	}
}


bool Board::sinkStatus(int row, int col) { //sinkStatus evaluates if a ship is sunk after a hit at a particular row and column location.
	int count = 0; //Initializes integer variable to be used as a counter.
	char element = initialGrid[row][col]; //Get the element stored at the position.
	for (int i = 0; i < m_size; i++) {
		for (int j = 0; j < m_size; j++) {
			if (initialGrid[i][j] == element && placeGrid[i][j] == 'S') { //If initial grid contains the given element and the player sunk the ship.
				count++; //Increases the count.
				if (count == (element-'0')) { //When the count and the element are the same, the ship has been sunk.
					return true; //Return true to exit the function.
				}
			}
		}
	}
	return false; //The ship was not sunk, return false.
}

bool Board::checkWin() { //checkWin takes in no parameters and returns boolean value indicating whether a player has won battleship or not.
	for (int i = 0; i < m_size; i++) { //Nested for loop traverses entirety of placeGrid board.
		for (int j = 0; j < m_size; j++) {
			if (placeGrid[i][j] >= '1' && placeGrid[i][j] <= '5') { //If an X is encountered (representing an un-hit ship location)...
				return false; //Then return false as ships remain and player has not yet won.
			}
		}
	}
	return true; //Else, return true as no ships remain to be hit, player has won battleship.
}

void Board::printBoard(std::string boardType) { //Prints board based on given boardtype, just for UI interface.
	std::cout << "\n" << this->player << "'s " << boardType <<" Grid\n\n"; //Heading designating which player's shot grid is in view.
	for (int i = 0; i <= m_size; i++) { //Nested for loop traverse entirety of board.
		if (i == 1) {
			std::cout << "\n"; //Formatting for top row to display column letters.
		} if (i != 0) {
			std::cout << printCol[i - 1] << " ";
		}
		for (int j = 0; j <= m_size; j++) { //Formatting for displaying row numbers.
			if (i == 0 && j == 0 && i != m_size) {
				std::cout << "  ";
			} if (j == 0 && i != m_size) {
				std::cout << " ";
			} if (i == 0 && j != 0) {
				std::cout << printRow[j - 1] << " ";
			} if (i != 0 && j != m_size) { //Display grid.
				if (boardType == "Shot") {
					std::cout << shotGrid[i - 1][j] << " ";
				} else {
					std::cout << placeGrid[i - 1][j] << " ";
				}
			}
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}
