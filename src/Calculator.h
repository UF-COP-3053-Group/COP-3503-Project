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
#include <stdexcept>
#include <sstream>
#include <cmath>
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
	void simplifyTree(Expression*& root);
	Expression* simplifyNode(Expression* root);
	string toString(Expression* root);
	string toRPNString(Expression* root);
	double toDouble(Expression* root);
	void addAnswer(string input, Expression* answer);
	string getPreviousAnswersAsString();

private:
	vector<string> previousInputs;
	vector<Expression*> previousAnswers;
	
};

#endif /* defined(__COP_3503_Project__Calculator__) */
