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
#include "Number.h"
#include "Rational.h"
#include "Expression.h"
using namespace std;

class Integer : public Number
{
private:
	int num;
	int inputNum;
    string type;
    
public:
	Integer(); // default constructor for testing
	Integer(int inputNum);
	
	// TODO: need to implement add, subtract, etc. How do we implement this dependent upon Number subclass?
	void add(Number* n);
	Expression* add(Integer* z , Expression* caller);
	string getType();
	void subtract(Number* n  );
	Expression* subtract(Integer* z , Expression* caller);

	void multiply(Number* n  );
	Expression* multiply(Integer* z , Expression* caller);

	void divide(Number* n);
//	Rational divide(Integer z);

	double getValue();
    
};

#endif /* defined(__COP_3503_Project__Integer__) */
