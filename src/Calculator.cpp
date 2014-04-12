//
//  Calculator.cpp
//  COP-3503-Project
//
//  Created by Justin on 4/10/14.
//
//

#include "Calculator.h"


/**
 * Constructor
 */
Calculator::Calculator()
{
	
}


/**
 * Destructor
 */
Calculator::~Calculator()
{
	
}


/**
 * The main calculator function that takes an input and simplifies it.
 * Will store the answer for later retrieval.
 */
void Calculator::calculate(string input)
{
	// First, we need to parse the input
	parseInput(input);
	
	// Next, take the tree
}


/**
 * Parses the input by first combining like terms over additon and subtraction,
 * then building a tree from the resulting (somewhat simplified) string.
 * Returns: a pointer to the root node of the tree
 */
expression* Calculator::parseInput(string& input)
{
	// Before building the tree, lets try to collect any simple like terms
	input = collectTerms(input);
	
	// Now, create the tree from the given input
	expression* tree = createTree(input);
	
	
	return tree; // Yes?
}

string Calculator::collectTerms(string& input)
{
	// First, break up the string into a vector split over each plus and minus
	
	
	return input;
}

expression* Calculator::createTree(string input)
{
	return new expression;
}