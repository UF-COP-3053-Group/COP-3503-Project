//
//  Radical.h
//  COP-3503-Project
//
//  Created by Justin on 4/9/14.
//  Edited by Tylor on 4/14/2014.
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
	Number* coefficient;
    
public:
	Radical();
    Radical(Number* coefficient, Number* base, Number* radicand);
    Radical(Number* base, Number* radicand);
	
	double getValue();
	string toString();

	Expression* add(Number* num , Expression* caller);
	Expression* subtract(Number* num , Expression* caller);
	Expression* multiply(Number* num , Expression* caller);
	Expression* divide(Number* num , Expression* caller);

};

#endif /* defined(__COP_3503_Project__Radical__) */
