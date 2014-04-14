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

using namespace std;

class Radical : public Number
{
private:
    string type;
    
public:
	Radical();
    Radical(Number* base, Number* radicand);
	
	double getValue();

	Expression* add(Number* num , Expression* caller);
	Expression* subtract(Number* num , Expression* caller);
	Expression* multiply(Number* num , Expression* caller);
	Expression* divide(Number* num , Expression* caller);

};

#endif /* defined(__COP_3503_Project__Radical__) */
