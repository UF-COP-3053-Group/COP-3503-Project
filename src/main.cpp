//
//  main.cpp
//  COP-3503-Project
//
//  Created by Justin on 4/9/14.
//
//

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

int main(int argc, const char * argv[])
{
	// If the third arg is test, run the tests. Note that strcmp == 0 if true.
	if ( argc > 1 && !strcmp(argv[1], "test") )
	{
		tests();
	}
	
	// TODO: Everything
}

/**
 * Prints a menu to stdout
 */
void printMenu()
{
	//TODO: Make it print a menu. Duh.
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
}
