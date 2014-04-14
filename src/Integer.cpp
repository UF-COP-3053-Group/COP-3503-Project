//
//  Integer.cpp
//  COP-3503-Project
//
//  Created by Justin on 4/9/14.
//
//

#include "Integer.h"

Integer::Integer()
{
	// Default constructor for testing
}

/**
 * Constructor
 */
Integer::Integer(int inputNum)
{
	// TODO: Parser should take care of input and push it to correct class.
	this->inputNum = inputNum;
}

double Integer::getValue()
{
	return inputNum;
}