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



using namespace std;


class Constant : public Number
{
private:
	string name;
    string type;
    
public:
	Constant(string name);
	bool isKnown(string name);
	double getValue();
	string getName();


	Expression *add(Number* num , Expression *caller);
	Expression *subtract(Number* num , Expression *caller);
	Expression *multiply(Number* num , Expression *caller);
	Expression *divide(Number* num , Expression *caller);

	string toString();


	
};

#endif /* defined(__COP_3503_Project__Constant__) */
