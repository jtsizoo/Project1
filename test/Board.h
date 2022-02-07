/*-------------------------------------------------------
 *      File Name: Board.h
 *      Authors: Alice Kuang, Thresa Kelly, Minwood Lee, Justin Sizoo, Maggie Swartz (Group #14)
 *      Assignment: EECS_448 Project #1
 *      Description: This is the header file for the Board class
 *      Date Last Modified: 02/06/2022
 *-----------------------------------------------------*/

#ifndef BOARD_H
#define BOARD_H

#include <iostream>

class Board {
	private:
	std::string player;
	int m_size;
	char** placeGrid;
	char** shotGrid;
	int printCol[10] = {1,2,3,4,5,6,7,8,9,10};
	char printRow[10] = {'A','B','C','D','E','F','G','H','I','J'};
	
	public:
	/*----------
     	* @pre
     	* @post
     	* @param
     	* @return
     	* -------*/
	Board(int size, std::string playerNum);
	/*----------
        * @pre
        * @post
        * @param
        * @return
        * -------*/
	~Board();
	/*----------
        * @pre
        * @post
        * @param
        * @return
        * -------*/
	bool insertShip(int size, int row, int col, char dir);
	/*----------
        * @pre
        * @post
        * @param
        * @return
        * -------*/
	bool shootShot(int row, int col, Board* opBoard);
	/*----------
        * @pre
        * @post
        * @param
        * @return
        * -------*/
	bool isHit(int row, int col);
	/*----------
        * @pre
        * @post
        * @param
        * @return
        * -------*/
	bool checkWin();
	/*----------
        * @pre
        * @post
        * @param
        * @return
        * -------*/
	void printShotGrid();
	/*----------
        * @pre
        * @post
        * @param
        * @return
        * -------*/
	void printPlaceGrid();
	/*----------
        * @pre
        * @post
        * @param
        * @return
        * -------*/
	void printInitialBoard();
};

#endif
