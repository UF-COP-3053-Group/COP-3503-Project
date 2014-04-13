//
//  Operator.cpp
//  COP-3503-Project
//
//  Created by Justin on 4/12/14.
//
//

#include "Operator.h"


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

