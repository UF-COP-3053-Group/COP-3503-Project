//
//  Operator.h
//  COP-3503-Project
//
//  Created by Justin on 4/12/14.
//
//

#ifndef __COP_3503_Project__Operator__
#define __COP_3503_Project__Operator__

#include <iostream>
#include <stdexcept>

using namespace std;

class Operator
{
public:
	Operator(char symbol, int precedence, bool rightAssoc);
	bool isRightAssoc();
	char getSymbol();
	int getPrecedence();
	int comparePrecedence(Operator op);
	
private:
	char symbol;
	int precedence;
	bool rightAssoc;
};

#endif /* defined(__COP_3503_Project__Operator__) */
