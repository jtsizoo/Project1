#include "Executive.h"
#include <limits>

Executive::Executive(int numShips) {
    m_size = 10;
    PTurn = false;
    p1Board = new Board(m_size);
    p2Board = new Board(m_size);
    chooseShipLoc(p1Board, numShips);
    chooseShipLoc(p2Board, numShips);
    p1Board->printPlaceGrid();
    std::cout << '\n';
    p2Board->printPlaceGrid();
}

Executive::~Executive() {
    delete p1Board;
    delete p2Board;
}

void Executive::run() {

}

void Executive::chooseShipLoc(Board* board, int numShips) {
    std::string shipLoc = "";
    int row = 0;
    int col = 0;
    char column;
    char direction;
    bool inserted = false;
    for (int i = 0; i < numShips; i++) {
        while (!inserted) {
          std::cout << "Player " << PTurn+1 << ", Input a location for ship " << i+1 << ": ";
          shipLoc = validateLoc(shipLoc);
          row = (int)shipLoc[0] - 48;
          column = shipLoc[1];
          col = charToInt(column);
          std::cout << "Input a direction (Horizontal or vertical): ";
          direction = validateDirection(direction);
          if (!board->insertShip(i+1, row-1, col, direction)) {
            std::cout << "Error: Ship extends outside board. Try again\n";
          } else {
            inserted = true;
          }
        }
        inserted = false;
    }
    PTurn = !PTurn;
}

int Executive::charToInt(char c) {
    int colNum = (int)c;
    //ASCII (A-J) -> (65-75)
    colNum -= 65;
    return colNum;
}

std::string Executive::validateLoc(std::string input) {
    std::cin >> input;
	while (std::cin.fail() && input.length() != 2 && !isdigit(input[0]) && isdigit(input[1])) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Sorry, your input was invalid. Try again: ";
		std::cin >> input;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return input;
}

char Executive::validateDirection(char input) {
    std::cin >> input;
	while (std::cin.fail() && input != 'H' && input != 'V') {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Sorry, your input was invalid. Try again: ";
		std::cin >> input;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return input;
}
