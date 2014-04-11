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
// Test includes
#include "Number.h"
#include "Constant.h"
#include "Integer.h"
#include "Radical.h"
// End test includes

using namespace std;

// Define all functions used in the main
void printMenu();

// For testing purposes only.
// TODO: Replace with actual expression testing once the calulator is implemented
void tests();
void rational_test();

int main(int argc, const char * argv[])
{
	// If the third arg is test, run the tests. Note that strcmp == 0 if true.
	if ( argc > 1 && !strcmp(argv[1], "test") )
	{
		tests();
	}

	// a test for creating and simplifying rationals
	if( argc > 1 && !strcmp(argv[1] , "rational"))
	{
		rational_test();
	}
	
	else {
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
	string userInput; //should it be declared here or elsewhere?
	bool menuLoop = true;
	//TODO: Print second part of menu and pass input to parser
	//      Throw errors for bad input
	while(menuLoop != false || menuLoop != false)
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
		if(userInput == "Q" || userInput == "q")
		{
			menuLoop = false;
		}
		// check for correct input
		cout << "################################################################################" << endl;
		cout << "## Continuing...							      ##" << endl;
		cout << "##                                                                            ##" << endl;
		cout << "## Please enter your expression below, or 'q' to quit: 			      ##" << endl;
		cin >> userInput;
		if(userInput == "Q" || userInput == "q")
		{
			menuLoop = false;
		}
	}
	// Test that exit works
	//cout << "Exiting" << endl;
	// Works!
}


/**
 * A function used to run some tests for expected and unexpected behavior
 * Should be removed and replaced with a better testing system, time permitting.
 */
void tests()
{
	//TODO: Write some tests
	cout << "Running tests:" << endl;
	
	cout << "Running overloaded addition test:" << endl;
	cout << "Creating a Constant" << endl;
	Constant myconst = Constant("pi");
	
	cout << "Creating an Integer" << endl;
	Integer myint = Integer();
	
	cout << "Creating a Radical" << endl;
	Radical myrad = Radical();
	
	cout << "Creating a Log (Not overloaded yet)" << endl;
	Log mylog = Log();
	
	cout << "Adding an Integer" << endl;
	myconst.add(myint);
	
	cout << "Adding a Radical" << endl;
	myconst.add(myrad);
	
	cout << "Adding a Log" << endl;
	myconst.add(mylog);

	cout << "Integer tests" << endl;
	cout << "Adding a constant (generic Number)" << endl;
	myint.add(myconst);

	cout << "Adding an Integer" << endl;
	myint.add(myint);

	cout << "Subtracting a Radical (generic Number)" << endl;
	myint.subtract(myrad);

	cout << "Subtracting an Integer" << endl;
	myint.subtract(myint);

	cout << "Multiplying a Radical (generic Number)" << endl;
	myint.multiply(myrad);

	cout << "Multiplying an Integer" << endl;
	myint.multiply(myint);

	cout << "Dividing a Radical (generic Number)" << endl;
	myint.divide(myrad);

	cout << "Dividing an Integer" << endl;
	myint.divide(myint);

		
}

void rational_test()
{
	int num , den;
	cout << "Enter numerator: " <<endl;
	cin >> num;

	cout << "Enter denominator: " <<endl;
	cin >> den;	

	cout << "Creating Rational" <<endl;
	Rational *r = new Rational(num,den);
	cout << "Numerator: " << r->getNum() <<endl;
	cout << "Denominator: " << r->getDen() << endl;
	cout << "GCD: " << r->gcd(r->getNum() , r->getDen()) << endl;
	cout << "Simplifying" <<endl;
	r->simplify();
	cout << "Numerator: " << r->getNum() <<endl;
	cout << "Denominator: " << r->getDen() << endl;

	Rational *a = new Rational(1,2);
	r->add(*a);
	delete r;
}
