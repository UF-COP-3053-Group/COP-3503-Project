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
	
	Expression* add(Number* num);
	Expression*  subtract(Number* num);
	Expression*  multiply(Number* num);
	Expression*  divide(Number* n);
	Expression* exponentiate(Number* num);

	double getValue();

	string toString();
    
};

#endif /* defined(__COP_3503_Project__Integer__) */
