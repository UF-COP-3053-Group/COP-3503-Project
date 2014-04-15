//
//  Log.h
//  COP-3503-Project
//
//  Created by Justin on 4/9/14.
//
//

#ifndef __COP_3503_Project__Log__
#define __COP_3503_Project__Log__

#include <iostream>
#include "Number.h"
#include "Calculator.h" //if this is going to use the parser, we need to include the Calculator class

using namespace std;

class Log : public Number
{
private:
    string type;
	Number* base;
	Number* argument;
	Calculator calc;
    
public:
	Log();
    Log(Number* base, Number* argument);
	double getValue();
	Number* getBase();
	Number* getArgument();

	string toString();
	Expression* add(Number* num, Expression* caller);
	Expression* subtract(Number* num, Expression* caller);
	Expression* multiply(Number* num, Expression* caller);
	Expression* divide(Number* num, Expression* caller);

	Expression* simplify();

	bool isPrime(int n);

};

#endif /* defined(__COP_3503_Project__Log__) */
