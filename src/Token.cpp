//
//  Token.cpp
//  COP-3503-Project
//
//  Created by Justin on 4/12/14.
//
//

#include "Token.h"

/**
 * Constructor for a number
 */
Token::Token(Number* number)
{
	this->number = number;
	this->is_number = true;
	this->is_operator = false;
	this->paren = '\0';
}


/**
 * Constructor for an operator
 */
Token::Token(Operator op)
{
	this->op = op;
	this->is_number = false;
	this->is_operator = true;
	this->paren = '\0';
}


/**
 * Constructor for a parenthesis
 */
Token::Token(char paren)
{
	this->is_number = false;
	this->is_operator = false;
	this->paren = paren;
}


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


/**
 * Retuns true if this token is a left parenthesis
 */
bool Token::isLeftParen()
{
	return this->paren == '(';
}


/**
 * Retuns true if this token is a right parenthesis
 */
bool Token::isRightParen()
{
	return this->paren == ')';
}
