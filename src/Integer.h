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
#include "Rational.h"
using namespace std;

class Integer : public Number
{
private:
	int num;
	int inputNum;
    string type;
    
public:
	Integer(); // default constructor for testing
	Integer(int inputNum);
	
	// TODO: need to implement add, subtract, etc. How do we implement this dependent upon Number subclass?
	void add(Number* n);
	int add(Integer z);

	void subtract(Number* n );
	int subtract(Integer z);

	void multiply(Number* n );
	int multiply(Integer z);

	void divide(Number* n);
//	Rational divide(Integer z);

	double getValue();
    
};

#endif /* defined(__COP_3503_Project__Integer__) */
