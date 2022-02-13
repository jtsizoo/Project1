/*-------------------------------------------------------
 *      File Name: Executive.cpp
 *      Authors: Alice Kuang, Thresa Kelly, Minwoo Lee, Justin Sizoo, Maggie Swartz (Group #14)
 *      Assignment: EECS_448 Project #1
 *      Description: This is the executable file for the Executive class
 *      Date Last Modified: 02/06/2022
 *-----------------------------------------------------*/

#include "Executive.h"
#include <limits>
#include <iostream>
#include <cctype>

Executive::Executive(int numShips) { //Constructor for Executive class, takes in selected number of ships as a parameter.
	m_size = 10; //Sets member variable m_size equal to 10 (creation of 10x10 playing board.
	PTurn = false; //Variable PTurn keeps track of which player's turn it is, starts at false so Player 1 will go first when gameplay begins.
	p1Board = new Board(m_size, "Player 1"); //Creates instance of Board class for Player 1, takes in m_size and name "Player 1" as parameters.
	p2Board = new Board(m_size, "Player 2"); //Creates instance of Board class for Player 2, take in m_size and name "Player 2" as parameters.
	p1Board->printBoard("Initial"); //Prints out initial board prior to ship location selection.
	chooseShipLoc(p1Board, numShips); //Player 1 places their ships on their board w/ selected number of ships.
	p2Board->printBoard("Initial");
	chooseShipLoc(p2Board, numShips); //Player 2 places their ships on their board w/ selected number of ships.
}

Executive::~Executive() { //Destructor for the Executive class.
	delete p1Board; //Deletes instance of Board class associated with Player 1.
	delete p2Board; //Deletes instance of Board class associated with Player 2.
}

void Executive::run() { //Void run function enables all gameplay functionality.
	Board* board = p1Board; //Creates a pointer to Board instance p1Board (Player 1).
	Board* opBoard = p2Board; //Creates a pointer to Board instance opBoard (Player 2).
	while (true) { //While loop to enable continuous gameplay until there is a winner.
				char confirm;
        std::string shot = ""; //Initializes string shot to an empty string.
        int row = 0; //Initializes row location integer to 0.
        int col = 0; //Initializes column location integer to 0.
        char column; //Creates char variable representing the column ID.
				board->printBoard("Shot"); //Print the updated shotGrid.
        std::cout << "Player " << PTurn+1 << ", take your shot: "; //Message indicating Player 1 goes first, but alternates to next player in future by + on PTurn.
        shot = validateLoc(shot); //Validate shot location.
				if(shot.length() ==3) { //If function helps to process shot location if in row 10 (legnth is 3 due to char + 10).
					row = 9; //If we are in row = 10...
					column = tolower(shot[2]);
					col = charToInt(column); //Then correctly concert to integer to identify appropriate location.
		  	} else { //Else if we are in rows 1-9...
					row = (int)shot[0] - 49; //Convert string to appropriate location identification.
					column = tolower(shot[1]);
					col = charToInt(column);
		  	}
        if (board->shootShot(row, col, opBoard)) { //Check to see if there was a hit or miss at shot location.
					if (opBoard->sinkStatus(row, col)) { //See if this shot resulted in the sinking of a ship...
						std::cout << "SUNK!\n\n"; //If it did, output message indicating sunk status.
					}
				else std::cout << "HIT!\n\n"; //If not sunk, but a hit did occur, then issue message indicating hit status.

			board->printBoard("Shot"); //Print the updated shotGrid.

			if (opBoard->checkWin()) { //Check to see if this round of gameplay resulted in a winner.
                	break;
            		}
      } else { //Else, a hit did not occur in this round of gameplay.
            		std::cout << "MISS!\n\n"; //Output message indicating a miss occured.
			board->printBoard("Shot"); //Print shot board.
        	}
			Board* temp = board; //Create temp board.
			board = opBoard; //Set equal to opponent's board.
			opBoard = temp; //Set opponent's board equal to temp.
			std::cout << "Press the Y key to confirm player switch: ";
			std::cin >> confirm;
			while (std::cin.fail() || (confirm != 'Y' && confirm != 'y')) { //While innapropriate input occurs...
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Utilize cin.fail and output error message, need correct input to continue.
				std::cout << "Invalid Input - Press the Y key to confirm player switch: ";
				std::cin >> confirm;
			}
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			PTurn = !PTurn; //Update PTurn to move onto the next player and allow them to place their ships or start gameplay.
			std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
			std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    	}
    	std::cout << "\nGame end: Player " << PTurn+1 << " wins.\n"; //If we exited the while loop, one of the players won, output message indicating win.
}

void Executive::chooseShipLoc(Board* board, int numShips) {//chooseShipLoc function places ships with board pointer and numShips desired as parameters.
	char confirm;
	std::string shipLoc = ""; //Initializes shipLoc to empty string.
	int row = 0; //Initializes row integer to 0.
	int col = 0; //Initializes column integer to 0.
	char column; //Char variable representing column.
	char direction; //Char variable representing ship direction (orientation).
	bool inserted = false; //Boolean variable keeps track of whether the ship was inserted, initialized to false.
	for (int i = 0; i < numShips; i++) { //For loop traverses desired number of ships.
        	while (!inserted) { //While loop continues while the ship has not been inserted successfully.
          		std::cout << "Player " << PTurn+1 << ", Input a location for ship " << i+1 << ": "; //Message directs current player to insert their ship.
          		shipLoc = validateLoc(shipLoc); //Validate ship location.
		  		if(shipLoc.length() ==3) { //This code is necessary to validate if player wants to insert in row 10.
			  		row = 9;
			  		column = tolower(shipLoc[2]);
			  		col = charToInt(column);
		  		} else { //Valdiating ship location if in rows 1 to 9.
			  		row = (int)shipLoc[0] - 49;
			  		column = tolower(shipLoc[1]);
			  		col = charToInt(column);
		  		}
		  		if (i == 0) {
					direction = 'H'; //If i=0, the first ship is being entered and a direction is not necessary.
				} else { //Else have user input if they want the ship oriented horizontally or vertically.
			  		std::cout << "Input a direction ('H' for horizontal or 'V' for vertical): ";
			  		direction = validateDirection(direction); //Make sure ship location is still valid with desired orientation.
		  		}
          			if (!board->insertShip(i+1, row, col, direction)) { //If you cannot insert at desired location/orientation, user has to try again.
            				std::cout << "Error - Invalid Location : Ship already exists here or extends outside board. Try again\n"; //Error message.
          			} else {
           				inserted = true; //Else, ship was inserted at desired location/orientation successfully!
					board->printBoard("Place"); //Mark the change on the place board.
          			}
        	} //Closes out while loop.
        inserted = false;
	} //Closes out for loop.
	std::cout << "Press the Y key to confirm player switch: ";
	std::cin >> confirm;
	while (std::cin.fail() || (confirm != 'Y' && confirm != 'y')) { //While innapropriate input occurs...
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Utilize cin.fail and output error message, need correct input to continue.
		std::cout << "Invalid Input - Press the Y key to confirm player switch: ";
		std::cin >> confirm;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	PTurn = !PTurn; //Update PTurn to move onto the next player and allow them to place their ships or start gameplay.
	std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

int Executive::charToInt(char c) { //charToInt takes in a character and converts that to the ASCII correlated integer value.
	int colNum = (int)c; //Set colNum variable equal to (int)c.
	colNum -= 97; //ASCII (a-j) is equal to 97 to 107, so subtract off 97 to convert to correct integer value.
	return colNum; //Return colNum integer value.
}

bool Executive :: inputChecks(std::string input)
{
	bool restrictLength = 0; //Boolean value restrictLength initialized to zero (false).
	bool invalidFormat = 0; //Boolean value invalidFormat intitialized to zero (false).
	bool validChar = 0; //Boolean value validChar initialized to zero (false).
	if(input.length() < 2 || input.length() > 3) restrictLength = 1; //Restrict the length to strings of 2 or 3.
	if(input.length() == 2) //i.e. 1 digit followed by 1 letter.
	{
		if(!isdigit(input[0]) || isdigit(input[1])) invalidFormat = 1;
		if(charToInt(input[1]) >= 0 && charToInt(input[1]) < 10) validChar = 1; //Validate lowercase char case.
		else if(charToInt(input[1]) > -33 && charToInt(input[1]) < -22) validChar = 1; //Validate uppercase char case.
	}
	else if(input.length() == 3) //i.e. 2 digit followed by 1 letter.
	{
		int firstNum = input[0]; //If the first digit is 1, this will have an ASCII of 48
		int secondNum = input[1]; //If the first digit is 1, this will have an ASCII of 49
		if(!isdigit(input[0]) || !isdigit(input[1]) || isdigit(input[2]) || (firstNum != 49 || secondNum != 48)) invalidFormat = 1;
		if(charToInt(input[2]) >= 0 && charToInt(input[2]) < 10) validChar = 1; //Validate lowercase char case.
		else if(charToInt(input[2]) > -33 && charToInt(input[2]) < -22) validChar = 1; //Validate uppercase char case.
	}
	if(restrictLength || invalidFormat || !validChar) return 1;
	else return 0;
}

std::string Executive::validateLoc(std::string input) { //Collects user input for string and ensures it is a valid entry, i.e. follow row-column format.
	std::cin >> input; //Collect user input.
	bool inValid = inputChecks(input);
	while (std::cin.fail() || inValid) { //While innapropriate input occurs...
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Utilize cin.fail and output error message, need correct input to continue.
		if (inValid)
		{
			std::cout << "Your input should specify the row and then column, i.e. 1a. Try again: ";
		}
		std::cin >> input; //input = validateLoc(input);
		inValid = inputChecks(input);
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return input; //Return std::string input that has been validated.
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
