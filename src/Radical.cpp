//
//  Radical.cpp
//  COP-3503-Project
//
//  Created by Justin on 4/9/14.
//  Editied by Tylor on 4/11/2014.
//


//TODO: Add pseudocode for coefficients


#include "Radical.h"

/**
 * Constructor
 */
Radical::Radical(/*int base, Number* radicand*/)
{
	// TODO: Create the constructor
	//int base;
	//Number* radicand;
}

void Radical::add(Number* in)
{
	//Do nothing
	cout << "Successfully recognized adding a Generic Number to a Radical" << endl;
}

void Radical::add(Constant* in)
{
	//Constant + Radical, no actual addition
	cout << "Successfully recognized adding a Constant to a Radical" << endl;
}

void Radical::add(Exponent* in)
{
	//Exponent + Radical, no actual addition
	cout << "Successfully recognized adding an Exponent to a Radical" << endl;
}

void Radical::add(Integer* in)
{
	//Integer + Radical, no actual addition
	cout << "Successfully recognized adding a integer to a Radical" << endl;
}

void Radical::add(Log* in)
{
	//Log + Radical, no actual addition
	cout << "Successfully recognized adding a Logarithm to a Radical" << endl;
}

void Radical::add(Radical* in)
{
	//Radical + Radical, no actual addition
	cout << "Successfully recognized adding a Radical to a Radical" << endl;
}

void Radical::add(Rational* in)
{
	//Rational + Radical, no actual addition
	cout << "Successfully recognized adding a Rational to a Radical" << endl;
}

//For subtract could we just call this->add(in->multiply(-1)) to decrease amount of code, since x-y == x+(y*-1)? Maybe just have a single Subtract method then?

void Radical::subtract(Number* in)
{
	//Do nothing
	cout << "Successfully recognized subtracting a Generic Number from a Radical" << endl;
}

void Radical::subtract(Constant* in)
{
	//Radical - Constant, no actual subtraction
	cout << "Successfully recognized subtracting a Constant from a Radical" << endl;
}

void Radical::subtract(Exponent* in)
{
	//Radical - Exponent, no actual subtraction
	cout << "Successfully recognized subtracting a Exponent from a Radical" << endl;
}

void Radical::subtract(Integer* in)
{
	//Radical - integer, no actual subtraction
	cout << "Successfully recognized subtracting a integer from a Radical" << endl;
}

void Radical::subtract(Log* in)
{
	//Radical - Log, no actual subtraction
	cout << "Successfully recognized subtracting a Logarithm from a Radical" << endl;
}

void Radical::subtract(Radical* in)
{
	//Radical - Radical, no actual subtraction
	cout << "Successfully recognized subtracting a Radical from a Radical" << endl;
}

void Radical::subtract(Rational* in)
{
	//Radical - Rational, no actual subtraction
	cout << "Successfully recognized subtracting a Rational from a Radical" << endl;
}


void Radical::multiply(Number* in)
{
	//Do nothing
	cout << "Successfully recognized multiplying a Generic Number to a Radical" << endl;
}

void Radical::multiply(Constant* in)
{
	//Constant*Radical, no actual multiplication
	cout << "Successfully recognized multiplying a Constant to a Radical" << endl;
}

void Radical::multiply(Exponent* in)
{
	//Exponent*Radical, no actual multiplication
	cout << "Successfully recognized multiplying a Exponent to a Radical" << endl;
}

void Radical::multiply(Integer* in)
{
	//Integer*Radical, no actual multiplication
	cout << "Successfully recognized multiplying a integer to a Radical" << endl;
}

void Radical::multiply(Log* in)
{
	//Log*Radical, no actual multiplication
	cout << "Successfully recognized multiplying a Logarithm to a Radical" << endl;
}

void Radical::multiply(Radical* in)
{
	//Radical*Radical, (IFF Bases are the same)
	//Factor each radicand and see if there are common factors. 
	//Each pair of factors gets pulled out as one integer. 
	//Integers get multiplied together and the leftover factors get multiplied together.
	//The result should be: Radical* r = new Radical(this->base, factors);
	//r->multiply(integers);
	//(If different Bases)
	//No multiplication
	
	cout << "Successfully recognized multiplying a Radical to a Radical" << endl;
}

void Radical::multiply(Rational* in)
{
	//Radical*Rational, Rational.num = this->multiply(Radical.num) This gives a rational with the radical in the numerator
	cout << "Successfully recognized multiplying a Rational to a Radical" << endl;
}


void Radical::divide(Number* in)
{
	cout << "Successfully recognized dividing a Generic Number to a Radical" << endl;
}

void Radical::divide(Constant* in)
{
	cout << "Successfully recognized dividing a Constant to a Radical" << endl;
}

void Radical::divide(Exponent* in)
{
	cout << "Successfully recognized dividing a Exponent to a Radical" << endl;
}

void Radical::divide(Integer* in)
{
	cout << "Successfully recognized dividing a integer to a Radical" << endl;
}

void Radical::divide(Log* in)
{
	cout << "Successfully recognized dividing a Logarithm to a Radical" << endl;
}

void Radical::divide(Radical* in)
{
	cout << "Successfully recognized dividing a Radical to a Radical" << endl;
}

void Radical::divide(Rational* in)
{
	cout << "Successfully recognized dividing a Rational to a Radical" << endl;
}
