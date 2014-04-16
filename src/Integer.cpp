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
/*
void Integer::add(Number* num)
{
	cout << "Successfully recognized adding a generic Number to this Integer" << endl; //all outputs here are for testing only
	// Do nothing. Destructor?
}
*/
Expression* Integer::add(Number* num)
{
	// needs to return answer, figure out format first. May affect above line (answer may need to be Integer).
	// same goes for other implemented methods.
	if(num->getType() != "Integer")
		//TODO
		throw logic_error("No one has written this part of the method yet");;


	int answer = this->getValue() + num->getValue(); //works
	return new Expression(new Integer(answer));

}
/*
void Integer::subtract(Number* num, Expression* caller)
{

	return 
//	cout << "Successfully recognized subtracting a generic Number from this Integer" << endl;
	// Do nothing
	// Destructor?
}
*/
Expression* Integer::subtract(Number* num)
{
	if(num->getType() != "Integer")
		//TODO
		throw logic_error("No one has written this part of the method yet");;



	int answer = this->getValue() - num->getValue(); //works
	return new Expression(new Integer(answer));


}
/*
void Integer::multiply(Number* num)
{
	cout << "Successfully recognized multiplying a generic Number and this Integer" << endl;
	// if coefficient == 1, do nothing
	// else multiply coefficient with Integer
}
*/
Expression* Integer::multiply(Number* num)
{
	if(num->getType() != "Integer")
		//TODO
		throw logic_error("No one has written this part of the method yet");;



	int answer = (this->getValue()) * (num->getValue()); //works
	return new Expression(new Integer(answer));

}



Expression* Integer::divide(Number* num)
{
	return new Expression(new Rational(this->getValue() , num->getValue()));

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


