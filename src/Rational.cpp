//
//  Rational.cpp
//  COP-3503-Project
//
//  Created by Justin on 4/9/14.
//
//

#include "Rational.h"
#include <stdexcept>
using namespace std;

/**
 * Constructor
 */
Rational::Rational(double decimal){
    //create a rational from a decimal number
}

Rational::Rational(int num , int den)
{

	if(den == 0)
		throw invalid_argument("Can't divide by zero");

	this->num = num;
	this->den = den;
	// TODO: Create the constructor

}

Rational::~Rational()
{
	

}


void Rational::divide(Rational r)
{

	//Again, this had the side effect of changin r.
	
	int temp = r.getNum();
	r.setNum(r.getDen());
	r.setDen(temp);

	Rational::multiply(r);
}
void Rational::setNum(int n)
{
	num = n;	
}

void Rational::setDen(int n)
{
	den = n;
}

void Rational::add(Number n)
{
	cout << "Successfully caught a number" << endl;	

}

void Rational::add(Constant n)
{

	cout << "Successfully recognized a constant" <<endl;
}


//add the value of the Integer of to the Rational
void Rational::add(Integer i)
{
//	num  = num + i * den;
	
			
}

void Rational::subtract(Rational r)
{
	//WARNING: this has the undesired side-effect of changing r...fix later.
	r.setNum(-1 * r.getNum());
	Rational::add(r);
}
//perhaps this should eventually return a new Rational number?
void Rational::add(Rational r)
{
	int ans_num = num * r.getDen() + den * r.getNum();
	int ans_den = den * r.getDen();

	Rational *n = new Rational(ans_num , ans_den);
	n->simplify();
	
	cout<<"Numerator: " << n->getNum()<<endl;
	cout<<"Denominator: " << n->getDen() <<endl; 	
	
	// ? 
	delete n;
	
}

void Rational::multiply(Rational r)
{
	int ans_num = num * r.getNum();
	int ans_den = den * r.getDen();
	
	Rational *n = new Rational(ans_num , ans_den);
	n->simplify();

	cout << "Numerator: " << n->getNum()<<endl;
	cout << "Denominator: " <<n->getDen() << endl;
	
	delete n;
	
}
//handling of divide by 0 is done by constructor, 
//negative numbers should work now.
int Rational::gcd(int a , int b)
{

	bool flip = false;
	if(b < 0 && a > 0)
	{
		a *= -1;
		b *= -1;
	}

	if(b < 0 && a < 0)
	{
		a *= -1;
		b *= -1;
	}

	if(a < 0)
	{
		flip = true;	
		a *= -1;
	}
	int top = a >= b ? a : b;
	int bot = a <= b ? a : b;

	int r = top % bot;

	if(r == 0)
	{
		if(flip)
			return -1 *bot;
		return bot;	
	}
	else
	{
		gcd(bot, r);	
	}

}

void Rational::simplify()
{
	int gcd = Rational::gcd(this->num , this->den);
	if(num == 0)
	{
		Rational::rationalToInt(0);//should return an integer, = 0;
	}

	if(den == 1)
	{
		Rational::rationalToInt(num);//should return an integer, = num

	}

	if(num < 0 && den < 0)
	{
		num *= -1;
		den *= -1;
	}
	num = num / gcd;
	den = den / gcd;	

}

//Will we need this? 
Integer *Rational::rationalToInt(int n)
{
	cout << "Created new Integer, " << n <<endl;
	return new Integer(n);
}
int Rational::getNum()
{
    return num;
}

int Rational::getDen()
{
	return den;
}

void Rational::exponentiate(Rational power){
    num = pow(num, power.getNum());
    den = pow(den, power.getNum());
    //return a radical
}

void Rational::exponentiate(Integer power){
    num = pow(num, power.getInt());
    den = pow(den, power.getInt());
}
