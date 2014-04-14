//
//  Constant.cpp
//  COP-3503-Project
//
//  Created by Justin on 4/9/14.
//
//


#include "Constant.h"

// Check the definitions of our constants
// pi
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
// e
#ifndef M_E
#define M_E 2.7182818284590452354
#endif


/**
 * Constructor
 * Args: <string> name: The name of the constant, e.g. pi or e
 */
Constant::Constant(string name)
{
	// First, convert name string to lowercase
	transform(name.begin(), name.end(), name.begin(), ::tolower);

	// If we don't know the constant, throw an exception
	if (!isKnown(name))
	{
		throw invalid_argument(name + " is not a known constant.");
	}

	// Set the name of the constant
	this->name = name;
}


/**
 * Function to check if a constant is one understood by our program
 * Args: <string> name: the lowercase name of the constant to check
 */
bool Constant::isKnown(string name)
{
	// C++ doesn't allow string switching, so a chain of if - else if is used instead.
	if (name == "pi")
		return true;

	else if (name == "e")
		return true;

	else
		return false;
}

/**
 * Function to get the decimal value of this current constant.
 * Doubles as a way to initilize the value in the constructor and as a value getter
 */
double Constant::getValue()
{
	/*
	 C++ doesn't allow string switching, so a chain of if - else if is used instead.
	 Each constant first trys to return the value as defined by the platform's math.h, 
	 and then reverts to a hard-coded 32-bit double definition if not found.
	 */
	if (name == "pi")
		return M_PI;

	else if (name == "e")
		return M_E;

	// Should never be encountered, as we check if the constant is known during construction
	else
		throw runtime_error("How did we get here? Error getting the value of constant: " + this->name);
}

/**
 * Returns the name of this constant, e.g. pi or e
 * return: <string> name
 */
string Constant::getName()
{
	return this->name;
}

<<<<<<< HEAD
=======
void Constant::add(Number num)
{
	cout << "Successfully caught a generic Number" << endl;
	// Will catch types where there are no special rules
}
void Constant::add(Integer num)
{
	cout << "Successfully recognized an Integer" << endl;
	// testing only, in real life should just go to add(Number num)
}
void Constant::add(Radical num)
{
	cout << "Successfully recognized a Radical" << endl;
	// testing only, in real life should just go to add(Number num)
}

void Constant::add(Constant num)
{
	// This implementation assumes that a coefficient will result in that many separate constant objects.
	// Further implementation requires knowledge of parser inputs and outputs.
	// Alternatively, we could use something along these lines and return 2 Numbers (one for coefficient, one for constant):
	// void Constant:add(Constant num, Integer& coefficient, Constant& constant);
	cout << "Successfully recognized a Constant" << endl;
	if(getName() == num.getName()) {
		// return Number (2 * e) ?
		cout << "2 * " << num.getName() << endl; // testing
	}
	else {
		// do nothing...?
		cout << getName() << "+" << num.getName() << endl;
	}

}


void Constant::subtract(Number num)
{
	cout << "Successfully recognized subtracting a generic Number" << endl;
	// no change
}

void Constant::subtract(Constant num)
{
	cout << "Successfully recognized subtracting a Constant" << endl;
	if(getName() == num.getName()) {
		// return Integer 0? Will depend on parser and how we will return values to it
		cout << "0" << endl; // testing if statement
	}
	else {
		// do nothing...?
		cout << getName() << "-" << num.getName() << endl;
	}
}

void Constant::multiply(Number num)
{
	cout << "Successfully recognized multiplying a generic Number" << endl;
	//no change
}

void Constant::multiply(Constant num)
{
	cout << "Successfully recognized multiplying a constant" << endl;

	if(getName() == num.getName()) {
		// return Exponent?
		cout << num.getName() << "^2" << endl; // testing if statement
	}
	else {
		// do nothing...?
		cout << getName() << "*" << num.getName()  << endl; //testing if statement
	}
}

void Constant::divide(Number num)
{
	cout << "Successfully recognized dividing a generic Number" << endl;
}

void Constant::divide(Constant num)
{
	cout << "Successfully recognized dividing a Constant" << endl;
	if(getName() == num.getName()) {
		// return Integer 1?
		cout << "1" << endl; // testing if statement
	}
	else {
		// do nothing...?
		cout << getName() << "/" << num.getName()  << endl; //testing if statement
	}
}

Radical Constant::exponentiate(Rational power){
    //formating to be determined
	Radical result = Radical(power.getDen(), *this);
	return result;
}

void Constant::exponentiate(Integer power){
    //formatting to be determined

}

string Constant::getType()
{
	return "c";
}
>>>>>>> 40773ff532c3a7ab8062ddec51b7f0aa00c21353
