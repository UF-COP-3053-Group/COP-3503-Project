//
//  Rational.cpp
//  COP-3503-Project
//
//  Created by Justin on 4/9/14.
//
//

#include "Rational.h"
#include <stdexcept>
using namespace std;

/**
 * Constructor
 */
Rational::Rational(string decimalString){
    //create a rational from a decimal number
}

Rational::Rational(Number num, Number den){
    
}

Rational::Rational(int num , int den)
{
	// TODO: Create the constructor

}

Rational::~Rational()
{
	

}

//handling of divide by 0 is done by constructor,
//negative numbers should work now.
int Rational::gcd(int a , int b)
{

	bool flip = false;
	if(b < 0 && a > 0)
	{
		a *= -1;
		b *= -1;
	}

	if(b < 0 && a < 0)
	{
		a *= -1;
		b *= -1;
	}

	if(a < 0)
	{
		flip = true;	
		a *= -1;
	}
	int top = a >= b ? a : b;
	int bot = a <= b ? a : b;

	int r = top % bot;

	if(r == 0)
	{
		if(flip)
			return -1 *bot;
		return bot;	
	}
	else
	{
		gcd(bot, r);	
	}
	
	// We should never get here
	throw runtime_error("Error in calculating the gcd. We should never have reached this point.");

}

/* FIXME
void Rational::simplify()
{
	int gcd = Rational::gcd(this->num , this->den);
	if(num == 0)
	{
		Rational::rationalToInt(0);//should return an integer, = 0;
	}

	if(den == 1)
	{
		Rational::rationalToInt(num);//should return an integer, = num

	}

	if(num < 0 && den < 0)
	{
		num *= -1;
		den *= -1;
	}
	num = num / gcd;
	den = den / gcd;	

}
*/
