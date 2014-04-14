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
	return this->inputNum;
}

string Integer::getType()
{
	return this->type;
}

void Integer::add(Number* num)
{
	cout << "Successfully recognized adding a generic Number to this Integer" << endl; //all outputs here are for testing only
	// Do nothing. Destructor?
}

int Integer::add(Integer* num)
{
	// needs to return answer, figure out format first. May affect above line (answer may need to be Integer).
	// same goes for other implemented methods.
	int answer = this->getValue() + num->getValue(); //works
	return answer; 
}

void Integer::subtract(Number* num)
{
	cout << "Successfully recognized subtracting a generic Number from this Integer" << endl;
	// Do nothing
	// Destructor?
}

int Integer::subtract(Integer* num)
{
	int answer = this->getValue() - num->getValue(); //works
	return answer;
}

void Integer::multiply(Number* num)
{
	cout << "Successfully recognized multiplying a generic Number and this Integer" << endl;
	// if coefficient == 1, do nothing
	// else multiply coefficient with Integer
}

int Integer::multiply(Integer* num)
{
	int answer = (this->getValue()) * (num->getValue()); //works
	return answer;	

}

void Integer::divide(Number* num)
{
	cout << "Successfully recognized dividing this Integer by a generic Number. Or vice versa" << endl;
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

