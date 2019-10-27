//
// Created by Justin Lin on 2019-04-08.
//
/*********************************************************************
** Program name:  printBoard.cpp
** Author:        Justin Lin
** Date:          04/08/2019
** Description:   This is the implementation file for the printBoard function.
 *                The function takes in as parameters a pointer to a board
 *                object, as well as an ant object. The function uses loops
 *                to print the entire Board object with borders around the
 *                outer edge of the board. At the current location of the ant,
 *                the board will print out a '*' symbol instead of the color
 *                of that space.
*********************************************************************/
#include "printBoard.h"
#include <iostream>
using std::cout;
using std::endl;

void printBoard(Board *antBoard, Ant ant) {
    //  Prints top border
    cout << " ";
    for (int col = 0; col < antBoard->getColSize(); col++) {
        cout << "_";
    }
    cout << endl;

    //  Prints board with left and right borders
    for (int row = 0; row < antBoard->getRowSize(); row++) {
        cout << "|";

        //  Prints '*' at current ant location, otherwise will print
        //  current state of board
        for (int col = 0; col < antBoard->getColSize(); col++) {
            if ((ant.getAntRow() == row) && (ant.getAntCol() == col)) {
                cout << "*";
            }
            else {
                cout << antBoard->getColor(row, col);
            }
        }
        cout << "|" << endl;
    }

    //  Prints bottom border
    cout << " ";
    for (int col = 0; col < antBoard->getColSize(); col++) {
        cout << "-";
    }
    cout << endl;
}