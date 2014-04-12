//
//  Radical.h
//  COP-3503-Project
//
//  Created by Justin on 4/9/14.
//  Editied by Tylor on 4/11/2014.
//

#ifndef __COP_3503_Project__Radical__
#define __COP_3503_Project__Radical__

#include <iostream>

#include "Number.h"
#include "Integer.h"
#include "Radical.h"
#include "Rational.h"
#include <string>

using namespace std;

class Constant;
class Exponent;
class Integer;
class Log;
class Rational;

class Radical : public Number
{
public:
	Radical(int,Number*);
	Radical();
    
    void exponentiate(Rational power);
    void exponentiate(Integer power);
	
	// TODO: All implemented, need to finish adding rules for multiply and divide. 
	string getSymValue();
	string getRadicand(Number* radicand);
	void simplify();
	int getBase();
	
	void add(Number*);
	void add(Constant*);
	void add(Exponent*);
	void add(Integer*);
	void add(Log*);
	void add(Radical*);
	void add(Rational*);

	void subtract(Number*);
	void subtract(Constant*);
	void subtract(Exponent*);
	void subtract(Integer*);
	void subtract(Log*);
	void subtract(Radical*);
	void subtract(Rational*);

	void multiply(Number*);
	void multiply(Constant*);
	void multiply(Exponent*);
	void multiply(Integer*);
	void multiply(Log*);
	void multiply(Radical*);
	void multiply(Rational*);

	void divide(Number*);
	void divide(Constant*);
	void divide(Exponent*);
	void divide(Integer*);
	void divide(Log*);
	void divide(Radical*);
	void divide(Rational*);
	
private:
	int base;
	Number* radicand;
	
};

#endif /* defined(__COP_3503_Project__Radical__) */
