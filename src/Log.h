//
// Log.h
// COP-3503-Project
//
// Created by Justin on 4/9/14.
//
//

#ifndef __COP_3503_Project__Log__
#define __COP_3503_Project__Log__

#include <iostream>
#include "Number.h"
#include "Calculator.h"
#include "Integer.h"
#include "Constant.h"
#include "Radical.h"
#include "Expression.h"
//class Constant;
class Integer;
using namespace std;

class Log : public Number
{
private:
Number *base;
Number *argument;
public:
Log();
    Log(Number* b, Number* a);
    Log(Integer* b, Integer* a);
    //Log(Rational* base, Rational* argument);
    //Log(int base, int argument);
    //Log(Constant* base, Constant* argument);
    virtual ~Log();
double getValue();
	string toString();
Number* getBase();
Number* getArgument();
string getType();
Expression* add(Number* num);
Expression* subtract(Number* num);
Expression* multiply(Number* num);
Expression* divide(Number* num);
Expression* divide(Log* num);
Expression* exponentiate(Number* num);
bool isPrime(int n);
bool simplified();
Expression* simplify();

};

#endif /* defined(__COP_3503_Project__Log__) */
