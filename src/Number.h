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
	virtual double getValue();
	virtual string getType();
	
private:
	bool negative;
	string type = "Number";
};

#endif /* NUMBER_H_ */
