//
//  Radical.cpp
//  COP-3503-Project
//
//  Created by Justin on 4/9/14.
//  Edited by Tylor on 4/14/2014.
//


//TODO: Add pseudocode for coefficients


#include "Radical.h"

/**
 * Constructor
 */
Radical::Radical()
{

}

Radical::Radical(Number* coefficient, Number* base, Number* radicand)
{
	    this->coefficient = coeficient;
		this->base = base;
		this->radicand = radicand;
		type = "r";
}

Radical::Radical(Number* base, Number* radicand)
{
		coefficient = new Integer(1);
	    this->base = base;
		this->radicand = radicand;
		type = "r";
}


/**
 * Returns the numerical value of this object as a double
 */
double Radical::getValue()
{
	return pow(radicand->getValue(),(1/base->getValue()));
}

Number* Radical::getBase()
{
	return base;
	Number* Radical::getCoef()
{
	return coefficient;
}

Number* Radical::getRad()
{
	return radicand;
}

string Radical::getType()
{
	return type;
}

Expression* Radical::add(Number* num , Expression* caller)
{ 
	//Hope this is right, not too sure how Expression works tbh. Will include pseudocode so I can be corrected.
	//Idea is to see if the other side is a radical, if it is, check if they have the same base and radicand, if they do, add the coefficients.
	int c = coefficient;
	if(num->getType()=="r")
	{
		if((num->getBase()->getValue()==base)&&(num->getRad()->getValue()==radicand))
		{
			c+=num->getCoef()->getValue();
			return new Expression(new Radical(c,base,radicand));
		}
	}
	return caller;
}

Expression* Radical::subtract(Number* num , Expression* caller)
{
	//Same as addition only negative
	int c = coefficient;
	if(num->getType()=="r")
	{
		if((num->getBase()->getValue()==base)&&(num->getRad()->getValue()==radicand))
		{
			c-=num->getCoef()->getValue();
			return new Expression(new Radical(c,base,radicand));
		}
	}
	return caller;
}

Expression* Radical::multiply(Number* num , Expression* caller)
{
	if(num->getType()=="r")
	{
		//If the radicands are the same, return an Integer equal to radicand*coefficient
		if(num->getRad() == radicand)
		{
			return new Expression(new Integer(radicand->getValue()*coefficient->getValue()*num->getCoef()->getValue()));
		}
		//If radicands are different return a radicand where coefficients are multiplied and the base is the same and the radicand is multiplied
		else
		{
			//Not sure about this construction. Supposed to return new Radical (coefThis*coefIn,base,radThis*radIn) but there's no way to multiply two Numbers in a way that returns a Number, right?
			return new Expression(new Radical(coefficient*num->getCoef(),base,radicand*num->getRadicand()));
		}
	}
	return caller;
}

Expression* Radical::divide(Number* num , Expression* caller)
{
	if(num->getType()=="r")
	{
		//divide the coef's and divide the radicands
		else
		{
			//Not sure about this construction. Supposed to return new Radical (coefThis*coefIn,base,radThis*radIn) but there's no way to divide two Numbers in a way that returns a Number, right?
			return new Expression(new Radical(coefficient/num->getCoef(),base,radicand/num->getRadicand()));
		}
	}
	return caller;
}



	
