/*
 * Number.cpp
 *
 *  Created on: Apr 8, 2014
 *      Author: kyle
 *
 */

#include "Number.h"

string Number::getType()
{
	throw logic_error("Error: Number.getType() called when it should have been implemented by a subclass.");
}

double Number::getValue()
{
	throw logic_error("Error: Number.getValue() called when it should have been implemented by a subclass.");
}

