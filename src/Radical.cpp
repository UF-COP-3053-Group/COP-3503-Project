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
    this->coefficient = new Integer(1);
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
    return new Expression('+', new Expression(this), new Expression(num));
}

Expression* Radical::subtract(Number* num)
{
//TODO
    return new Expression('-', new Expression(this), new Expression(num));
}

Expression* Radical::multiply(Number* num)
{
//TODO
    return new Expression('*', new Expression(this), new Expression(*num->multiply(coefficient)));
}

Expression* Radical::divide(Number* num)
{
//TODO
    return new Expression(new Rational(this , num));
}

/**
 * Will exponentiate this radical by the passed Number* num
 */
Expression* Radical::exponentiate(Number* num)
{
	if (num->getValue() == this->radicand->getValue()) {
        return new Expression(base);
    }
    else
        return new Expression('^', new Expression(base), new Expression(new Rational(num, this->radicand)));
}


string Radical::toString()
{
	string str;
    if (coefficient->getValue() != 1) {
        str = coefficient->toString();
        str += " ";
    }
    if (this->radicand->getValue() == 2)
        str += "sq";
    else
        str += radicand->toString();
    str += "rt:";
    str += this->base->toString();
    return str;
}



