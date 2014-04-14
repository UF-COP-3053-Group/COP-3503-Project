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

using namespace std;


class Number {
public:
		// Commented out for working purposes.
		//We can't create objects that don't define all of these functions and we need to for testing.
		//virtual void add(Number num) = 0; // void since actual returns should be subclasses
		//virtual void subtract() = 0;
		//virtual void multiply() = 0;
		//virtual void divide() = 0;
	
	virtual double getValue();
	virtual string getType();
	
private:
	bool negative;
	
};

#endif /* NUMBER_H_ */
