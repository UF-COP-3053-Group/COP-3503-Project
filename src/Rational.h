//
//  Rational.h
//  COP-3503-Project
//
//  Created by Justin on 4/9/14.
//
//

#ifndef __COP_3503_Project__Rational__
#define __COP_3503_Project__Rational__

//#include <iostream>

#include "Number.h"
#include "Integer.h"
#include "Constant.h"
#include "Radical.h"

class Constant;
class Integer;

using namespace std;

class Rational : public Number
{
private:
    Number numerator;
    Number denom;
    
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
	Number getNum();
	Number getDen();
};

#endif /* defined(__COP_3503_Project__Rational__) */
