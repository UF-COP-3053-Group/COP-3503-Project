//
//  main.cpp
//  COP-3503-Project
//
//  Created by Justin on 4/9/14.
//
//
#include <stdexcept>
#include <iostream>
#include <string.h>
#include "Calculator.h"

// Test includes


// End test includes

using namespace std;

// Define all functions used in the main
void printMenu();

// For testing purposes only.
// TODO: Replace with actual expression testing once the calulator is implemented
void tests();


int main(int argc, const char * argv[])
{
	tests();
	
	// If the third arg is test, run the tests. Note that strcmp == 0 if true.
	if ( argc > 1 && !strcmp(argv[1], "test") )
	{
		tests();
		return 0;
	}
	else
	{

		printMenu(); // Default behavior
	}

	// TODO: Everything
}

/**
 * Prints a menu to stdout
 * The code isn't super sexy or using lots of escape characters,
 * but it works and everything is lined up, at least on Ubuntu.
 * None of the expressions are set in stone, let me know
 * if they need to be changed. - Kyle
 */
void printMenu()
{
	Calculator myCalc = Calculator();
	string userInput;
	string userInput2;
	bool menuLoop = true;
	//TODO: Print second part of menu and pass input to parser
	//      Throw errors for bad input
	while(menuLoop != false)
	{
		cout << "################################################################################" << endl;
		cout << "################################################################################" << endl;
		cout << "## Welcome to The Best Calculator You Will Ever Use 			      ##" << endl;
		cout << "## (TBCYWEU, pronounced TibKeyWoo)  					      ##" << endl;
		cout << "## The following operators are allowed:                                       ##" << endl;
		cout << "## + add 								      ##" << endl;
		cout << "## - subtract							      	      ##" << endl;
		cout << "## * multiply								      ##" << endl;
		cout << "## / divide 								      ##" << endl;
		cout << "##                              					      ##" << endl;
		cout << "##                                                                            ##" << endl;
		cout << "## The following expressions are allowed: 				      ##" << endl;
		cout << "## e - Euler's number							      ##" << endl;
		cout << "## pi - 3.141592653589793238462643383279502884197136939937510582097494	      ##" << endl;
		cout << "## log - logarithm. Example: log3(3) - log base 3 of 3			      ##" << endl;
		cout << "## rad - radical. Example: rad3(9) - cubic root of 9			      ##" << endl;
		cout << "## ^ - exponent. Example 2^3 - 2 to the power of 3			      ##" << endl;
		cout << "## () - Grouping							      ##" << endl;
		cout << "##									      ##" << endl;
		cout << "################################################################################" << endl;
		cout << "################################################################################" << endl;
		cout << endl;
		cout << "Press 'q' to quit or 'c' to continue: " << endl;
		cin >> userInput;
		if(userInput == "Q" || userInput == "q")  //this stopped working...
		{
			menuLoop = false;
		}
		// check for correct input
		else
		{
		cout << "################################################################################" << endl;
		cout << "## Continuing...							      ##" << endl;
		cout << "##                                                                            ##" << endl;
		cout << "## Please enter your expression below, or 'q' to quit: 			      ##" << endl;
		cin >> userInput;
		if(userInput == "Q" || userInput == "q")
		{
			menuLoop = false;
		}
		// can't implement below yet, because calculate doesn't return anything.
		else {
		myCalc.calculate(userInput);
 // needs toString method from Calculator to convert Expression to String
 //		display answer
		cout << "Continue? y/n:" << endl;
		cin >> userInput2;
		if (userInput2 == "n" || userInput2 == "N")
		{
			menuLoop = false;
		}
		else if(userInput2 != "y" || userInput2 != "Y") {
			//throw some error, try again
//			throw
			cout << "yes just because " << endl;
		}
		}
	}
	}
	// Test that exit works
	//cout << "Exiting" << endl;
	// Works!
}

/****************************************************
 *
 * All below functions are for testing purposes only
 *
 ****************************************************/

/**
 * A function used to run some tests for expected and unexpected behavior
 * Should be removed and replaced with a better testing system, time permitting.
 */
void tests()
{
	//TODO: Write some tests
	cout << "Running tests:" << endl;
	
	Calculator calc = Calculator();
	calc.calculate("2 + 5 * 3");
		
}




