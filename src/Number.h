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

using namespace std;


class Number
{
public:	
	virtual double getValue() = 0;
	virtual string getType();
	bool negative;
	string type;
};

#endif /* NUMBER_H_ */
