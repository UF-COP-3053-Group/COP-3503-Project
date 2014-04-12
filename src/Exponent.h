//
//  Exponent.h
//  COP-3503-Project
//
//  Created by Justin on 4/9/14.
//
//

#ifndef __COP_3503_Project__Exponent__
#define __COP_3503_Project__Exponent__

#include <iostream>

#include "Number.h"

//fwd declaration, so that the code compiles. 
//might need to be changed later. 
class Rational;

using namespace std;

class Exponent : public Number
{
public:
    Exponent(Number base, Number power);
	Exponent(double base, double power);
    Exponent(double base, Rational power);

	
	// TODO: need to implement add, subtract, etc. How do we implement this dependent upon Number subclass?
    /*void add(Number);
     
	void add(Constant);
    //combine
     
	void add(Exponent);
    //if Integer base, convert both to integer, add
     
	void add(Integer);
     //convert to Integer, add
     
	void add(Log);
    //simplyify log, combine
     
	void add(Radical);
    //combine
     
	void add(Rational);
    //combine
     
	void subtract(Constant);
     
	void subtract(Exponent);
    //if Integer base, convert both to integers, subtract
     
	void subtract(Integer);
    //convert to Integer, subtract
     
	void subtract(Log);
     
	void subtract(Radical);
     
	void subtract(Rational);
     

    void multiply(Constant);
    //combine
     
	void multiply(Exponent);
     //add pow
     
	void multiply(Integer);
    //convert to Integer, multiply
     
	void multiply(Log);
    //combine
     
	void multiply(Radical);
    //denominator = root * pow +1
     
	void multiply(Rational);
    //multiply by denominator
     

     
	void divide(Constant);
    //create fraction
     
	void divide(Exponent);
    //if base is same, subtract pow.
    //else create fraction
     
	void divide(Integer);
    //convert to Integer, create fraction
     
	void divide(Log);
    //create fraction
     
	void divide(Radical);
    //create fraction
     
	void divide(Rational);
    // multiply by denominator
     
     */
};

#endif /* defined(__COP_3503_Project__Exponent__) */
