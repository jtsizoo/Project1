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
    PTurn = false; //Variable PTurn keeps track of which player's turn it is, starts at false so Player 1 will go first when gameplay begins.
    p1Board = new Board(m_size); //Creates instance of Board class for Player 1, takes in m_size and name "Player 1" as parameters.
    p2Board = new Board(m_size); //Creates instance of Board class for Player 2, take in m_size and name "Player 2" as parameters.
    chooseShipLoc(p1Board, numShips); //Player 1 places their ships on their board w/ selected number of ships.
    chooseShipLoc(p2Board, numShips); //Player 2 places their ships on their board w/ selected number of ships.
}

Executive::~Executive() { //Destructor for the Executive class.
    delete p1Board; //Deletes instance of Board class associated with Player 1.
    delete p2Board; //Deletes instance of Board class associated with Player 2.
}

void Executive::run() { //Void run function enables all gameplay functionality.

}

void Executive::chooseShipLoc(Board* board, int numShips) { //chooseShipLoc function places ships with board pointer and numShips desired as parameters.

}
