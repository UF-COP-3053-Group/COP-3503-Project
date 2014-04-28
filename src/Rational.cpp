//
//  Rational.cpp
//  COP-3503-Project
//
//  Created by Justin on 4/9/14.
//
//

#include "Rational.h"
#include <stdexcept>
#include <string>
using namespace std;

/**
 * Constructor
 */

Rational::Rational(string decimalString){
    //create a rational from a decimal number
    type = "Rational";
    if(decimalString == "0" || decimalString == "0.0")	
        throw "Division by zero is bad";
    decimalString.erase ( decimalString.find_last_not_of('0') + 1, std::string::npos );
    unsigned long places = decimalString.size() - decimalString.find_first_of(".") - 1;
    this -> den = new Integer(pow(10, places));
    
    decimalString.erase (remove(decimalString.begin(), decimalString.end(), '.'), decimalString.end());

    this -> numerator = new Integer(atoi(decimalString.c_str()));
}
Rational::Rational(Number* num, Number* den){
    type = "Rational";
    numerator = num;
    this->den = den;
    if (den->getValue() == 0)
        throw "Division by zero is bad";
	
	this->simplify();
}

Rational::Rational(Integer *i1 , Integer *i2)
{
	this->numerator = i1;
	this->den = i2;	
	type = "Rational";	
	if(den->getValue() == 0)
		throw invalid_argument("Can't divide by 0");		

	this->simplify();
}

Rational::Rational(int num , int den)
{
    	type = "Rational";
 	this->numerator = new Integer(num);
    	this->den = new Integer(den);
    	if (this->den->getValue() == 0)
        	throw  invalid_argument("Can't divide by 0");

	this->simplify();
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
	
//	delete this->numerator;
//	delete this->den;	

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
		return gcd(bot, r);	
	}
	
	// We should never get here
	throw runtime_error("Error in calculating the gcd. We should never have reached this point.");

}

//assumes the Number type of numerator and demoniator work properly.
string Rational::toString()
{
	string strNum;
    string strDen;
    string str;
    strNum = this->numerator->toString();
	strDen = this->den->toString();
    if (strNum == strDen) {
        return "1";
    }
    else if (strDen == "1") {
        return strNum;
    }
    else if (strDen == "-1"){
        str += "-";
        str += strDen;
        return str;
    }
    
    str += strNum;
    str += " / ";
    str += strDen;
	return str;

}
Number* Rational::getNum(){
    return this->numerator;
}

Number* Rational::getDen(){
    return this->den;
}


Expression* Rational::addRat(Rational *r)
{
	this->numerator = new Integer(this->numerator->getValue() * r->getDen()->getValue() + this->den->getValue() * r->getNum()->getValue());

	this->den = new Integer(this->den->getValue() * r->getDen()->getValue());
	this->simplify();
	if(this->den->getValue() == 1.0)
		return new Expression(this->numerator);		

	if((int) this->numerator->getValue() == 0)
		return new Expression(new Integer(0));


	return new Expression(this);

	

}

Expression* Rational::subtRat(Rational *r)
{
	this->numerator = new Integer(this->numerator->getValue() * r->getDen()->getValue() - this->den->getValue()*r->getNum()->getValue());
	this->den = new Integer(this->den->getValue() * r->getDen()->getValue());
	
	this->simplify();
	if(this->den->getValue() == 1.0)
		return new Expression(this->numerator);
		
	if((int) this->numerator->getValue() == 0)
		return new Expression(new Integer(0));

	return new Expression(this) ;

}


Expression* Rational::multRat(Rational* r)
{
	this->numerator = new Integer(this->numerator->getValue() * r->getNum()->getValue());
	this->den = new Integer(this->den->getValue() * r->getDen()->getValue());
	
	this->simplify();
	if(this->den->getValue() == 1.0)
		return new Expression(this->numerator);
		
	if((int) this->numerator->getValue() == 0)
		return new Expression(new Integer(0));

	return new Expression(this) ;


}

Expression* Rational::divRat(Rational* r)
{
	this->numerator = new Integer(this->numerator->getValue() * r->getDen()->getValue());
	this->den = new Integer(this->den->getValue() * r->getNum()->getValue());

	this->simplify();
	if(this->den->getValue() == 1.0)
		return new Expression(this->numerator);
		
	if((int) this->numerator->getValue() == 0)
		return new Expression(new Integer(0));

	return new Expression(this) ;



	
}

Expression* Rational::add(Number *r)
{

	if(r->getType() == "Integer")
	{
		this->numerator = new Integer(this->numerator->getValue() + this->den->getValue() * r->getValue());

		this->simplify();
		if(this->den->getValue() == 1.0)
			return new Expression(this->numerator);
		
		if((int) this->numerator->getValue() == 0)
			return new Expression(new Integer(0));

		return new Expression(this) ;
	
	}

	else if(r->getType() == "Rational")
	{
		if(dynamic_cast<Rational*>(r) != nullptr)
			return addRat(dynamic_cast<Rational*>(r));

	}
		

	throw logic_error("No oijne has written this method yet");


}

Expression* Rational::subtract(Number *r)
{
	if(r->getType() == "Integer")
	{
		this->numerator = new Integer(this->numerator->getValue() - this->den->getValue() * r->getValue());

		this->simplify()->getNumber();
		if((int)this->den->getValue()  == 1)
			return new Expression(this->numerator);
		if((int) this->numerator->getValue() == 0)
			return new Expression(new Integer(0));


		return new Expression(this);

	}
	
	else if(r->getType() == "Rational")
	{
		if(dynamic_cast<Rational*>(r) != nullptr)
			return subtRat(dynamic_cast<Rational*>(r));

	}

	
	throw logic_error("No one has written this method yet");

}

Expression* Rational::multiply(Number *r)
{
	if(r->getType() == "Integer")
	{
		this->numerator = new Integer(this->numerator->getValue() * r->getValue());
		this->simplify()->getNumber();
		if((int)this->den->getValue()  == 1)
			return new Expression(this->numerator);
		if((int) this->numerator->getValue() == 0)
			return new Expression(new Integer(0));


		return new Expression(this);


	}	

	else if (r->getType() == "Rational")
	{
		if(dynamic_cast<Rational*>(r) != nullptr)
			return multRat(dynamic_cast<Rational*>(r));

	}

	throw logic_error("No one has written this method yet");

}

Expression* Rational::divide(Number *r)
{
	if(r->getType() == "Integer")
	{
		this->den= new Integer(this->den->getValue() * r->getValue());
		this->simplify()->getNumber();
		if((int)this->den->getValue()  == 1)
			return new Expression(this->numerator);
		if((int) this->numerator->getValue() == 0)
			return new Expression(new Integer(0));


		return new Expression(this);

	}
	
	
	else if (r->getType() == "Rational")
	{
		if(dynamic_cast<Rational*>(r) != nullptr)
			return divRat(dynamic_cast<Rational*>(r));

	}


	throw logic_error("No one has written this method yet");

}


/**
 * Will exponentiate this rational by the passed Number* num
 */
Expression* Rational::exponentiate(Number* num)
{
	throw logic_error("No one has written exponentiate for Rational yet");
}


Expression* Rational::simplify()
{
	/*
	if(numerator->getType() != "Integer" || den->getType() != "Integer")
		return this;
	*/
	int numerator = (int)this->numerator->getValue();
	int denominator = (int) this->den->getValue();
	
	int gcd = Rational::gcd(numerator, denominator);
	if(numerator== 0)
	{
		return new Expression( new Integer(0));
	}

	if(denominator== 1)
	{
		return new Expression(new Integer(this->numerator->getValue())) ;

	}

	if(numerator < 0 && denominator < 0)
	{
		numerator *= -1;
		denominator *= -1;
	}
	this->numerator =  new Integer(numerator / gcd);
	this->den = new Integer(denominator / gcd);	

	return new Expression(this); 
}



