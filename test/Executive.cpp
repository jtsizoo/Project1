#include "Executive.h"

Executive::Executive(int numShips) {
    m_size = 10;
    PTurn = 0;
    p1Board = new Board(m_size);
    p2Board = new Board(m_size);
    chooseShipLoc(p1Board, numShips);
    chooseShipLoc(p1Board, numShips);
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
          std::cout << "Input a location for ship " << i+1 << ": ";
          shipLoc = validateLoc(shipLoc);
          row = shipLoc[0];
          column = shipLoc[1];
          col = charToInt(column);
          std::cout << "Input a direction (Horizontal or vertical): ";
          direction = validateDirection(direction);
          if (!board->insertShip(i, row-1, col, direction)) {
            std::cout << "Error: Ship extends outside board. Try again\n";
          } else {
            inserted = true;
          }
        }
        inserted = false;
    }
}

int Executive::charToInt(char c) {
    int colNum = (int)c;
    //ASCII (A-J) -> (65-75)
    colNum -= 65;
    return colNum;
}

std::string Executive::validateLoc(std::string input) {
    std::cin >> input;
	while (std::cin.fail() && input.length() !=     int move = 0;2 && !isdigit(input[0]) && isdigit(input[1])) {
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
