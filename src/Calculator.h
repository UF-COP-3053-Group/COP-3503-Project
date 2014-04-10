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

using namespace std;

// The main tree node structure used to store data
struct node
{
	char op;
	Number num;
	node* left;
	node* right;
};

class Calculator
{
public:
	Calculator();
	~Calculator();
	void calculate(string input);
	node* parseInput(string& input);
	string collectTerms(string& input);
	node* createTree(string input);

private:
	vector<node*> previousAnswers;
	
};

#endif /* defined(__COP_3503_Project__Calculator__) */
