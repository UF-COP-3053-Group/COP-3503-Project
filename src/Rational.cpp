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
    type = "Rational";
}

Rational::Rational(Number num, Number den){
    type = "Rational";
    numerator = num;
    denom = den;
    if (denom.getValue() == 0)
        throw "Division by zero is bad";
}

Rational::Rational(int num , int den)
{
    type = "Rational";
	numerator = Integer(num);
    denom = Integer(den);
    if (denom.getValue() == 0)
        throw "Division by zero is bad";

}

Rational::Rational(Rational num, Number den){
    type = "Rational";
    //Depends on nonexistent methods
    numerator = num.getNum();
    //denom = num.getDen().multiply(den));
    if (denom.getValue() == 0)
        throw "Division by zero is bad";
}

Rational::Rational(Number num, Rational den){
    //numerator = num * den.getDen();
    denom = den.getNum();
    if (denom.getValue() == 0)
        throw "Division by zero is bad";
}

Rational::Rational(Rational num, Rational den){
    //numerator = num.getNum() * den.getDen();
    //denom = num.getDen() * den.getNum();
    if (denom.getValue() == 0)
        throw "Division by zero is bad";
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

Number Rational::getNum(){
    return this->numerator;
}

Number Rational::getDen(){
    return this->denom;
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
