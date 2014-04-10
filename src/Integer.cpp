//
//  Integer.cpp
//  COP-3503-Project
//
//  Created by Justin on 4/9/14.
//
//

#include "Integer.h"

/**
 * Constructor
 */
Integer::Integer()
{
	// TODO: Create the constructor
}

void Integer::add(Number num)
{
	cout << "Successfully recognized adding a generic Number to this Integer" << endl; //all outputs here are for testing only
	// Do nothing
}

void Integer::add(Integer num)
{
	cout << "Successfully recognized adding an Integer to this Integer" << endl;
	// Add integers. Easy. Depending on how we handle output blah blah blah
}

void Integer::subtract(Number num)
{
	cout << "Successfully recognized subtracting a generic Number from this Integer" << endl;
	// Do nothing
}

void Integer::subtract(Integer num)
{
	cout << "Successfully recognized subtracting an Integer from this Integer" << endl;
	// Subtract integers
}

void Integer::multiply(Number num)
{
	cout << "Successfully recognized multiplying a generic Number and this Integer" << endl;
	// if coefficient == 1, do nothing
	// else multiply coefficient with Integer
}

void Integer::multiply(Integer num)
{
	cout << "Successfully recognized multiplying an Integer and this Integer" << endl;
	// Go forth and multiply!
}

void Integer::divide(Number num)
{
	cout << "Successfully recognized dividing this Integer by a generic Number. Or vice versa" << endl;
	// divide coefficients
}

void Integer::divide(Integer num)
{
	cout << "Successfully recognized dividing this Integer by an Integer" << endl;
	// divide
}
