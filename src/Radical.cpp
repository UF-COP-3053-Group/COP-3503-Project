//
// Radical.cpp
// COP-3503-Project
//
// Created by Justin on 4/9/14.
// Edited by Tylor on 4/11/2014.
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
type = "rad";
	this->base = base;
    this->radicand = radicand;
}

Number* Radical::getBase()
{
	return this->base;
}
Number* Radical::getRadicand()
{
	return this->radicand;
}
/**
* Returns the numerical value of this object as a double
*/
double Radical::getValue()
{
return pow(radicand->getValue(),(1/base->getValue()));
}

Expression* Radical::add(Number* num)
{
//TODO
throw logic_error("No one has built this method yet");
}

Expression* Radical::subtract(Number* num)
{
//TODO
throw logic_error("No one has built this method yet");
}

Expression* Radical::multiply(Number* num)
{
//TODO
throw logic_error("No one has built this method yet");
}

Expression* Radical::divide(Number* num)
{
//TODO
throw logic_error("No one has built this method yet");
}


/**
 * Will exponentiate this radical by the passed Number* num
 */
Expression* Radical::exponentiate(Number* num)
{
	throw logic_error("No one has written exponentiate for Radical yet");
}


string Radical::toString()
{
	string str;
    if (this->radicand->getValue() == 2)
        str += "sq";
    else
        str += radicand->toString();
    str += "rt:";
    str += this->base->toString();
    return str;
}



