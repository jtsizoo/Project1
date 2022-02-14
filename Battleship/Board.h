/*-------------------------------------------------------
 *      File Name: Board.h
 *      Authors: Alice Kuang, Thresa Kelly, Minwoo Lee, Justin Sizoo, Maggie Swartz (Group #14)
 *      Assignment: EECS_448 Project #1
 *      Description: This is the header file for the Board class
 *      Date Last Modified: 02/13/2022
 *-----------------------------------------------------*/

#ifndef BOARD_H
#define BOARD_H

#include <iostream>

class Board {
private:
    std::string player; //std::string representing player name
    int m_size; //member variable m_size, representing size of board
    char** initialGrid; //2D array of characters, representing initialGrid (the resulting grid after player places their own battleships)
    char** placeGrid; //2D array of characters, representing placeGrid (where a player places their own battleships)
    char** shotGrid; //2D array of characters, representing shotGrid (where a player tries to hit opponent's battleships and records results)
    int printCol[10] = { 1,2,3,4,5,6,7,8,9,10 }; //Array of integers, of size 10, filled w/ headers for column positions.
    char printRow[10] = { 'A','B','C','D','E','F','G','H','I','J' }; //Array of characters, of size 10, filled w/ headers for row positions.

public:
    /*----------
        * @pre int size must be 10x10, playerNum must be a string (will just be Player 1 or Player 2)
        * @post constructor for the Board class, an instance of board class is created
        * @param integer size - size of ship, and std::string playerNum - representing name of player
        * @return an instance of the Board class
        * -------*/
    Board(int size, std::string playerNum);

    /*----------
        * @pre an instance of Board class must exist to be deleted
        * @post destructor - Board class instance is deleted
        * @param none
        * @return none, just deletion of Board instance
        * -------*/
    ~Board();

    /*----------
        * @pre position where player desires insertion must be currently empty
        * @post inserts ship at desired location on placeGrid
        * @param row/col represent x/y location, size is size of ship to be inserted, dir char is V or H representing vertical or horizontal
        * @return boolean value T or F, whether a ship can be inserted at the desired location w/ the desired orientation
        * -------*/
    bool insertShip(int size, int row, int col, char dir);

    /*----------
    * @pre insertShip method was successfully called
    * @post returns a bool status of whether there will be a collision with another ship if placed at that location and orientation
    * @param row/col represent x/y location, size is size of ship to be inserted, dir char is V or H representing vertical or horizontal
    * @return boolean value T or F, whether a collision will occur
    * -------*/
    bool noCollisions(int size, int row, int col, char dir);

    /*----------
        * @pre both player's must have already placed their ships in their own placeGrid
        * @post returns T/F value for whether a shot occurred and updates shotGrid
        * @param row/col represent x/y location where shot is taking place, Board* pointer references oppoent's board
        * @return boolean value T or F, representing whether or not a shot occurred at the given location
        * -------*/
    bool shootShot(int row, int col, Board* opBoard);

    /*----------
        * @pre shootShot function returned true since a ship was hit
        * @post returns T/F value for whether a given length ship was entirely sunk
        * @param row/col represents x/y location of the ship
        * @return boolean value T or F, respresenting whether a ship was sunk
        * -------*/
    bool sinkStatus(int row, int col);

    /*----------
        * @pre shootShot function must have already ran
        * @post returns T/F value for whether a hit occurred at the location and updates corresponding grids accordingly
        * @param row/col represents x/y location where checking to see if a hit occurred
        * @return boolean value T or F, respresenting whether a hit occurred
        * -------*/
    bool isHit(int row, int col);

    /*----------
        * @pre gameplay must have already begun
        * @post returns T/F for whether any ships remain that need to be hit
        * @param none
        * @return boolean value T or F, indicating if player has won game yet or not (if yes, gameplay will stop)
        * -------*/
    bool checkWin();

    /*----------
        * @pre none
        * @post prints the grid of the specified boardType
        * @param string specifying the boardType (initialGrid, placeGrid, or shotGrid)
        * @return none - void function
        * -------*/
    void printBoard(std::string boardType);

    /*----------
        * @pre gameplay must have already begun
        * @post returns T/F if shot loc invalid
        * @param row and col
        * @return boolean value T or F
        * -------*/
    bool validShot(int row, int col);
};

#endif
