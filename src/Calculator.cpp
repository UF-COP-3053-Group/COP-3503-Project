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
	/*
	// Delete all pointers to expressions in the previous answers vector to prevent memory leaks
	for (int i = 0; i < previousAnswers.size(); i++)
	{
		// Delete all of the nodes in the tree, including the root
		// The root node will recursivly delete all child nodes
		delete previousAnswers[i];
	}
	*/
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
 * Will store the answer for later retrieval in the previousAnswers
 * Also returns the reference to the calculated tree
 */
Expression* Calculator::calculate(string input)
{
	// First, we need to parse the input
	Expression* tree = parseInput(input);
	
	// Next, take the tree and simplify it
	simplifyTree(tree);
	
	// Finally, we add the tree to the list of previous answers.
	previousAnswers.push_back(tree);
	
	// Return the reference to this tree as well
	return tree;
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
	
	// Now, create the tree from the given input with the parser class
	Parser parser;
	Expression* root = parser.createAST( parser.tokenize(input) );
	
	// Returns the root node of the newly created tree
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


/**
 * Takes in of root node of an AST and simplifies the tree in place.
 * Args: <Expression*> root: the root of the tree
 */
void Calculator::simplifyTree(Expression* root)
{
	
}


/**
 * Takes in the root of a tree and converts it to a string
 * Returns a string that represents the simplified mathematical expression
 */
string Calculator::toString(Expression* root)
{
	
	return "Not yet implemented";
}

/**
 * Takes in the root of a tree and converts it to a double
 * Returns the double that represents the answer from the tree
 */
double Calculator::toDouble(Expression* root)
{
	// First, get the operator from this node
	char op = root->getOperatorSymbol();
	
	// Then, operate recursivly down the tree
	if (op == '^')
	{
		return pow( toDouble(root->getLeftNode()), toDouble(root->getRightNode()) );
	}
	else if (op == '*')
	{
		return toDouble(root->getLeftNode()) * toDouble(root->getRightNode());
	}
	else if (op == '/')
	{
		return toDouble(root->getLeftNode()) / toDouble(root->getRightNode());
	}
	else if (op == '+')
	{
		return toDouble(root->getLeftNode()) + toDouble(root->getRightNode());
	}
	else if (op == '-')
	{
		return toDouble(root->getLeftNode()) - toDouble(root->getRightNode());
	}
	else
	{
		Number* num = root->getNumber();
		double lol = num->getValue();
		
		return lol;
	}
}
