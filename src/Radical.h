//
// Radical.h
// COP-3503-Project
//
// Created by Justin on 4/9/14.
// Edited by Tylor on 4/11/2014.
//

#ifndef __COP_3503_Project__Radical__
#define __COP_3503_Project__Radical__

#include <iostream>
#include "Number.h"

using namespace std;

class Radical : public Number
{
private:
    string type;
Number* base;
Number* radicand;
    
public:
Radical();
    Radical(Number* base, Number* radicand);

double getValue();
string toString();

Expression* add(Number* num);
Expression* subtract(Number* num);
Expression* multiply(Number* num);
Expression* divide(Number* num);
Expression* exponentiate(Number* num);

};

#endif /* defined(__COP_3503_Project__Radical__) */
