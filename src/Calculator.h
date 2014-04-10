//
//  Calculator.h
//  COP-3503-Project
//
//  Created by Justin on 4/10/14.
//
//

#ifndef __COP_3503_Project__Calculator__
#define __COP_3503_Project__Calculator__

#include <iostream>
#include "Number.h"

using namespace std;

class Calculator
{
public:
	Calculator();
	~Calculator();
	void calculate(string input);
	void parseInput(string& input);
	
	
};

#endif /* defined(__COP_3503_Project__Calculator__) */
