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
#include "Number.h"
#include <string>
#include "Number.h"


using namespace std;

class Constant : public Number
{
public:
	Constant(string name);
	bool isKnown(string name);
	double getValue();
	string getName();
	// TODO: need to implement add, subtract, etc. How do we implement this dependent upon Number subclass?
	
private:
	string name;
};

#endif /* defined(__COP_3503_Project__Constant__) */
