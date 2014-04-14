//
//  Rational.h
//  COP-3503-Project
//
//  Created by Justin on 4/9/14.
//
//

#ifndef __COP_3503_Project__Rational__
#define __COP_3503_Project__Rational__

#include <iostream>

#include "Number.h"
#include "Integer.h"
#include "Constant.h"
#include "Radical.h"
#include "Expression.h"
class Constant;
class Integer;

using namespace std;

class Rational : public Number
{
private:
    Number *numerator;
    Number *den;
    
public:
    Rational(string decimalString);
    Rational(Number* num, Number* den);
    Rational(Rational* num, Number* den);
    Rational(Number* num, Rational* den);
    Rational(Rational* num, Rational* den);
	Rational(int num, int den);
	virtual ~Rational();
	void simplify();
	Integer gcd(Integer c , Integer d);
	Number* getNum();
	Number* getDen();

	Expression* add(Number *r , Expression *caller);
	Expression* subtract(Number *r , Expression *caller);
	Expression* multiply(Number *r , Expression* caller);
	Expression* divide(Number *r , Expression* caller);


	//overloads
	Expression* add(Rational *r , Expression *caller);
	Expression* subtract(Rational *r , Expression *caller);
	Expression* multiply(Rational *r , Expression* caller);
	Expression* divide(Rational *r , Expression* caller);


	
	string getType();
	double getValue();
};

#endif /* defined(__COP_3503_Project__Rational__) */
