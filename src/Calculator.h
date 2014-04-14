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
#include "Parser.h"
#include "Number.h"
#include "Rational.h"
#include "Expression.h"

using namespace std;

class Calculator
{
public:
	Calculator();
	~Calculator();
	
	vector<Expression*> getPreviousAnswers();
	Expression* getLastAnswer();
	Expression* calculate(string input);
	Expression* parseInput(string& input);
	string collectTerms(string& input);
	void simplifyTree(Expression* root);
	string toString(Expression* root);
	void defineOperators();

private:
	vector<Expression*> previousAnswers;
	
};

#endif /* defined(__COP_3503_Project__Calculator__) */
