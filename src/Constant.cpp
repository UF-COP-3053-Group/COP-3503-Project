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
	
	// Set the coefficient to 1
	this->coefficient = new Integer(1);
	this->exponent = new Integer(1);
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
 * Adds two constants of the same kind by adding their coefficients
 */
//TODO: Replace this by collecting terms during tokenization, if possible
Expression* Constant::add(Constant *num)
{
	// When two of the same constants are added, they add their coefficients
	this->coefficient = this->coefficient->add( num->getCoefficient() )->getNumber();
	
	// Return this constant now that its coefficient has been updated
	return new Expression(this);
	
}


Expression* Constant::subtract(Number *num)
{
	// Use a dynamic cast to check if the passed number is a constant
	Constant* constant = dynamic_cast<Constant*>(num);
	// If it is, and it's the same name, use the constant version of this method
	if (constant != nullptr && this->getName() == constant->getName())
	{
		return this->subtract(constant);
	}
	// Otherwise, we return an expression concatinating these numbers with the subtract operator
	else
	{
		return new Expression('-', new Expression(this), new Expression(num));
	}

}

/**
 * Subtracts two constants of the same kind by subtracting their coefficients
 */
Expression* Constant::subtract(Constant* num)
{
	// When two of the same constants are subtracted, they subtract their coefficients
	this->coefficient = this->coefficient->subtract( num->getCoefficient() )->getNumber();
	
	// TODO: Add this back once Integer is fully implemented properly
//	if (coefficient->getValue() == 0)
//	{
//		return new Expression( new Integer(0) );
//	}
	// Return this constant now that its coefficient has been updated
	return new Expression(this);
}


Expression* Constant::multiply(Number *num)
{
	// Use a dynamic cast to check if the passed number is a constant
	Constant* constant = dynamic_cast<Constant*>(num);
	// If it is, and it's the same constant name, use the constant version of this method
	if (constant != nullptr && this->getName() == constant->getName())
	{
		return this->multiply(constant);
	}
	// Otherwise, we return an expression concatinating these numbers with the multiply operator
	else
	{
		return new Expression('*', new Expression(this), new Expression(num));
	}
}


/**
 * Multiplies two constants of the same kind by adding together their exponents
 */
Expression* Constant::multiply(Constant *num)
{
	// When two of the same constants are multiplied, they add their exponents
	this->exponent = this->exponent->add( num->getExponent() )->getNumber();
	
	// If the exponent is now 0, simplify that to 1
	if (this->getExponent()->getValue() == 0)
	{
		return new Expression( new Integer(1) );
	}
	
	// Return this constant now that its coefficient has been updated
	return new Expression(this);
}


Expression* Constant::divide(Number *num)
{
	// Use a dynamic cast to check if the passed number is a constant
	Constant* constant = dynamic_cast<Constant*>(num);
	// If it is, and it's the same constant name, use the constant version of this method
	if (constant != nullptr && this->getName() == constant->getName())
	{
		return this->divide(constant);
	}
	// Otherwise, we return an expression concatinating these numbers with the divide operator
	else
	{
		return new Expression('/', new Expression(this), new Expression(num));
	}
}


/**
 * Divides two constants of the same kind by subtracting their exponents
 */
Expression* Constant::divide(Constant *num)
{
	// When two of the same constants are divided, they subtract their exponents
	this->exponent = this->exponent->subtract( num->getExponent() )->getNumber();
	
	// If the exponent is now 0, simplify that to 1
	if (this->getExponent()->getValue() == 0)
	{
		return new Expression( new Integer(1) );
	}
	
	// Return this constant now that its coefficient has been updated
	return new Expression(this);
}


/**
 * Exponentiates this constant by multiplying together this exponent and the passed exponent
 */
/*Expression* Constant::exponentiate(Number *num)
{
	
}
*/


/**
 * Returns the coefficient of this constant. E.g. 2 * pi will return an Integer pointer to 2.
 */
Number* Constant::getCoefficient()
{
	return this->coefficient;
}


/**
 * Returns the coefficient of the constant. E.g. pi ^ 3 will return an Integer pointer to 3
 */
Number* Constant::getExponent()
{
	return this->exponent;
}


/**
 * Set the coefficient of this constant to the passed Number* coefficient
 */
void Constant::setCoefficient(Number* coefficient)
{
	this->coefficient = coefficient;
}


/**
 * Set the exponent of this constant to the passed Number* exponent
 */
void Constant::setExponent(Number* exponent)
{
	this->exponent = exponent;
}


/**
 * Returns a string representation of this constant.
 * e.g. "3 * pi" or "e ^ 2"
 */
string Constant::toString()
{
	string output = "";
	
	// If the coefficient is not equal to one, include it in the output
	if (this->getCoefficient()->getValue() != 1)
	{
		output += this->getCoefficient()->toString() + " * ";
	}
	
	// Include the name
	output += this->getName();
	
	// If the exponent is not equal to one, include it in the output
	if (this->getExponent()->getValue() != 1)
	{
		output += " ^ " + this->getExponent()->toString();
	}
	
	return output;
}









