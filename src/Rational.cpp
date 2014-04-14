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
	this->numerator = new Integer(num);
    this->den = new Integer(den);
    if (this->den->getValue() == 0)
        throw "Division by zero is bad";

}
//TODO
Rational::Rational(Rational* num, Number* den){
    type = "Rational";
    //Depends on nonexistent methods
//    this->numerator = num->getValue();
    //denom = num.getDen().multiply(den));
    if (den->getValue() == 0)
        throw "Division by zero is bad";
}
//TODO
Rational::Rational(Number* num, Rational* den){
    //numerator = num * den.getDen();
   // this->den = den->getValue();
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

string Rational::getType()
{
	return this->type;
}

double Rational::getValue()
{
	return (numerator->getValue()) / (den->getValue());
}
//handling of divide by 0 is done by constructor,
//negative numbers should work now.
int Rational::gcd(int c , int d)
{
    
   

    int a = c ;//.getValue();
    int b = d ;//.getValue();
    
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
			return (-1 * bot);
		return (bot);
	}
	else
	{
		gcd(bot, r);	
	}
	
	// We should never get here
	throw runtime_error("Error in calculating the gcd. We should never have reached this point.");

}

Expression* Rational::multiply(Rational *r , Expression* caller)
{
	//only handle simple case : int / int for now	
	if(this->numerator->getType() != "Integer"  || this->den->getType() != "Integer")
	{
		
		return caller; 

	}


	else
	{
		int ansNum = numerator->getValue() + r->getNum()->getValue();
		int ansDen = den->getValue() + r->getDen()->getValue();


		return new Expression(new Rational(ansNum , ansDen));
	}
		

}

Expression* Rational::divide(Rational *r , Expression *caller)
{
	//only handle simple case : int / int for now	
	if(this->numerator->getType() != "Integer"  || this->den->getType() != "Integer")
	{
		
		return caller; 

	}

	else
	{
		int ansNum = numerator->getValue() + r->getDen()->getValue();
		int ansDen = numerator->getValue() + r->getNum()->getValue();	
		
		return new Expression(new Rational(ansNum , ansDen));

	}
	

}

Expression* Rational::add(Rational *r , Expression *caller)
{
	//only handle simple case : int / int for now	
	if(this->numerator->getType() != "Integer"  || this->den->getType() != "Integer")
	{
		
		return caller; 

	}

	else
	{
		int ansNum =( numerator->getValue() * r->getDen()->getValue() ) + ( den->getValue() * r->getNum()->getValue() );

		int ansDen = den->getValue() * r->getDen()->getValue();


		return new Expression(new Rational(ansNum , ansDen));


	}

}

Expression* Rational::subtract(Rational *r , Expression *caller)
{
	//only handle simple case : int / int for now	
	if(this->numerator->getType() != "Integer"  || this->den->getType() != "Integer")
	{
		
		return caller; 

	}


	else
	{
		int ansNum = (numerator->getValue() * r->getDen()->getValue()) - (den->getValue() * r->getNum()->getValue());
		int ansDen = den->getValue() * r->getDen()->getValue();
		
		return new Expression(new Rational(ansNum , ansDen));

	}

}

Number* Rational::getNum(){
    return this->numerator;
}

Number* Rational::getDen(){
    return this->den;
}


Expression* Rational::add(Number *r , Expression *caller)
{
	return caller;

}

Expression* Rational::subtract(Number *r , Expression *caller)
{
	return caller;

}

Expression* Rational::multiply(Number *r , Expression *caller)
{
	return caller;

}

Expression* Rational::divide(Number *r , Expression *caller)
{
	return caller;

}


void Rational::simplify()
{
	if(numerator->getType() != "Integer" || den->getType() != "Integer")
		return;

	int numerator = (int)this->numerator->getValue();
	int denominator = (int) this->den->getValue();
	
	int gcd = Rational::gcd(numerator, denominator);
	if(numerator== 0)
	{
		return ;
	}

	if(denominator== 1)
	{
		return;

	}

	if(numerator < 0 && denominator < 0)
	{
		numerator *= -1;
		denominator *= -1;
	}
	this->numerator =  new Integer(numerator / gcd);
	this->den = new Integer(denominator / gcd);	

}



