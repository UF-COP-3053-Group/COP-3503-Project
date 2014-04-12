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
	// Delete all pointers to expressions in the previous answers vector to prevent memory leaks
	for (int i = 0; i < previousAnswers.size(); i++)
	{
		// Delete all of the nodes in the tree, including the root
		// The root node will recursivly delete all child nodes
		delete previousAnswers[i];
	}
}


/**
 * A getter function that returns a vector of Expression pointers
 * representing the previous answers, in the order oldest at index 0
 * to newest answer at index .size() - 1
 */
vector<Expression*> Calculator::getPreviousAnswers()
{
	return previousAnswers;
}


/**
 * A getter function that returns the last answer as an Expression pointer.
 * Should be used to replace the ans keyword
 */
Expression* Calculator::getLastAnswer()
{
	// Return the last thing in the vector
	return previousAnswers.back();
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
Expression* Calculator::parseInput(string& input)
{
	// Before building the tree, lets try to collect any simple like terms
	input = collectTerms(input);
	
	// Now, create the tree from the given input
	Expression* root = createTree(input);
	
	
	return root;
}


/**
 * A preprocessing helper function that will attempt to collect like terms from the passed
 * string before the calculator builds the expression tree.
 * Args: <string> input: the input math string
 * Returns: <string>: a version of the input with some terms collected (if possible)
 */
string Calculator::collectTerms(string& input)
{
	// First, break up the string into a vector split over each plus and minus
	
	//TODO: Implement this method. For now, we'll focus on the Expression tree, as it's more important
	return input;
}

Expression* Calculator::createTree(string input)
{
	return new Expression;
}

