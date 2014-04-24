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
	 and if not found then reverts to the hard-coded 32-bit double definition at the top of this file.
	 */
	if (this->name == "pi")
		return M_PI;

	else if (this->name == "e")
		return M_E;

	// Should never be encountered, as we check if the constant is known during construction
	else
	{
		throw runtime_error("How did we get here? Error getting the value of constant: " + this->name);
	}
}

/**
 * Returns the name of this constant, e.g. pi or e
 * return: <string> name
 */
string Constant::getName()
{
	return this->name;
}

/**
 * Will attempt to add any passed Number* to this constant
 * Returns a new expression pointer (AKA expression tree) representing the answer
 */
Expression* Constant::add(Number *num)
{
	// Use a dynamic cast to check if the passed number is a constant
	Constant* constant = dynamic_cast<Constant*>(num);
	// If it is, and it's the same constant name, use the add constant method
	if (constant != nullptr && this->getName() == constant->getName())
	{
		return this->add(constant);
	}
	// Otherwise, we return an expression concatinating these numbers with the add operator
	else
	{
		return new Expression('+', new Expression(this), new Expression(num));
	}

}


/**
 * Adds two constants of the same kind, returning an expression "2 * constant"
 */
//TODO: Replace this by collecting terms during tokenization.
Expression* Constant::add(Constant *num)
{
	// When two of the same constants are added, they return 2 * the constant
	return new Expression('*', new Expression(new Integer(2)), new Expression(num));
	
}

Expression* Constant::subtract(Number *num)
{
	// Use a dynamic cast to check if the passed number is a constant
	Constant* constant = dynamic_cast<Constant*>(num);
	// If it is, use the add constant method
	if (constant != nullptr && this->getName() == constant->getName())
	{
		return this->subtract(constant);
	}
	// Otherwise, we return an expression concatinating these numbers with the add operator
	else
	{
		return new Expression('-', new Expression(this), new Expression(num));
	}

}


Expression* Constant::subtract(Constant* num)
{
	// When two of the same constants are subtracted, they cancel each other out, so there is no expression
	return nullptr;
}

Expression* Constant::multiply(Number *num)
{
	//TODO
	throw logic_error("No one has written this part of the method yet");

}

Expression* Constant::divide(Number *num)
{
	//TODO
	throw logic_error("No one has written this part of the method yet");

}


/**
 * Returns the coefficient of this constant. E.g. 2 * pi will return an Integer pointer to 2.
 */
Number* Constant::getCoefficient()
{
	return this->coefficient;
}


/**
 * Returns a string representation of this constant.
 * e.g. "3 * pi" or "e ^ 2"
 */
string Constant::toString()
{
	return this->getName();
}









