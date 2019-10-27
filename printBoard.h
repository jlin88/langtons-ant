//
// Created by Justin Lin on 2019-04-08.
//
/*********************************************************************
** Program name:  printBoard.h
** Author:        Justin Lin
** Date:          04/08/2019
** Description:   This is the header file for the printBoard function.
 *                The function takes in as parameters a pointer to a board
 *                object, as well as an ant object. The function uses loops
 *                to print the entire Board object with borders around the
 *                outer edge of the board. At the current location of the ant,
 *                the board will print out a '*' symbol instead of the color
 *                of that space. This is called in the main function to
 *                show the state of the board at every step of the ant.
*********************************************************************/

#ifndef PRINTBOARD_H
#define PRINTBOARD_H
#include "Board.h"
#include "Ant.h"

void printBoard(Board *antBoard, Ant ant);

#endif // PRINTBOARD_H
