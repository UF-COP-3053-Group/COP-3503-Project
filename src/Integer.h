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
	int inputNum;
    string type;
    
public:
	Integer(); // default constructor for testing
	Integer(int inputNum);
	
	// TODO: need to implement add, subtract, etc. How do we implement this dependent upon Number subclass?
	Expression* add(Number* num, Expression* caller);
//	Expression* add(Number* z , Expression* caller);
	string getType();
	Expression*  subtract(Number* num , Expression* caller  );
//	Expression* subtract(Integer* z , Expression* caller);

	Expression*  multiply(Number* num , Expression* caller  );
//	Expression* multiply(Integer* z , Expression* caller);

	Expression*  divide(Number* n , Expression* caller);
//	Expression* divide(Integer* z , Expression* caller);

	double getValue();

	string toString();
    
};

#endif /* defined(__COP_3503_Project__Integer__) */
