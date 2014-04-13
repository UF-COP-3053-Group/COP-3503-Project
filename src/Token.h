//
//  Token.h
//  COP-3503-Project
//
//  Created by Justin on 4/12/14.
//
//

#ifndef __COP_3503_Project__Token__
#define __COP_3503_Project__Token__

#include <iostream>
#include "Number.h"
#include "Operator.h"

class Token
{
public:
	bool isNumber();
	bool isOperator();
	Number number;
	Operator op;

private:
	bool is_number;
	bool is_operator;
};

#endif /* defined(__COP_3503_Project__Token__) */
