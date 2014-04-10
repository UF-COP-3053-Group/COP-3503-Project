//
//  Rational.cpp
//  COP-3503-Project
//
//  Created by Justin on 4/9/14.
//
//

#include "Rational.h"

/**
 * Constructor
 */
Rational::Rational(int num , int den)
{

	this->num = num;
	this->den = den;
	// TODO: Create the constructor

}

Rational::~Rational()
{
	

}


//Need stricter checking of params, doesn't work for
//negative numbers yet... or divide by 0 errors
int Rational::gcd(int a , int b)
{
	// Check for invalid b
	if (b == 0)
		throw invaid_argument("Can't devide by 0");
	
	int top = a >= b ? a : b;
	int bot = a <= b ? a : b;

	int r = top % bot;

	if(r == 0)
		return bot;

	else
	{
		gcd(bot, r);	
	}

	// Should never reach this far, but if
	throw logic_error("gcd not found for this rational");
}

void Rational::simplify()
{
	int gcd = Rational::gcd(this->num , this->den);
	num = num / gcd;
	den = den / gcd;	

}

int Rational::getNum()
{
	return num;
}

int Rational::getDen()
{
	return den;
}
