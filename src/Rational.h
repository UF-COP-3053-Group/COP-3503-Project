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
	Rational(Integer *i1 , Integer *i2);
	Rational(int num, int den);
	virtual ~Rational();
	Expression* simplify();
	int gcd(int c , int d);
	Number* getNum();
	Number* getDen();
	
	Expression* addRat(Rational *r);
	Expression* subtRat(Rational *r);	
	Expression* multRat(Rational *r);
	Expression* divRat(Rational *r);


	Expression* add(Number *r);
	Expression* subtract(Number *r);
	Expression* multiply(Number *r);
	Expression* divide(Number *r);


	string toString();

	
	string getType();
	double getValue();
};

#endif /* defined(__COP_3503_Project__Rational__) */
