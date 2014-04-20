//
//  Operator.cpp
//  COP-3503-Project
//
//  Created by Justin on 4/12/14.
//
//

#include "Operator.h"

/**
 * Empty Constructor to allow empty operators to exist as needed for tokens and nodes
 */
Operator::Operator()
{
	this->symbol = '\0';
}


/**
 * Constructor to build an operator from just the passed symbol.
 * Uses findPrecedence(symbol) and findAssoc(symbol) to build the parameters
 */
Operator::Operator(char symbol)
{
	this->symbol = symbol;
	this->precedence = findPrecedence(symbol);
	this->rightAssoc = findRightAssoc(symbol);
}


/**
 * Constructor
 * Args: a character symbol for the operation, a numerical presidence (higher is more urgent), and if it is right associtive.
 */
Operator::Operator(char symbol, int precedence, bool rightAssoc)
{
	this->symbol = symbol;
	this->precedence = precedence;
	this->rightAssoc = rightAssoc;
}


/**
 *
 */
int Operator::findPrecedence(char symbol)
{
	// Switch the symbol, returning it's precedence
	switch (symbol)
	{
		case '+':
		case '-':
			return 2;
			break;
			
		case '*':
		case '/':
			return 3;
			break;
		
		case '^':
			return 4;
			break;
		
		default:
			throw runtime_error("Couldn't find the precedence for this symbol.");
	}
}


/**
 *
 */
bool Operator::findRightAssoc(char symbol)
{
	// Check if this symbol is right associative, returning false by default
	if (symbol == '^')
	{
		return true;
	}
	
	// Default case
	return false;
}


/**
 * Returns true if this operator is right associative (e.g. exponentiation), false otherwise
 */
bool Operator::isRightAssoc()
{
	return this->rightAssoc;
}


/**
 * Returns the character symbol for this operator
 */
char Operator::getSymbol()
{
	return this->symbol;
}


/**
 * Returns the numberical precedence of this operator
 */
int Operator::getPrecedence()
{
	return this->precedence;
}

/**
 * Compares the precedence of this operator and the passed operator
 */
int Operator::comparePrecedence(Operator other)
{
	// If this has a higher precedence, return 1
	if ( this->getPrecedence() > other.getPrecedence() )
	{
		return 1;
	}
	// If this has a lower precedence, return -1
	else if ( this->getPrecedence() < other.getPrecedence() )
	{
		return -1;
	}
	// If they are equal, return 0
	else if ( this->getPrecedence() == other.getPrecedence() )
	{
		return 0;
	}
	// Should never be reached
	else
	{
		throw runtime_error("Error in comparing precedence. Something must have went very, very wrong.");
	}
		
}

