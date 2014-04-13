//
//  Expression.h
//  COP-3503-Project
//
//  Created by Justin on 4/12/14.
//
//

#ifndef COP_3503_Project_Expression_h
#define COP_3503_Project_Expression_h

#include <iostream>
#include "Number.h"
#include "Operator.h"

/**
 * The main tree node structure used to store data
 * Stores a root and pointers to the left hand side and right hand side of an expression,
 * both of which are expressions themselves.
 */
class Expression
{
public:
	Expression(Number num);
	Expression(Operator op, Expression* leftNode, Expression* rightNode);
	~Expression();
	Number getNumber();
	char getOperatorSymbol();
	bool isNumber();
	void deleteExpressionTree(Expression* node);
	
private:
	Operator op;
	Number num;
	Expression* left;
	Expression* right;
};

#endif
