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

Rational::Rational(Number* num, Number* den){
    type = "Rational";
    numerator = num;
    this->den = den;
    if (den->getValue() == 0)
        throw "Division by zero is bad";
}

Rational::Rational(int num , int den)
{
    type = "Rational";
	numerator = Integer(num);
    den = Integer(den);
    if (den->getValue() == 0)
        throw "Division by zero is bad";

}

Rational::Rational(Rational* num, Number* den){
    type = "Rational";
    //Depends on nonexistent methods
    numerator = num->getNum();
    //denom = num.getDen().multiply(den));
    if (den->getValue() == 0)
        throw "Division by zero is bad";
}

Rational::Rational(Number* num, Rational* den){
    //numerator = num * den.getDen();
    den = den->getNum();
    if (den->getValue() == 0)
        throw "Division by zero is bad";
}

Rational::Rational(Rational* num, Rational* den){
    //numerator = num.getNum() * den.getDen();
    //denom = num.getDen() * den.getNum();
    if (den->getValue() == 0)
        throw "Division by zero is bad";
}

Rational::~Rational()
{
	

}

double Rational::getValue()
{
	return (numerator->getValue()) / (den->getValue*());
}
//handling of divide by 0 is done by constructor,
//negative numbers should work now.
Integer Rational::gcd(Integer c , Integer d)
{
    
   

    int a = c.getValue();
    int b = d.getValue();
    
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
			return Integer(-1 * bot);
		return Integer(bot);
	}
	else
	{
		gcd(bot, r);	
	}
	
	// We should never get here
//	throw runtime_error("Error in calculating the gcd. We should never have reached this point.");

}

Number Rational::getNum(){
    return this->numerator;
}

Number Rational::getDen(){
    return this->den;
}
/*
void Rational::simplify()
{
	if(numerator.getType() != "Integer" || den.getType() != "Integer")
		return;

	int numerator = (int)num.getValue();
	int denominator = (int) den.getValue();
	int gcd = Rational::gcd(numerator, denominator);
	if(numator== 0)
	{
		return 0;
	}

	if(denominator== 1)
	{
		Rational::rationalToInt(num);//should return an integer, = num

	}

	if(numerator < 0 && denominator < 0)
	{
		numerator *= -1;
		denominator *= -1;
	}
	num = numerator / gcd;
	den = denominator / gcd;	

}
*/
