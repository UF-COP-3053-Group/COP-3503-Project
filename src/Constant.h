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

using namespace std;

class Constant
{
public:
	Constant(string name);
	bool isKnown(string name);
	double getValue();
	string getName();
	
private:
	string name;
};

#endif /* defined(__COP_3503_Project__Constant__) */
