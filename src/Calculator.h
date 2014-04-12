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
#include <vector>
#include "Number.h"
#include "Rational.h"
#include "Expression.h"

using namespace std;

class Calculator
{
public:
	Calculator();
	~Calculator();
	void calculate(string input);
	expression* parseInput(string& input);
	string collectTerms(string& input);
	expression* createTree(string input);

private:
	vector<expression*> previousAnswers;
	
};

#endif /* defined(__COP_3503_Project__Calculator__) */
