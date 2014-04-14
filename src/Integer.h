//
//  Integer.h
//  COP-3503-Project
//
//  Created by Justin on 4/9/14.
//
//

#ifndef __COP_3503_Project__Integer__
#define __COP_3503_Project__Integer__

#include <iostream>
#include "Number.h"

using namespace std;

class Integer : public Number
{
private:
	int num;
	int inputNum;
    
public:
	Integer(); // default constructor for testing
	Integer(int);
	double getValue();
};

#endif /* defined(__COP_3503_Project__Integer__) */
