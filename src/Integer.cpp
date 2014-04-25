//
//  Integer.cpp
//  COP-3503-Project
//
//  Created by Justin on 4/9/14.
//
//

#include "Integer.h"


/**
 * Constructor
 */
Integer::Integer(int inputNum)
{
	this->inputNum = inputNum;
	this->type = "Integer";
}


double Integer::getValue()
{
	return this->inputNum;
}

string Integer::getType()
{
	return type;
}


Expression* Integer::add(Number* num)
{
	// Check if num is an integer
	if (dynamic_cast<Integer*>(num) != nullptr)
	{
		// num is an integer, so let's do some simple artihmetic
		this->inputNum = this->getInt() + dynamic_cast<Integer*>(num)->getInt();
		
		// Retun this Integer as a new expression
		return new Expression(this);
	}
	
	// Default behavior: return a new expression concatinating these
	return new Expression('+', new Expression(this), new Expression(num));
}


Expression* Integer::subtract(Number* num)
{
	if(num->getType() != "Integer")
		//TODO
		throw logic_error("No one has written this part of subtract for Integer yet");



	int answer = this->getValue() - num->getValue(); //works
	return new Expression(new Integer(answer));


}


Expression* Integer::multiply(Number* num)
{
	// Check if num is an integer
	if (dynamic_cast<Integer*>(num) != nullptr)
	{
		// This is an integer, so let's do some simple artihmetic
		this->inputNum = this->getInt() * dynamic_cast<Integer*>(num)->getInt();
		
		// Retun this Integer as a new expression
		return new Expression(this);
	}
	
	// Check if num is a constant
	if (dynamic_cast<Constant*>(num) != nullptr)
	{
		// This is a constant, so let the constant handle multiplying this into its coefficient
		return dynamic_cast<Constant*>(num)->multiply(this);
	}
	
	// Default behavior: return a new expression concatinating these
	return new Expression('*', new Expression(this), new Expression(num));
}


Expression* Integer::divide(Number* num)
{
	// FIXME: Why are we using getValue here?? The point of the project is to avoid doubles whenever possible.
	return new Expression(new Rational(this->getValue() , num->getValue()));
}


/**
 * Will exponentiate this integer by the passed Number* num
 * Written by Justin
 */
Expression* Integer::exponentiate(Number* num)
{
	// Use a dynamic cast to check if the passed number is an integer
	Integer* passedInt = dynamic_cast<Integer*>(num);
	
	// If it is, we can simply use the pow method
	if (passedInt != nullptr)
	{
		// Just change this number in place
		this->inputNum = pow( this->getInt(), passedInt->getValue() );
		
		// Return this Integer as an expression
		return new Expression(this);
	}
	// Otherwise, we return an expression concatinating these numbers with the operator
	else
	{
		return new Expression('^', new Expression(this), new Expression(num));
	}
}

/**
 * Retuns the primitive int stored by this Integer
 */
int Integer::getInt()
{
	return this->inputNum;
}


string Integer::toString()
{
	ostringstream rtnStream;
	rtnStream << this->getValue();
	string rtnString = rtnStream.str();
	return rtnString;
}


/*
Rational Integer::divide(Integer num)
{
	// This implementation assumes 'num' is the divisor

	double answer = this->getValue() / num.getValue(); //works
	Rational r = new Rational(answer);
	return r;

	// Alternative implementation: returning a Rational:

//	Rational *ratAnswer = new Rational(getInt(), num.getInt());
//	cout << ratAnswer->getNum() << "/" << ratAnswer->getDen() << endl;
}
*/


