/*
 * Number.h
 *
 *  Created on: Apr 8, 2014
 *      Author: kyle
 *      
 */

#ifndef NUMBER_H_
#define NUMBER_H_

#include <iostream>
#include <string>
#include <stdexcept>
#include "Expression.h"

using namespace std;

class Expression;

class Number
{
public:
	virtual Expression* add(Number* num, Expression* caller) = 0;
	virtual double getValue() = 0;
	virtual string getType();
	bool negative;
	string type;
};

#endif /* NUMBER_H_ */
