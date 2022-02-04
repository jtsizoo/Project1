#include "Executive.h"
#include <limits>

Executive::Executive(int numShips) {
    m_size = 10;
    PTurn = false;
    p1Board = new Board(m_size);
    p2Board = new Board(m_size);
	p1Board->printInitialBoard();
    chooseShipLoc(p1Board, numShips);
    chooseShipLoc(p2Board, numShips);
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
			board->printPlaceGrid();
			std::cout << "\n";
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
	int num10;
	if(input.length() == 3)
	{
		if(input[0] == '1' && input[1] == '0')
		{
			num10 = 10;
		}
	}
	bool lengthCheck1 = 0;
	bool lengthCheck2 = 0;
	bool lengthCheck3 = 0;
	if(input.length() < 2 || input.length() > 3) lengthCheck3 = 1;
	if(input.length() == 2)
	{
		if(!isdigit(input[0]) || isdigit(input[1])) lengthCheck1 = 1;
	}
	else if(input.length() == 3)
	{
		if(num10 != 10 || !isdigit(input[0]) || !isdigit(input[1]) || isdigit(input[2])) lengthCheck2 = 1;
	}	 
while (std::cin.fail() ||lengthCheck3 || lengthCheck1 || lengthCheck2) {
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
