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
Radical::Radical()
{

}

Radical::Radical(int base, Number radicand)
{
	this->base = base;
	this->radicand = radicand;
}

string Radical::getSymValue()
{
	string o = "sqrt(" + getRadicand(radicand) + ")";
	return o;
}

string Radical::getRadicand(Number radicand)
{
	return "Radicand";//radicand.getValue();
}
int Radical::getBase()
{
	return base;
}

void Radical::simplify()
{
	if(/*radicand is an integer*/0)
	{
		/*factorize the radicand, if a factor is repeated this->base times, pull out the factor. When done multiply the pulled out factors together and then call this->multiply(pulled factors)*/
	}
	else if(/*radicand is an exponent*/0)
	{
		/*divide the exponent by the radicand. the result is the new exponent.*/
	}
	else if(/*radicand is a rational*/0)
	{
		/*sqrt(a/b)==sqrt(a)/sqrt(b)*/
	}
	//If statements have a 0 for testing and compilation purposes. This way this method does nothing but cout a message.
}
//couts are only for testing
void Radical::add(Number* in)
{
	//Do nothing
	cout << "Successfully recognized adding a Generic Number to a Radical" << endl;
}

void Radical::add(Constant* in)
{
	//Constant + Radical, just call this.add(in);
	cout << "Successfully recognized adding a Constant to a Radical" << endl;
}

void Radical::add(Exponent* in)
{
	//Exponent + Radical, just call this.add(in);
	cout << "Successfully recognized adding an Exponent to a Radical" << endl;
}

void Radical::add(Integer* in)
{
	//Integer + Radical, just call this.add(in);
	cout << "Successfully recognized adding a integer to a Radical" << endl;
}

void Radical::add(Log* in)
{
	//Log + Radical, just call this.add(in);
	cout << "Successfully recognized adding a Logarithm to a Radical" << endl;
}

void Radical::add(Radical* in)
{
	//Radical + Radical, just call this.add(in);
	cout << "Successfully recognized adding a Radical to a Radical" << endl;
}

void Radical::add(Rational* in)
{
	//Rational + Radical, just call this.add(in);
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
	//Radical - Constant, just call this.subtract(<Number*>in);
	cout << "Successfully recognized subtracting a Constant from a Radical" << endl;
}

void Radical::subtract(Exponent* in)
{
	//Radical - Exponent, just call this.subtract(<Number*>in);
	cout << "Successfully recognized subtracting a Exponent from a Radical" << endl;
}

void Radical::subtract(Integer* in)
{
	//Radical - integer, just call this.subtract(<Number*>in);
	cout << "Successfully recognized subtracting a integer from a Radical" << endl;
}

void Radical::subtract(Log* in)
{
	//Radical - Log, just call this.subtract(<Number*>in);
	cout << "Successfully recognized subtracting a Logarithm from a Radical" << endl;
}

void Radical::subtract(Radical* in)
{
	//Radical - Radical, just call this.subtract(<Number*>in);
	cout << "Successfully recognized subtracting a Radical from a Radical" << endl;
}

void Radical::subtract(Rational* in)
{
	//Radical - Rational, just call this.subtract(<Number*>in);
	cout << "Successfully recognized subtracting a Rational from a Radical" << endl;
}


void Radical::multiply(Number* in)
{
	//Do nothing
	cout << "Successfully recognized multiplying a Generic Number to a Radical" << endl;
}

void Radical::multiply(Constant* in)
{
	//Constant*Radical, just call this.multiply(<Number*>in);
	cout << "Successfully recognized multiplying a Constant to a Radical" << endl;
}

void Radical::multiply(Exponent* in)
{
	//Exponent*Radical, just call this.multiply(<Number*>in);
	cout << "Successfully recognized multiplying a Exponent to a Radical" << endl;
}

void Radical::multiply(Integer* in)
{
	//Integer*Radical, just call this.multiply(<Number*>in);
	cout << "Successfully recognized multiplying a integer to a Radical" << endl;
}

void Radical::multiply(Log* in)
{
	//Log*Radical, just call this.multiply(<Number*>in);
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
	if(in->getBase() != base)
	{
		//multiply(Number in);
	}
	cout << "Successfully recognized multiplying a Radical to a Radical" << endl;
}

void Radical::multiply(Rational* in)
{
	//Radical*Rational, Rational.numerator = this->multiply(Radical.numerator) This gives a rational with the radical in the numerator
	cout << "Successfully recognized multiplying a Rational to a Radical" << endl;
}


void Radical::divide(Number* in)
{
	//Radical/Number, gives back a rational where numerator = radical and denominator = in
	cout << "Successfully recognized dividing a Generic Number to a Radical" << endl;
}

void Radical::divide(Constant* in)
{
	//Radical/Constant, gives back a rational where numerator = radical and denominator = in
	cout << "Successfully recognized dividing a Constant to a Radical" << endl;
}

void Radical::divide(Exponent* in)
{
	//Radical/Exponent, gives back a rational where numerator = radical and denominator = in
	cout << "Successfully recognized dividing a Exponent to a Radical" << endl;
}

void Radical::divide(Integer* in)
{
	//Radical/Integer, gives back a rational where numerator = radical and denominator = in
	//EXCEPTION IF: in=0
	//Special case if(in==1) return just the radical
	cout << "Successfully recognized dividing a integer to a Radical" << endl;
}

void Radical::divide(Log* in)
{
	//Radical/Log, gives back a rational where numerator = radical and denominator = in
	cout << "Successfully recognized dividing a Logarithm to a Radical" << endl;
}

void Radical::divide(Radical* in)
{
	//Radical/Radical
	//If bases are same, make a radical with the radicands such that numerator=this.radicand and denominator=in.radicand
	//this.radicand=(simplified rational)
	//If bases are different: Gives back a rational where numerator = radical and denominator = in
	cout << "Successfully recognized dividing a Radical to a Radical" << endl;
}

void Radical::divide(Rational* in)
{
	//Radical/Rational, gives back a rational where numerator = radical*in.denominator and denominator = in.numerator
	cout << "Successfully recognized dividing a Rational to a Radical" << endl;
}

void Radical::exponentiate(Rational power){
    //requires unique code
}

void Radical::exponentiate(Integer power){
    //if (power.getInt() == radicand.getValue()) {
        //return base
    //}
    //requires unique code
}

string Radical::getType()
{
	return "r";
}
