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
#include "Rational.h"
#include "Radical.h"

using namespace std;

class Log : public Number
{
private:
    //**************
    Number base;
    Number argument;
    //**************
    
public:
	Log();
    //**************
    Log(Number b, Number a);
    void simplify();
    //Log(Number*, Number*);
    //Log(Number*, Number);
    //Log(Number, Number*);
    //**************
    void exponentiate(Rational power);
    void exponentiate(Integer power);
	
	// TODO: need to implement add, subtract, etc. How do we implement this dependent upon Number subclass?
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

#endif /* defined(__COP_3503_Project__Log__) */
