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
		return 0;
	}

	// a test for creating and simplifying rationals
	if( argc > 1 && !strcmp(argv[1] , "rational"))
	{
		rational_test();
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
		if(userInput == "Q" || userInput == "q")  //this stopped working...
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
	
	cout << "Creating an empty Integer and 'real' Integer" << endl;
	Integer myint = Integer();
	Integer myint2 = Integer(5);
	
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

	cout << "Adding an actual Integer" << endl;
	myint2.add(myint2);


	cout << "Subtracting a Radical (generic Number)" << endl;
	myint.subtract(myrad);

	cout << "Subtracting an Integer" << endl;
	myint2.subtract(myint2);

	cout << "Multiplying a Radical (generic Number)" << endl;
	myint.multiply(myrad);

	cout << "Multiplying an Integer" << endl;
	myint2.multiply(myint2);

	cout << "Dividing a Radical (generic Number)" << endl;
	myint.divide(myrad);

	cout << "Dividing an Integer" << endl;
	myint2.divide(myint2);

		
}

void rational_test()
{
	int num , den;
	char response;
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

	cout << "Would you like to test addition? (y/n)" << endl;
	cin >> response;
	if(response == 'y')	
	{
		int _num , _den;
		cout << "Enter numerator" <<endl;
		cin >> _num;
		cout << "Enter denominator" << endl;
		cin >> _den;
		Rational *a = new Rational(_num,_den);
		r->add(*a);
		delete a;

		
	}

	cout << "Would you like to test subtraction? (y/n)" << endl;	
	cin >> response;
	if(response == 'y')
	{
		int _num , _den;
		cout << "Enter numerator: " <<endl;
		cin >> _num;	
		cout << "Enter denominator: " <<endl;
		cin >> _den;
		Rational *a = new Rational(_num , _den);
		r->subtract(*a);
		delete a;

	}
	cout << "Would you like to test multiplication?" <<endl;
	cin >> response; 

	if(response == 'y')
	{
		int _num , _den;
		cout << "Enter numerator: " <<endl;
		cin >> _num;	
		cout << "Enter denominator: " <<endl;
		cin >> _den;
		Rational *a = new Rational(_num , _den);
		r->multiply(*a);
		delete a;

	}

	cout << "Would you like to test division?" << endl;
	cin >> response;	
	if(response == 'y')
	{
		int _num , _den;
		cout << "Enter numerator: " <<endl;
		cin >> _num;	
		cout << "Enter denominator: " <<endl;
		cin >> _den;
		Rational *a = new Rational(_num , _den);
		r->divide(*a);
		delete a;

	}


	delete r;
}









