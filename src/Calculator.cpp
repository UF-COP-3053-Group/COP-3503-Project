//
//  Calculator.cpp
//  COP-3503-Project
//
//  Created by Justin on 4/10/14.
//
//  Responsibilities:
//  Justin:
//     Everything in here, basically.
//  Hard to test as it's dependent on a lot of other classes working

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
	// TODO: Stop this from segfaulting on linux but not via LLVM?
	// Delete all pointers to expressions in the previous answers vector to prevent memory leaks
	for (int i = 0; i < previousAnswers.size(); i++)
	{
		// Delete all of the nodes in the tree, including the root
		// The root node will recursively delete all child nodes
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
 * Will store the answer for later retrieval in the previousAnswers
 * Also returns the reference to the calculated tree
 */
Expression* Calculator::calculate(string input)
{
	// First, we need to parse the input
	Expression* tree = parseInput(input);
	
	// DEBUG: Make sure the tree was parsed right
	cout << toString(tree) << endl;
	cout << toRPNString(tree) << endl;
	
	// Next, take the tree and simplify it
	simplifyTree(tree);
	
	// Finally, we add the tree to the list of previous inputs and answers.
	this->addAnswer(input, tree);
	
	// Return the reference to this tree as well
	return tree;
}


/**
 * Parses the input by first combining like terms over addition and subtraction,
 * then building a tree from the resulting (somewhat simplified) string.
 * Returns: a pointer to the root node of the tree
 */
Expression* Calculator::parseInput(string& input)
{
	// First, replace all instances of the 'ans' keyword with the last answer
	input = replaceAnswer(input);
	
	// Before building the tree, lets try to collect any simple like terms
	input = collectTerms(input);
	
	// Now, create the tree from the given input with the parser class
	Parser parser;
	Expression* root = parser.createAST( parser.tokenize(input) );
	
	// Returns the root node of the newly created tree
	return root;
}


/**
 *
 */
string Calculator::replaceAnswer(string input)
{
	// Find the position of an 'ans' keyword
	size_t position = input.find("ans");
	// Loop until there aren't any more keywords to replace
	while (position != string::npos)
	{
		// Get the last answer
		string lastAns = this->toString( this->getLastAnswer() );
		
		string replaceText = "( ";
		replaceText += lastAns;
		replaceText += " )";
		
		// Replace "ans" with the replaceText
		input.replace(position, string("ans").length(), replaceText);
		
		// Update the position
		position = input.find("ans");
	}
	
	return input;
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
void Calculator::simplifyTree(Expression*& root)
{
	root = simplifyNode(root);
}


/**
 * Helper function to recursively simplify the tree
 * Takes in a node and the last operation seen to pass on as the caller
 * Should be able to simplify the tree by replacing nodes in place, but I'm not sure how that can work with this tree
 * FIXME
 */
Expression* Calculator::simplifyNode(Expression* node)
{
	// DEBUG: Print the working tree
	cout << "Working Tree: " << toString(node) << endl;
	
	
	// If this node is an operator (not a number)
	if(!node->isNumber())
	{
		// Simplify left side recursively
		node->setLeft( simplifyNode(node->getLeftNode()) );
		
		// DEBUG: Show the change
		cout << "Tree modified left to: " << toString(node) << endl;
		
		// Simplify right side recursively
		node->setRight( simplifyNode(node->getRightNode()) );
		
		// DEBUG: Show the change
		cout << "Tree modified right to: " << toString(node) << endl;
		
		// Then operate in place
		if(node->getOperatorSymbol() == '+')
		{
			// If the left node is a number and the right node is a number
			if(node->getLeftNode()->isNumber() && node->getRightNode()->isNumber())
			{
				// Call the .add method of the left node with the right as an arg
				//return node->getLeftNode()->getNumber()->add( node->getRightNode()->getNumber());
				
				// DEBUG: Verbose version
				Number* left = node->getLeftNode()->getNumber();
				Number* right = node->getRightNode()->getNumber();
				cout << "Adding left to right" << endl;
				Expression* result = left->add(right);
				cout << "Result: " << toString(result) << endl;
				return result;
				
			}
			
			/* TODO: Is this needed? Probably redundant.
			// Try it with the right side
			else if(node->getRightNode()->isNumber())
			{
				return node->getRightNode()->getNumber()->add(node->getLeftNode());
			}
			*/
			
		}
		else if (node->getOperatorSymbol() == '-')
		{
			// If the left node is a number and the right node is a number
			if(node->getLeftNode()->isNumber() && node->getRightNode()->isNumber())
			{
				// Call the .subtract method of the left node with the right as an arg
				return node->getLeftNode()->getNumber()->subtract( node->getRightNode()->getNumber());
			}
		}
		else if (node->getOperatorSymbol() == '*')
		{
			// If the left node is a number and the right node is a number
			if(node->getLeftNode()->isNumber() && node->getRightNode()->isNumber())
			{
				// Call the .multiply method of the left node with the right as an arg
				return node->getLeftNode()->getNumber()->multiply( node->getRightNode()->getNumber());
			}
		}
		else if (node->getOperatorSymbol() == '/')
		{
			// If the left node is a number and the right node is a number
			if(node->getLeftNode()->isNumber() && node->getRightNode()->isNumber())
			{
				// Call the .devide method of the left node with the right as an arg
				//return node->getLeftNode()->getNumber()->divide( node->getRightNode()->getNumber());
				
				// DEBUG: Verbose version
				Number* left = node->getLeftNode()->getNumber();
				Number* right = node->getRightNode()->getNumber();
				cout << "Dividing left to right" << endl;
				Expression* result = left->divide(right);
				cout << "Result: " << toString(result) << endl;
				return result;
			}
		}
		// This operator isn't yet known or supported then
		else
		{
			string errorString = "Error in simplifying the tree: Unknown operator: ";
			errorString += node->getOperatorSymbol();
			throw invalid_argument(errorString);
		}
		
	}
	
	// If not an operator, it's a number, so return the number
	return node;
	
	// If we reach here, something went wrong with the recursive calls
	throw runtime_error("We should have never reached this point");
}


/**
 * Takes in the root of a tree and converts it to a string
 * Returns a string that represents the simplified mathematical expression
 */
string Calculator::toString(Expression* root)
{
	// Note: An in order traversal of this tree results in standard (infix) output
	// Which is currently what we're outputting here
	
	// If the root is a not a number (is an operator), return the toString of left, right, and operator
	if (!root->isNumber())
	{
		// Output in infix
		string out;
		out = toString(root->getLeftNode()) + " " + root->getOperatorSymbol() + " " + toString(root->getRightNode());
		return out;
	}
	
	// If the root is a number
	if (root->isNumber())
	{
		// return the number as a string
		return root->getNumber()->toString();
	}
	
	
	throw runtime_error("Error in calulator.toString: We should have never reached the end of this recursive function.");
}


/**
 * Takes in the root of a tree and converts it to a string
 * Returns a string that represents the simplified mathematical expression
 */
string Calculator::toRPNString(Expression* root)
{
	// Note: A post order traversal of this tree results in RPN output
	// Which is currently what we're outputting here
	
	// If the root is a not a number (is an operator), return the toString of left, right, and operator
	if (!root->isNumber())
	{
		// Output in RPN via post order traversal
		string out;
		out = toRPNString(root->getLeftNode()) + " " + toRPNString(root->getRightNode()) + " "  + root->getOperatorSymbol();
		return out;
	}
	
	// If the root is a number
	if (root->isNumber())
	{
		// return the number as a string
		return root->getNumber()->toString();
	}
	
	
	throw runtime_error("Error in calulator.toRPNString: We should have never reached the end of this recursive function.");
}


/**
 * Takes in the root of a tree and converts it to a double
 * Returns the double that represents the answer from the tree
 */
double Calculator::toDouble(Expression* root)
{
	// First, get the operator from this node
	char op = root->getOperatorSymbol();
	
	// Then, operate recursively down the tree
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
		return root->getNumber()->getValue();
	}
}


/**
 * Adds an input and answer to the previousInput and previousAnswer vectors respectively,
 * making sure both are valid so they can have a common size and index between them.
 */
void Calculator::addAnswer(string input, Expression* answer)
{
	// Make sure both inputs are valid
	if(input != "" && answer != nullptr)
	{
		// Add to the vectors
		this->previousInputs.push_back(input);
		this->previousAnswers.push_back(answer);
	}
}


/**
 * Returns a string of the previous inputs and their respective answers
 * in the form "input = answer\n"
 */
string Calculator::getPreviousAnswersAsString()
{
	string out = "Previous Answers:\n";
	string iString;
	
	// Make sure there are some answers to be given
	// If the size isn't greater than 0, return an error string
	if (!(previousAnswers.size() > 0))
	{
		return "No previous answers to show\n";
	}
	
	for (int i = 0; i<previousInputs.size(); i++)
	{
		// Number the outputs starting at size and counting down
		int num = previousInputs.size() - i;
		
		// Convert num to a string
		stringstream ss;
		ss << num;
		ss >> iString;
		
		out += iString + ".) ";
		out += previousInputs[i];
		out += " = ";
		// Convert the Expression* tree to a string.
		out += this->toString(previousAnswers[i]);
		out += "\n";
	}
	
	return out;
}

