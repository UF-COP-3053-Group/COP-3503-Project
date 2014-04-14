//
//  Constant.cpp
//  COP-3503-Project
//
//  Created by Justin on 4/9/14.
//
//


#include "Constant.h"

// Check the definitions of our constants
// pi
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
// e
#ifndef M_E
#define M_E 2.7182818284590452354
#endif


/**
 * Constructor
 * Args: <string> name: The name of the constant, e.g. pi or e
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
	// C++ doesn't allow string switching, so a chain of if - else if is used instead.
	if (name == "pi")
		return true;

	else if (name == "e")
		return true;

	else
		return false;
}

/**
 * Function to get the decimal value of this current constant.
 * Doubles as a way to initilize the value in the constructor and as a value getter
 */
double Constant::getValue()
{
	/*
	 C++ doesn't allow string switching, so a chain of if - else if is used instead.
	 Each constant first trys to return the value as defined by the platform's math.h, 
	 and then reverts to a hard-coded 32-bit double definition if not found.
	 */
	if (name == "pi")
		return M_PI;

	else if (name == "e")
		return M_E;

	// Should never be encountered, as we check if the constant is known during construction
	else
		throw runtime_error("How did we get here? Error getting the value of constant: " + this->name);
}

/**
 * Returns the name of this constant, e.g. pi or e
 * return: <string> name
 */
string Constant::getName()
{
	return this->name;
}

