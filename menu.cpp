//
// Created by Justin Lin on 2019-04-05.
//
/*********************************************************************
** Program name:  menu.cpp
** Author:        Justin Lin
** Date:          04/05/2019
** Description:   This is the implementation file for the menu function.
 *                The function is a modular menu that is reusable in
 *                future programs with minor modifications. The function
 *                prints a banner at the top with the type of a project,
 *                prompts the user for a selection, and uses the
 *                integerValidation function to verify input. The function
 *                then uses a switch statement to return the user's choice.
 *                To reuse this function, the only thing that needs to be
 *                changed are the print statements, validation if you need
 *                an input that is not an integer, and number of options.
*********************************************************************/

#include "menu.h"
#include "integerValidation.h"
#include "inBounds.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int menu() {

    int choice = 0;

    //  Repeatedly prompts user for selection until valid choice is made.
    choice = integerValidation();
    while (!inBounds(choice, 1, 2)) {
        choice = integerValidation();
    }

    //  Verification prompts
    switch (choice) {
        case 1: cout << "You selected: 1. Start Langton's Ant" << endl;
                return 1;
        case 2: cout << "You selected 2: Quit. Goodbye!" << endl;
                return 2;
    }
}
