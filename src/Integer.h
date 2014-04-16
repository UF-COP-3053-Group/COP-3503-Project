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
#include "Expression.h"
using namespace std;

class Integer : public Number
{
private:
	int inputNum;
    string type;
    
public:
	Integer(); // default constructor for testing
	Integer(int inputNum);
	
	// TODO: need to implement add, subtract, etc. How do we implement this dependent upon Number subclass?
	Expression* add(Number* num);
//	Expression* add(Number* z);
	string getType();
	Expression*  subtract(Number* num);
//	Expression* subtract(Integer* z);

	Expression*  multiply(Number* num);
//	Expression* multiply(Integer* z);

	Expression*  divide(Number* n);
//	Expression* divide(Integer* z);

	double getValue();

	string toString();
    
};

#endif /* defined(__COP_3503_Project__Integer__) */
