//
//  Constant.cpp
//  COP-3503-Project
//
//  Created by Justin on 4/9/14.
//
//


#include "Constant.h"
#include <stdexcept>

/**
 *	Constructor
 *  Args: <string> name: The name of the constant, e.g. pi or e
 */
Constant::Constant(string name)
{
	// First, convert name string to lowercase
	transform(name.begin(), name.end(), name.begin(), ::tolower);
	
	// If we don't know the constant, throw an exception
	if (!isKnown(name))
	{
		throw invalid_argument(name + " is not a known constant.");
	}
	
	// Set the name of the constant
	this->name = name;
}


/**
 * Function to check if a constant is one understood by our program
 * Args: <string> name: the lowercase name of the constant to check
 */
bool Constant::isKnown(string name)
{
	switch (name)
	{
		case "pi":
			return true;
			break;
		
		case "e":
			return true;
			break;
		
		case default:
			return false;
	}
}

/**
 * Function to get the decimal value of this current constant.
 * Doubles as a way to initilize the value in the constructor and as a value getter
 */
double Constant::getValue()
{
	switch (this->name)
	{
		case "pi":
			return 0.1;
			break;
			
		case "e":
			return 0.1;
			break;
			
		// Should never be encountered, as we check if the constant is known during construction
		case default:
			throw runtime_error("How did we get here? Error getting the value of constant: " + this->name);
	}
}

string Constant::getName()
{
	return this->name;
}
