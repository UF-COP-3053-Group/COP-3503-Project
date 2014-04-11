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

int Integer::getInt()
{
	return inputNum;
}


void Integer::add(Number num)
{
	cout << "Successfully recognized adding a generic Number to this Integer" << endl; //all outputs here are for testing only
	// Do nothing
}

void Integer::add(Integer num)
{
	// needs to return answer, figure out format first. May affect above line (answer may need to be Integer).
	// same goes for other implemented methods.
	int answer = this->getInt() + num.getInt(); //works
	 cout << answer << endl; //testing
}

void Integer::subtract(Number num)
{
	cout << "Successfully recognized subtracting a generic Number from this Integer" << endl;
	// Do nothing
}

void Integer::subtract(Integer num)
{
	int answer = this->getInt() - num.getInt(); //works
	cout << answer << endl; // testing
}

void Integer::multiply(Number num)
{
	cout << "Successfully recognized multiplying a generic Number and this Integer" << endl;
	// if coefficient == 1, do nothing
	// else multiply coefficient with Integer
}

void Integer::multiply(Integer num)
{
	cout << "Successfully recognized multiplying an Integer and this Integer" << endl;
	int answer = (this->getInt()) * (num.getInt()); //works
	cout << answer << endl; // testing
}

void Integer::divide(Number num)
{
	cout << "Successfully recognized dividing this Integer by a generic Number. Or vice versa" << endl;
}

void Integer::divide(Integer num)
{
	cout << "Successfully recognized dividing this Integer by an Integer" << endl;
	// This implementation assumes 'num' is the divisor
	int answer = this->getInt() / num.getInt(); //works
	cout << answer << endl; // testing
}

