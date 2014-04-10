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

#include "Number.h"
#include "Exponent.h"
#include "Integer.h"
#include "Log.h"
#include "Radical.h"
#include "Rational.h"

using namespace std;

class Constant : public Number
{
public:
	Constant(string name);
	bool isKnown(string name);
	double getValue();
	string getName();
	
	// TODO: need to implement add, subtract, etc. How do we implement this dependent upon Number subclass?
	void add(Number num);
	void add(Integer num);
	void add(Radical num);

	
private:
	string name;
};

#endif /* defined(__COP_3503_Project__Constant__) */
