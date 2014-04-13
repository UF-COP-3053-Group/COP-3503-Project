//
//  Token.cpp
//  COP-3503-Project
//
//  Created by Justin on 4/12/14.
//
//

#include "Token.h"



/**
 * Returns true if this token is a number
 */
bool Token::isNumber()
{
	return this->is_number;
}


/**
 * Returns true if this token is an operator
 */
bool Token::isOperator()
{
	return this->is_operator;
}