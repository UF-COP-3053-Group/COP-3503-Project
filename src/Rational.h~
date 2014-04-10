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

using namespace std;

class Rational : public Number
{
public:
	Rational(int num, int den);
	virtual ~Rational();
	void simplify();
	int gcd(int a , int b);
	int getNum();
	int getDen();	
	// TODO: need to implement add, subtract, etc. How do we implement this dependent upon Number subclass?

private:
	int num , den;

};

#endif /* defined(__COP_3503_Project__Rational__) */
