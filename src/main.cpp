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
#include <stdlib.h>
#include <fstream>

// Test includes


// End test includes

using namespace std;

// Define all functions used in the main
void printMenu();
void altMenu();
void displayHelp();
void rational_test();
void gui();
void parse();
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

	if(argc >  1 && !strcmp(argv[1] , "rational"))	
	{
		rational_test();
		return 0;
	
	}

	if(argc > 1 && !strcmp(argv[1] , "gui"))
	{
		gui();
		return 0;
	}

	if(argc > 1 && !strcmp(argv[1] , "parse"))
	{	
		parse();
		return 0;	
		
	}
	// Try the altMenu, as it's simpler for testing
	altMenu();
	
	// From here, hand control off to the menu.
	//printMenu(); // Default behavior

}

void gui()
{
	//WARNING: violating all good coding principles here

	system("./test2");

}

void parse()
{
	Calculator calc = Calculator(); 
	ifstream myfile("Writefile.txt");
	string input = "";
	if(myfile.good())
		getline(myfile, input);
	ofstream outFile;
	outFile.open("Outfile.txt");

	outFile << calc.toString( calc.calculate(input) );	
	outFile.close();
	cout <<"done"<<endl;
	return;
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
	string userInput;
	string userInput2;
	Calculator myCalc = Calculator();
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
		cout << "## ans - Use previous answer                      ##" << endl;  //check the layout
		cout << "##									      ##" << endl;
		cout << "## IMPORTANT NOTE: Please insert a space between every term!		      ##" << endl;
		cout << "##									      ##" << endl;
		cout << "################################################################################" << endl;
		cout << "################################################################################" << endl;
		cout << endl;
		cout << "Please choose one of the following options: (N)ew expression, (H)elp, (R)eview, (Q)uit " << endl;
		cin >> userInput;
		if(userInput == "Q" || userInput == "q")
		{
			menuLoop = false;
		}
		// check for correct input
		else if(userInput =="c" || userInput == "C")
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

		else if(userInput == "H" || userInput == "h") {
			cout << "################################################################################" << endl;
			cout << "################################################################################" << endl;
			cout << "##  Welcome to TBCYWEU's help menu! This is a restatement of the intro        ##" << endl;
			cout << "##  dialog showing the proper use of the various supported expressions        ##" << endl;
			cout << "##									      ##" << endl;
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
			cout << "## ans - Use previous answer                      ##" << endl;  //check the layout
			cout << "##									      ##" << endl;
			cout << "## IMPORTANT NOTE: Please insert a space between every term!		      ##" << endl;
			cout << "##									      ##" << endl;
			cout << "################################################################################" << endl;
			cout << "################################################################################" << endl;
			cout << endl;
			cout << "(C)ontinue or (Q)uit?" << endl;
			cin >> userInput;
			if(userInput == "C" || userInput == "c") {
				menuLoop = true;
			}
			else if(userInput == "Q" || userInput == "q")
			{
				menuLoop = false;
			}
			else {
				throw logic_error("Incorrect input!"); //do something
				cout << "(C)ontinue or (Q)uit? " << endl;
				cin >> userInput;
				if(userInput == "Q" || userInput == "q")
				{
					menuLoop = false;
				}
			}

		}

		else if(userInput == "R" || userInput == "r") {
			bool reviewLoop = true;
			string reviewInput;
			int runs = 0;
			while(reviewLoop == true) {
				cout << "################################################################################" << endl;
				cout << "################################################################################" << endl;
				cout << "##  Review previous answers? Y/N						      ##" << endl;
				cout << "##                                                                            ##" << endl;
				cout << "## Each run will display the next to last answer 			      ##" << endl;
				cin >> reviewInput;
				if(reviewInput == "Y" || reviewInput == "y") {
					if(myCalc.getPreviousAnswers().empty()) {
						throw logic_error("No previous answers to show!");
					}
					else{
						cout << "Your last answer was" << *(myCalc.getPreviousAnswers().rbegin() + runs)  << endl; // Goes further back for each run
						runs++;
					}
				}
				else if(reviewInput == "N" || reviewInput == "n") {
					reviewLoop = false;
				}
				else {
					throw logic_error("Incorrect input!");
				}
			}
		}

		else if(userInput == "n" || userInput == "N")
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
				Expression* lastAns = myCalc.calculate(userInput);
				// needs toString method from Calculator to convert Expression to String
				//		display answer
				cout << "Decimal answer: " << myCalc.toDouble(lastAns) << endl;
				cout << "Continue? y/n:" << endl;
				cin >> userInput2;
				if (userInput2 == "n" || userInput2 == "N")
				{
					menuLoop = false;
				}
				else if(userInput2 != "y" || userInput2 != "Y") {
					throw logic_error("Incorrect input!"); //do something
					cout << "Press 'q' to quit or 'c' to continue: " << endl;
					cin >> userInput;
					if(userInput == "Q" || userInput == "q")
					{
						menuLoop = false;
					}
				}
			}
		}
		else {
			throw logic_error("Incorrect input!"); //do something
			cout << "Press 'q' to quit or 'c' to continue: " << endl;
			cin >> userInput;
			if(userInput == "Q" || userInput == "q")
			{
				menuLoop = false;
			}
		}
	}
	
	cout << "Bye!" << endl;
}
}



/**
 * Provides an alternate, simplified menu structure.
 */
void altMenu()
{
	// Store the input in this string
	string input;
	
	// Keep track of the mode we're working in. Simplification mode is the default
	bool doubleMode = false;
	
	// Create a caluclator object
	Calculator calc = Calculator();
	
	cout << "Welcome to The Best Calculator You Will Ever Use." << endl;
	cout << "(TBCYWEU, pronounced TibKeyWoo)" << endl;
	cout << endl;
	cout << "Please enter a space-seperated expression to evaluate.";
	
	// Start input loop
	do
	{
		cout << endl << "Type an expression, 'h' for (h)elp, 'a' to list previous (a)nswers,";
		cout << " 'm' to switch between simplification and double mode, or 'q' to (q)uit." << endl << endl;
		
		cout << "Input: ";
		// Get line, as cin >> input considers spaces as white space
		getline (cin, input);
		
		// Check input
		if (input == "q" || input == "Q")
		{
			// Exit
			break;
		}
		else if (input == "h" || input == "H")
		{
			// Display help
			displayHelp();
		}
		else if (input == "a" || input == "A")
		{
			// Show answers
			cout << calc.getPreviousAnswersAsString();
		}
		else if (input == "m" || input == "M")
		{
			// Switch the mode
			// If the double mode is on, turn it off
			if (doubleMode)
			{
				cout << "Switching to simplification mode" << endl;
				doubleMode = false;
			}
			// Else turn double mode on
			else
			{
				cout << "Switching to double mode" << endl;
				doubleMode = true;
			}
		}
		else if (input == "")
		{
			// If the input is empty, warn the user
			cout << "No really, enter something.";
		}
		else
		{
			// Doesn't match any other cases, so assume it's an expression.
			// Put inside of a try catch in case it isn't readable by the calculator.
			try
			{
				cout << "Answer: ";
				
				// Calculate an answer from the input and print it directly
				if(!doubleMode)
				{
					cout << calc.toString( calc.calculate(input) );
				}
				else
				{
					cout << calc.toDouble( calc.calculate(input) );
				}
				
			}
			catch (invalid_argument)
			{
				cout << "That isn't a supported expression or option!" << endl;
			}
		}
		
	} while (input != "q" || input != "Q");
	
	// Aw, they're leaving! At least say goodbye.
	cout << "Goodbye!" << endl;

}

/**
 * Prints a help menu to std::cout
 */
void displayHelp()
{
	cout << "Welcome to TBCYWEU's help menu!" << endl;
	cout << "The following operations are supported:" << endl;
	cout << " + add" << endl;
	cout << " - subtract" << endl;
	cout << " * multiply" << endl;
	cout << " / divide" << endl;
	cout << " ^ exponentiate" << endl;
	cout << " () grouping" << endl;
	cout << endl;
	cout << "The following functions are allowed:" << endl;
	// TODO: Copied from the old menu. Fix these when they work.
	cout << " log - logarithm. Example: log3(3) - log base 3 of 3" << endl;
	cout << " rad - radical. Example: rad3(8) - cubic root of 8" << endl;
	cout << " ans - Use previous answer" << endl;
	cout << endl;
	cout << "The following constants are supported:" << endl;
	cout << " e - Euler's number							      ##" << endl;
	cout << " pi - 3.14159..." << endl;
	cout << endl;
	cout << "IMPORTANT NOTE: Please insert a space between every term and operation!" << endl;
	cout << "e.g. type '2 + 5 ^ 2 / 5'" << endl;
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
	// Skip the tests right now //
	//////////////////////////////
	return;
	cout << "Running tests:" << endl;

	Calculator calc = Calculator();
	Expression* tree;

	tree = calc.calculate("2 + 2");
	
	double out = calc.toDouble(tree);

	cout << "Out: " << out << endl;

	cout << "TESTS DONE" << endl << endl;

}

void rational_test()
{
	//Make some rationals 
	Rational *r = new Rational(4,6);
	Integer *i1 = new Integer(3);
	Integer *i2 = new Integer(7);

	Rational *r2 = new Rational(i1, i2);

	Calculator calc = Calculator();
	Expression *tree;
	
	tree = calc.calculate("3 / 2");
	string out = calc.toString(tree);	
	/* Test Type	
	cout << r->getType() << endl;
	cout << r2->getType() << endl;
	*/

	/* Test Simplify
	cout << r->getNum()->getValue() << endl;
	cout << r->getDen()->getValue() << endl; 
	r->simplify();
	cout << r->getNum()->getValue() << endl;
	cout << r->getDen()->getValue() << endl; 
	*/
	/*
	cout << r->getNum()->toString() << endl;
	cout << r->getDen()->toString()  << endl;
	r->add(i1);
	cout << r->getNum()->toString() << endl;	
	cout << r->getDen()->toString() << endl;
	r->simplify();
	cout << r->getNum()->toString() << endl;	
	cout << r->getDen()->toString() << endl;
	*/	
		
		

	delete r;
	delete i1;
	delete i2;
	delete r2;

}












