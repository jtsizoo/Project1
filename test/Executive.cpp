/*-------------------------------------------------------
 *      File Name: Executive.cpp
 *      Authors: Alice Kuang, Thresa Kelly, Minwoo Lee, Justin Sizoo, Maggie Swartz (Group #14)
 *      Assignment: EECS_448 Project #1
 *      Description: This is the executable file for the Executive class
 *      Date Last Modified: 02/06/2022
 *-----------------------------------------------------*/

#include "Executive.h"
#include <limits>
#include<iostream>
#include <cctype>

Executive::Executive(int numShips) { //Constructor for Executive class, takes in selected number of ships as a parameter.
	m_size = 10; //Sets member variable m_size equal to 10 (creation of 10x10 playing board.
	PTurn = false; //Variable PTurn keeps track of which player's turn it is, starts at false so Player 1 will go first.
	p1Board = new Board(m_size, "Player 1"); //Creates instance of Board class for Player 1, takes in m_size and name "Player 1" as parameters.
	p2Board = new Board(m_size, "Player 2"); //Creates instance of Board class for Player 2, take in m_size and name "Player 2" as parameters.
	p1Board->printBoard("Initial"); //Prints out initial board prior to ship location selection.
	chooseShipLoc(p1Board, numShips); //Player 1 places their ships on their board w/ selected number of ships.
	chooseShipLoc(p2Board, numShips); //Player 2 places their ships on their board w/ selected number of ships.
}

Executive::~Executive() { //Destructor for the Executive class.
    delete p1Board; //Deletes instance of Board class associated with Player 1.
    delete p2Board; //Deletes instance of Board class associated with Player 2.
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
		 if(shot.length() ==3)
		  {
			  row = 9; //If row = 10
			  column = tolower(shot[2]);
			  col = charToInt(column);
		  }
		  else
		  {
				row = (int)shot[0] - 49;
				column = tolower(shot[1]);
				col = charToInt(column);
		  }

        if (board->shootShot(row, col, opBoard)) { //check for hit or miss
			if (opBoard->sinkStatus(row, col)) { //check if ship was sunk
				std::cout << "SUNK!\n\n"; 
			}
			else std::cout << "HIT!\n\n"; //if not sunk, it was hit 

			board->printBoard("Shot"); //print the shotGrid
            
			if (opBoard->checkWin()) { //check if there is a winner for this round
                break;
            }
        } else {
            std::cout << "MISS!\n\n";
			board->printBoard("Shot");
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
		  if(shipLoc.length() ==3)
		  {
			  row = 9; //If row = 10
			  column = tolower(shipLoc[2]);
			  col = charToInt(column);
		  }
		  else
		  {
			  row = (int)shipLoc[0] - 49;
			  column = tolower(shipLoc[1]);
			  col = charToInt(column);
		  }
		  if(i == 0) direction = 'H'; //If i=0, the first ship is being entered and a direction is not necessary.
		  else
		  {
			  std::cout << "Input a direction (Horizontal or vertical): ";
			  direction = validateDirection(direction);
		  }
          if (!board->insertShip(i+1, row, col, direction)) {
            std::cout << "Error - Invalid Location : Ship already exists here or extends outside board. Try again\n";
          } else {
            inserted = true;
			board->printBoard("Place");
          }
        }
        inserted = false;
    }
    PTurn = !PTurn;
}

int Executive::charToInt(char c) { //charToInt takes in a character and converts that to the ASCII correlated integer value.
    int colNum = (int)c; //Set colNum variable equal to (int)c.
    colNum -= 97; //ASCII (a-j) is equal to 97 to 107, so subtract off 97 to convert to correct integer value.
    return colNum; //Return colNum integer value.
}

// collect user input for string and ensure it is a valid entry, i.e. follows the row-column format (1a)
std::string Executive::validateLoc(std::string input) {
    std::cin >> input;
	bool restrictLength = 0;
	bool invalidFormat = 0;
	bool validChar = 0;
	if(input.length() < 2 || input.length() > 3) restrictLength = 1; //Restrict the length to strings of 2 or 3
	if(input.length() == 2) //i.e. 1 digit followed by 1 letter
	{
		if(!isdigit(input[0]) || isdigit(input[1])) invalidFormat = 1; 
		if(charToInt(input[1]) >= 0 && charToInt(input[1]) < 10) validChar = 1; //validate lower char case
		else if(charToInt(input[1]) > -33 && charToInt(input[1]) < -22) validChar = 1; //validate capital char case
	}
	else if(input.length() == 3) //i.e. 2 digit followed by 1 letter
	{
		if(!isdigit(input[0]) || !isdigit(input[1]) || isdigit(input[2]) || (input[0] != '1' && input[1] != '0')) invalidFormat = 1;
		if(charToInt(input[2]) >= 0 && charToInt(input[2]) < 10) validChar = 1; //validate lower char case
		else if(charToInt(input[2]) > -33 && charToInt(input[2]) < -22) validChar = 1; //validate capital char case
	}	 
	while (std::cin.fail() || restrictLength || invalidFormat || !validChar) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (invalidFormat) std::cout << "Your input should specify the row and then column, i.e. 1a. Try again and hit enter twice to process: ";
		else std::cout << "Sorry, your input was invalid. Try again and hit enter twice to process: ";
		input = validateLoc(input); //originally: std::cin >> input; 
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return input;
}

char Executive::validateDirection(char input) { //validateDirection function interprets user input for orientation, returns 'v'(vertical)  or 'h' (horizontal).
    std::cin >> input; //Takes in user input to determine ship orientation.
    input = tolower(input); //Convets input to lowercase equivalent if not already lowercase (H==h and V==v).
	while (std::cin.fail() || (input != 'h' && input != 'v')) { //If user input is not h for horizontal or v for vertical...
		std::cin.clear(); //Using cin.fail functionality...
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Sorry, your input was invalid. Try again: "; //Display error message and give user opportunity to input until acceptable input.
		std::cin >> input;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
	return input; //Return input value as 'v' or 'h' to reprsent desired orientation. 
}
