//
//  Constant.h
//  COP-3503-Project
//
//  Created by Justin on 4/9/14.
//
//

#ifndef __COP_3503_Project__Constant__
#define __COP_3503_Project__Constant__

#include <iostream>
#include <string>
#include <stdexcept>
// Allow M_PI and M_E defines to be accessed on platforms that provide the definitions.
#define _USE_MATH_DEFINES
#include <math.h>

// Needed for std::transform
#include <algorithm>

//Include Numbers
#include "Number.h"
#include "Rational.h"
#include "Integer.h"

// Foward declarations to prevent errors referencing classes
class Integer;

using namespace std;


class Constant : public Number
{
public:
	Constant(string name);
	Constant(string name, Number* coefficient, Number* exponent);
	bool isKnown(string name);
	double getValue();
	string getName();

	Expression* add(Constant* num);
	Expression* add(Number* num);
	
	Expression* subtract(Number* num);
	Expression* subtract(Constant* num);
	
	Expression* multiply(Number* num);
	Expression* multiply(Constant *num);
	Expression* multiply(Integer* num);
	
	Expression* divide(Number* num);
	Expression* divide(Constant* num);
	Expression* divide(Integer* num);
	
	Expression* exponentiate(Number *num);
	
	Number* getCoefficient();
	Number* getExponent();
	void setCoefficient(Number* coefficient);
	void setExponent(Number* exponent);

	string toString();

private:
	string name;
    string type;
	Number* coefficient;
	Number* exponent;
	
};

#endif /* defined(__COP_3503_Project__Constant__) */
