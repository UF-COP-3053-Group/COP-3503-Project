//
//  Parser.h
//  COP-3503-Project
//
//  Created by Justin on 4/12/14.
//
//

#ifndef __COP_3503_Project__Parser__
#define __COP_3503_Project__Parser__

#include <iostream>
#include <stdexcept>
#include <stack>
#include <sstream>
#include <vector>
#include <ctype.h>
#include "Expression.h"
#include "Token.h"

using namespace std;

/**
 * This parser class implements the shunting yard algorithm as a way to obtain
 * an abstract syntax tree from a given infix notation mathematical expression
 */
class Parser
{
public:
	Expression* createAST(vector<Token> tokens);
	vector<Token> tokenize(string input);
	
private:
	
};

#endif /* defined(__COP_3503_Project__Parser__) */
