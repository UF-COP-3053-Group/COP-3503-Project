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
#include <sstream>
#include <stdexcept>
#include <cmath>
#include <algorithm>
#include "Expression.h"

using namespace std;

class Expression;

class Number
{
public:
	virtual Expression* add(Number* num) = 0;
	virtual Expression* subtract(Number* num) = 0;
	virtual Expression* multiply(Number* num) = 0;
	virtual Expression* divide(Number* num) = 0;
	virtual Expression* exponentiate(Number* num) = 0;
	
	virtual double getValue() = 0;
	virtual string toString() = 0;
	virtual string getType();
	string type;
};

#endif /* NUMBER_H_ */
