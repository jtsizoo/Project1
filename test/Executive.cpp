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
    Board* board = p1Board;
    Board* opBoard = p2Board;
    while (true) {
        std::string shot = "";
        int row = 0;
        int col = 0;
        char column;

        std::cout << "Player " << PTurn+1 << ", take your shot: ";
        shot = validateLoc(shot);
        row = (int)shot[0] - 47;
        column = tolower(shot[1]);
        col = charToInt(column);

        if (board->shootShot(row, col, opBoard)) {
            std::cout << "HIT:\n\n";
            board->printShotGrid();
            if (opBoard->checkWin()) {
                break;
            }
        } else {
            std::cout << "MISS:\n\n";
            board->printShotGrid();
            Board* temp = board;
            board = opBoard;
            opBoard = temp;
            PTurn = !PTurn;
        }
    }
    std::cout << "\nGame end: Player " << PTurn+1 << " wins.\n";
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

          row = (int)shipLoc[0] - 47;
          column = tolower(shipLoc[1]);
          col = charToInt(column);

          std::cout << "Input a direction (Horizontal or vertical): ";
          direction = validateDirection(direction);
          if (!board->insertShip(i+1, row, col, direction)) {
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
    //ASCII (a-j) -> (97-107)
    colNum -= 97;
    return colNum;
}

std::string Executive::validateLoc(std::string input) {
    std::cin >> input;
	while (std::cin.fail() || input.length() != 2 || !isdigit(input[0]) || isdigit(input[1])) {
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
    input = tolower(input);
	while (std::cin.fail() || (input != 'h' && input != 'v')) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Sorry, your input was invalid. Try again: ";
		std::cin >> input;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return input;
}