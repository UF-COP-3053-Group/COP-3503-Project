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
#include "Math.h"

using namespace std;


class Number {
public:
		// Commented out for working purposes.
		//We can't create objects that don't define all of these functions and we need to for testing.
		//virtual void add(Number num) = 0; // void since actual returns should be subclasses
		//virtual void subtract() = 0;
		//virtual void multiply() = 0;
		//virtual void divide() = 0;
	
	virtual float getValue() = 0;
	virtual string getType() = 0;
	
private:
	bool negative;
	
};

#endif /* NUMBER_H_ */
