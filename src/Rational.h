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
//WARNING: circular dependency?
#include "Constant.h"
#include "Rational.h"
#include "Radical.h"

class Constant;

using namespace std;

class Rational : public Number
{
private:
    //**************
	Number num;
    Number denom;
    //**************
    
public:
    //**************
    Rational(Number num, Number denom);
    //**************
	Rational(int num, int den);
	virtual ~Rational();
	void simplify();
	int gcd(int a , int b);
	int getNum();
	int getDen();
	void setNum(int n);
	void setDen(int n);
	Integer *rationalToInt(int);	
	// TODO: need to implement add, subtract, etc. How do we implement this dependent upon Number subclass?

	//should this return a new Rational number? If so, how will we overload ? 
	void add(Rational);
	void add(Number);
	void add(Constant);
	void add(Integer);	

	void subtract(Rational);
	

	void multiply(Rational);

	void divide(Rational);
    
    void exponentiate(Rational power);
    void exponentiate(Integer power);
	/*void add(Number);
	void add(Constant);
	void add(Exponent);
	void add(Integer);
	void add(Log);
	void add(Radical);
	void add(Rational);

	
	void subtract(Number);
	void subtract(Constant);
	void subtract(Exponent);
	void subtract(Integer);
	void subtract(Log);
	void subtract(Radical);
	void subtract(Rational);

	void multiply(Number);
	void multiply(Constant);
	void multiply(Exponent);
	void multiply(Integer);
	void multiply(Log);
	void multiply(Radical);
	void multiply(Rational);

	void divide(Number);
	void divide(Constant);
	void divide(Exponent);
	void divide(Integer);
	void divide(Log);
	void divide(Radical);
	void divide(Rational);*/

};

#endif /* defined(__COP_3503_Project__Rational__) */
