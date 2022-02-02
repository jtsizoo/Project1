#include "Executive.h"

Executive::Executive(int numShips) {
    m_size = 10;
    pTurn = 0;
    p1Board = new Board(m_size);
    p2Board = new Board(m_size);
    chooseShipLoc(p1Board, numShips);
    chooseShipLoc(p1Board, numShips);
}

Executive::~Executive() {
    delete p1Board;
    delete p2Board;
}

void Executive::chooseShipLoc(Board* board, int numShips) {
    std::string shipLoc = "";
    int row = 0;
    int col = 0;
    char column;
    char direction;
    for (int i = 0; i < numShips; i++) {
        std::cout << "Input a location for ship " << i << ": ";
        shipLoc = validateLoc(shipLoc);
        row = shipLoc[0];
        column = shipLoc[1];
        col = charToInt(column);
        std::cout << "Input a direction (N, E, S, W): ";
        direction = validateDirection(direction);
        board->insertShip(i, row-1, col, direction);
    }
}

int Executive::charToInt(char c) {
    int colNum = (int)c;
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
	while (std::cin.fail() && input != 'N' && input != 'E' && input != 'S' && input != 'W') {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Sorry, your input was invalid. Try again: ";
		std::cin >> input;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return input;
}