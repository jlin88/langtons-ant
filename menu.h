/*********************************************************************
** Program name:  menu.h
** Author:        Justin Lin
** Date:          04/05/2019
** Description:   This is the header file for the menu function.
 *                The function is a modular menu that is reusable in
 *                future programs with minor modifications. The function
 *                prints a banner at the top with the type of a project,
 *                prompts the user for a selection, and uses the
 *                integerValidation function to verify input. The function
 *                then uses a switch statement to return the user's choice.
 *                To reuse this function, the only thing that needs to be
 *                changed are the print statements, validation if you need
 *                an input that is not an integer, and number of options.
 *                This function is called in the main program and the ints
 *                returned are used as part of conditionals.
*********************************************************************/

#ifndef MENU_H
#define MENU_H

int menu();

#endif //MENU_H
