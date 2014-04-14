//
//  Radical.cpp
//  COP-3503-Project
//
//  Created by Justin on 4/9/14.
//  Edited by Tylor on 4/11/2014.
//


//TODO: Add pseudocode for coefficients


#include "Radical.h"

/**
 * Constructor
 */
Radical::Radical()
{

}

Radical::Radical(Number* base, Number* radicand)
{
	    this->base = base;
		this->radicand = radicand;
}


/**
 * Returns the numerical value of this object as a double
 */
double Radical::getValue()
{
	return pow(radicand->getValue(),(1/base->getValue()));
}

Expression* Radical::add(Number* num , Expression* caller)
{
	//TODO
	return caller;
}

Expression* Radical::subtract(Number* num , Expression* caller)
{
	//TODO
	return caller;
}

Expression* Radical::multiply(Number* num , Expression* caller)
{
	//TODO
	return caller;
}

Expression* Radical::divide(Number* num , Expression* caller)
{
	//TODO
	return caller;
}



	
