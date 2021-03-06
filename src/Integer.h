//
//  Integer.h
//  COP-3503-Project
//
//  Created by Justin on 4/9/14.
//
//

#ifndef __COP_3503_Project__Integer__
#define __COP_3503_Project__Integer__

#include <iostream>
#include <vector>

#include "Number.h"
#include "Rational.h"
#include "Radical.h"
//WARNING: Circular dependency?

using namespace std;

class Integer : public Number
{
private:
	int num;
	int inputNum;
    
public:
	Integer(); // default constructor for testing
	Integer(int);
	
	// TODO: need to implement add, subtract, etc. How do we implement this dependent upon Number subclass?
	void add(Number);
	void add(Integer);

	void subtract(Number);
	void subtract(Integer);

	void multiply(Number);
	void multiply(Integer);

	void divide(Number);
	void divide(Integer);

	int getValue();
    
    void exponentiate(Rational power);
    void exponentiate(Integer power);
	
};

#endif /* defined(__COP_3503_Project__Integer__) */
