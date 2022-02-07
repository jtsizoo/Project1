/*-------------------------------------------------------
 * 	File Name: Executive.h
 * 	Authors: Alice Kuang, Thresa Kelly, Minwood Lee, Justin Sizoo, Maggie Swartz (Group #14)
 * 	Assignment: EECS_448 Project #1
 * 	Description: This is the header file for the Executive class
 * 	Date Last Modified: 02/06/2022
 *-----------------------------------------------------*/

#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <iostream>
#include <string>
#include "Board.h"

class Executive {
    private:
    int m_size;
    Board* p1Board;
    Board* p2Board;
    bool PTurn;

    public:
    /*----------
     * @pre
     * @post
     * @param
     * @return
     * -------*/
    Executive(int numShips);
     /*----------
     * @pre
     * @post
     * @param
     * @return
     * -------*/
    ~Executive();
     /*----------
     * @pre
     * @post
     * @param
     * @return
     * -------*/
    void chooseShipLoc(Board* board, int numShips);
     /*----------
     * @pre
     * @post
     * @param
     * @return
     * -------*/
    void run();
     /*----------
     * @pre
     * @post
     * @param
     * @return
     * -------*/
    int charToInt(char c);
     /*----------
     * @pre
     * @post
     * @param
     * @return
     * -------*/
    std::string validateLoc(std::string input);
     /*----------
     * @pre
     * @post
     * @param
     * @return
     * -------*/
    char validateDirection(char input);
};

#endif
