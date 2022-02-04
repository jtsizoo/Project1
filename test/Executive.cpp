#include "Executive.h"
#include <limits>

Executive::Executive(int numShips) {
    m_size = 10;
    PTurn = false;
    p1Board = new Board(m_size, "Player 1");
    p2Board = new Board(m_size, "Player 2");
	p1Board->printInitialBoard();
    chooseShipLoc(p1Board, numShips);
    chooseShipLoc(p2Board, numShips);
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
        row = (int)shot[0] - 49;
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

          row = (int)shipLoc[0] - 49;
          column = tolower(shipLoc[1]);
          col = charToInt(column);
		  if(i == 0) direction = 'H'; //If i=0, the first ship is being entered and a direction is not necessary.
		  else
		  {
			  std::cout << "Input a direction (Horizontal or vertical): ";
			  direction = validateDirection(direction);
		  }
          if (!board->insertShip(i+1, row, col, direction)) {
            std::cout << "Error: Ship extends outside board. Try again\n";
          } else {
            inserted = true;
          }
        }
        inserted = false;
    }
	board->printPlaceGrid();
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
	bool restrictLength = 0;
	bool lengthCheck2 = 0;
	bool lengthCheck3 = 0;
	bool validChar = 0;
	if(input.length() < 2 || input.length() > 3) restrictLength = 1;
	if(input.length() == 2)
	{
		if(!isdigit(input[0]) || isdigit(input[1])) lengthCheck2 = 1;
		if(charToInt(input[1]) >= 0 && charToInt(input[1]) < 10) validChar = 1; //validate lower char case
		else if(charToInt(input[1]) > -33 && charToInt(input[1]) < -22) validChar = 1; //validate capital char case
	}
	else if(input.length() == 3)
	{
		if(!isdigit(input[0]) || !isdigit(input[1]) || isdigit(input[2]) || (input[0] != '1' && input[1] != '0')) lengthCheck3 = 1;
		if(charToInt(input[2]) >= 0 && charToInt(input[2]) < 10) validChar = 1; //validate lower char case
		else if(charToInt(input[2]) > -33 && charToInt(input[2]) < -22) validChar = 1; //validate capital char case
	}	 
	while (std::cin.fail() || restrictLength || lengthCheck3 || lengthCheck2 || !validChar) {
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