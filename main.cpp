/*********************************************************************
** Program name:  main.cpp
** Author:        Justin Lin
** Date:          04/05/2019
** Description:   This is the main program for the Langton's Ant project.
 *                This program combines all of the functions and classes
 *                together to run a complete Langton's ant simulation.
 *                The program starts by using the menu function to
 *                introduce the game and prompt if the user wants to play.
 *                The program will loop until the user decides to quit the game.
 *                If the user decides to play, a prompt for the EXTRA CREDIT
 *                option will appear asking if the user wants to use a random
 *                starting location for the ant coordinates. There will be a
 *                series of prompts to get the user input for board
 *                specifications, number of steps to run the simulation for,
 *                and ant information if necessary. The inputs are all run
 *                through the integerValidation function, and in a loop with
 *                the inBounds function to validate input. If the user picked
 *                the random ant option, The program uses current time to
 *                seed the built-in rand function to generate the ant's starting
 *                location. After all input is obtained, a dynamically allocated
 *                2D array will be created and used to create Board and Ant
 *                objects. The program then will use these objects and loop
 *                through each step of the simulation printing the board,
 *                current step count, ant location, and ant direction. Once
 *                the last step of the simulation is reached, the dynamically
 *                allocated memory is deleted, and the user is asked if they
 *                want to play again.
*********************************************************************/
#include "menu.h"
#include "Board.h"
#include "Ant.h"
#include "printBoard.h"
#include "integerValidation.h"
#include "inBounds.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main() {

    //  Constants used for keeping inputs in bounds
    const int BOARD_MIN = 5,
              BOARD_MAX = 100,
              MIN_STEPS = 0,
              MAX_STEPS = 25000;

    //  Variables to store user inputs
    int numRows = 0,
        numCols = 0,
        numSteps = 0,
        startRow = 0,
        startCol = 0,
        direction = 0,
        menuChoice = 0,
        stepCounter = 0,
        useRandom = 0;

    //  Unsigned used to hold positive int for random seed
    unsigned seed;

    char **array = nullptr;

    //  Prints banner of project title
    cout << "****************************************************************" << endl;
    cout << "*     Langton's Ant Project (EXTRA CREDIT OPTION INCLUDED)     *" << endl;
    cout << "****************************************************************" << endl;

    //  Prompts
    cout << "Please select an option:" << endl;
    cout << "1. Start Langton's Ant Simulation" << endl;
    cout << "2. Quit" << endl;
    //  Uses menu function to get validated user input.
    menuChoice = menu();

    //  If user chooses to play, prompts for input
    while (menuChoice == 1) {

        //  Get validated starting parameter input from user
        //  EC: Choice for random ant starting location
        cout << "EXTRA CREDIT: Would you like to use a random starting "
             << "location for the ant?" << endl;
        cout << "1. Use random location" << endl;
        cout << "2. Choose ant location" << endl;

        useRandom = integerValidation();
        while (!inBounds(useRandom, 1, 2)) {
            useRandom = integerValidation();
        }
        cout << "How many rows would you like the board to have?" << endl;
        cout << "Please enter an integer between " << BOARD_MIN << " and "
             << BOARD_MAX << endl;

        numRows = integerValidation();
        while (!inBounds(numRows, BOARD_MIN, BOARD_MAX)) {
            numRows = integerValidation();
        }

        cout << "How many columns would you like the board to have?" << endl;
        cout << "Please enter an integer between " << BOARD_MIN << " and "
             << BOARD_MAX << endl;

        numCols = integerValidation();
        while (!inBounds(numCols, BOARD_MIN, BOARD_MAX)) {
            numCols = integerValidation();
        }

        cout << "How many steps do you want the simulation to run for?" << endl;
        cout << "Please enter an integer between " << MIN_STEPS << " and "
             << MAX_STEPS << endl;

        numSteps = integerValidation();
        while (!inBounds(numSteps, MIN_STEPS, MAX_STEPS)) {
            numSteps = integerValidation();
        }

        //  Checks to see if user picked random starting location
        if (useRandom == 1) {
            //  Uses time to create a seed.
            seed = time(0);
            srand(seed);

            //  Modulo used to limit range to be 0 through number of rows/cols
            startRow = rand() % numRows;
            startCol = rand() % numCols;

        }
        //  Prompts user for ant starting coordinates if random option
        //  is not chosen.
        else {
            cout << "What is the starting row of the Ant?" << endl;

            startRow = integerValidation();
            while (!inBounds(startRow, 0, numRows - 1)) {
                startRow = integerValidation();
            }

            cout << "What is the starting column of the Ant?" << endl;
            startCol = integerValidation();
            while (!inBounds(startCol, 0, numCols - 1)) {
                startCol = integerValidation();
            }
        }

        cout << "What direction is the Ant facing?" << endl;
        cout << "Please choose an option: " << endl;
        cout << "1. North" << endl;
        cout << "2. East" << endl;
        cout << "3. South" << endl;
        cout << "4. West" << endl;

        direction = integerValidation();
        while (!inBounds(direction, 1, 4)) {
            direction = integerValidation();
        }

        //  Dynamically allocate 2D array for board and fill with white spaces.
        array = new char *[numRows];
        for (int row = 0; row < numRows; row++) {
            array[row] = new char[numCols];
            for (int col = 0; col < numCols; col++) {
                array[row][col] = ' ';
            }
        }
        //  Create board and ant objects using user entered variables
        Board *boardPtr = new Board(array, numRows, numCols);
        Ant ant(boardPtr, startRow, startCol, direction);

        //  Runs Langton's Ant for user specified steps.
        while (stepCounter <= numSteps) {
            //  Step counter begins with 0, so user can see empty board with ant
            cout << "Step " << stepCounter << " out of " << numSteps << endl;

            //  Checks if ant is in bounds. Will wrap the ant to opposite side
            //  if ant is out of bounds.
            if (boardPtr->checkBounds(ant.getAntRow(), ant.getAntCol())) {
                ant.wallWrap();
            }

            //  Prints the board with ant's current location replacing the
            //  square color.
            printBoard(boardPtr, ant);
            cout << "Ant facing: " << ant.getOrientation() << endl;
            cout << "Ant location: " << ant.getAntRow() << " " << ant.getAntCol() << endl;

            //  Changes orientation of ant based on current square color
            ant.changeOrientation();

            //  Flips color of current square ant is on
            boardPtr->changeColor(ant.getAntRow(), ant.getAntCol());

            //  Move ant forward one square in whatever direction it is facing
            ant.moveAnt();
            stepCounter++;
        }

        //  Deallocate memory
        delete boardPtr;
        for (int row = 0; row < numRows; row++) {
            delete[] array[row];
        }
        delete[] array;

        //  Reset steps so user can play again
        stepCounter = 0;

        //  Pulls menu up again, so program runs until user quits.
        cout << "Please select an option:" << endl;
        cout << "1. Play again" << endl;
        cout << "2. Quit" << endl;
        menuChoice = menu();
    }
    //  Quit choice
    if (menuChoice == 2) {
        return 0;
    }
}