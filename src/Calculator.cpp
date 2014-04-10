//
//  Calculator.cpp
//  COP-3503-Project
//
//  Created by Justin on 4/10/14.
//
//

#include "Calculator.h"
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


/**
 * The main calculator function that takes an input and simplifies it.
 * Will store the answer for later retrieval.
 */
Calculator::calculate(string input)
{
	// First, we need to parse the input
	parseInput(input);
	
	// 
}


/**
 * Parses the input by first combining like terms over additon and subtraction,
 * then building a tree from the resulting (somewhat simplified) string.
 */
Calculator::parseInput(string& input)
{
	
}