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
public:
	Integer(); // default constructor for testing
	Integer(int);
	
	// TODO: need to implement add, subtract, etc. How do we implement this dependent upon Number subclass?
	void add(Number);
	void add(Integer);

	void subtract(Number);
	void subtract(Integer);

	void multiply(Number);
	void multiply(Integer);

	void divide(Number);
	void divide(Integer);

private:
	int num;
};

#endif /* defined(__COP_3503_Project__Integer__) */
