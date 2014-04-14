//
//  Radical.cpp
//  COP-3503-Project
//
//  Created by Justin on 4/9/14.
//  Edited by Tylor on 4/14/2014.
//


//TODO: Add pseudocode for coefficients


#include "Radical.h"

/**
 * Constructor
 */
Radical::Radical()
{

}

Radical::Radical(Number* coefficient, Number* base, Number* radicand)
{
	    this->coefficient = coefficient;
		this->base = base;
		this->radicand = radicand;
		type = "Radical";
}

/**
 * Returns the numerical value of this object as a double
 */
double Radical::getValue()
{
	return pow(radicand->getValue(),(1/base->getValue()));
}

Number* Radical::getBase()
{
	return base;
}

Number* Radical::getCoef()
{
	return coef->getValue();
}
string Radical::toString()
{
	string o = "";
	if(base->getValue()==2)
	{
		o = string("sqrt(")+radicand->toString()+string(")");
	}
	else
	{
		o = string("(")+base->toString()+string(")root(")+radicand->toString+string(")");
	}
	return o;
}


	Number* Radical::getCoef()
{
	return coefficient;
}

Number* Radical::getRad()
{
	return radicand;
}

string Radical::getType()
{
	return type;
}

Expression* Radical::add(Number* num , Expression* caller)
{ 
	//Hope this is right, not too sure how Expression works tbh. Will include pseudocode so I can be corrected.
	//Idea is to see if the other side is a radical, if it is, check if they have the same base and radicand, if they do, add the coefficients.
	int c = coefficient;
	if(num->getType()=="Radical")
	{
		if((num->getBase()->getValue()==base)&&(num->getRad()->getValue()==radicand))
		{
			c+=num->getCoef()->getValue();
			return new Expression(new Radical(c,base,radicand));
		}
	}
	return caller;
}

Expression* Radical::subtract(Number* num , Expression* caller)
{
	//Same as addition only negative
	int c = coefficient;
	if(num->getType()=="Radical")
	{
		if((num->getBase()->getValue()==base)&&(num->getRad()->getValue()==radicand))
		{
			c-=num->getCoef()->getValue();
			return new Expression(new Radical(c,base,radicand));
		}
	}
	return caller;
}

Expression* Radical::multiply(Number* num , Expression* caller)
{
	if(num->getType()=="Radical")
	{
		//If the radicands are the same, return an Integer equal to radicand*coefficient
		if(num->getRad() == radicand)
		{
			return new Expression(new Integer(radicand->getValue()*coefficient->getValue()*num->getCoef()->getValue()));
		}
		//If radicands are different return a radicand where coefficients are multiplied and the base is the same and the radicand is multiplied
		else
		{
			//Not sure about this construction. Supposed to return new Radical (coefThis*coefIn,base,radThis*radIn) but there's no way to multiply two Numbers in a way that returns a Number, right?
			return new Expression(new Radical(coefficient*num->getCoef(),base,radicand*num->getRadicand()));
		}
	}
	return caller;
}

Expression* Radical::divide(Number* num , Expression* caller)
{
	if(num->getType()=="Radical")
	{
		//divide the coef's and divide the radicands
		else
		{
			//Not sure about this construction. Supposed to return new Radical (coefThis*coefIn,base,radThis*radIn) but there's no way to divide two Numbers in a way that returns a Number, right?
			return new Expression(new Radical(coefficient/num->getCoef(),base,radicand/num->getRadicand()));
		}
	}
	return caller;
}

void Radical::simplify()
{
	if((radicand->getType() != "Integer")||(base->getType() != "Integer"))
		throw bad_input;//Should throw bad input or something if this ever happens. Needless to say this should not happen.
	vector<int> factors;//vector to hold the disassembled factor tree
	recurseSimplify(factors, radicand->getValue());//Get all of the factors for the radicand
	sort(factors.begin(),factors.end());//Sort them increasing
	b=base->getValue();//Get an int with the base for easier access
	if(factors.size >= b)//If there are fewer factors than the base, no simplification can be done
	{
		for(int i=0;i<factors.size()+((b-1)*-1);i++)//loop through the factors from 0 to a value small enough that I can compare 'b' factors.
		{
			bool row = false;//initialise the variable that determines if a row of factors has been found
			for(int j=0;j<b-1;j++)//check b consecutive factors
			{
				if(factors[i+j]==factors[i+j+1])//check them 2 at a time
					row = true;
				else
					row=false;
			}
			if(row)//If we got b of the same factor in a row
			{
				coeficcient = coefficient*New(Integer(factors[i]));//multiply the coefficient by the factor
				for(int j=0;j<b;j++)
				{
					factors.erase(factors.begin()+i+j);//and erase the factor from the list
				}
			}
		}
	}
	int p = 1;
	for(int i=0;i<factors.size();i++)//Then multiply the leftover factors and set the radicand to that
	{
		p*=factors[i];
	}
	radicand = new Integer(p);
}


bool Radical::recurseSimplify(vector<int> factors, int b)
{
	int f = 2;
	while (f < floor(b/2))
	{
		if(f%r==0)
		{
			factors.push_back(f);
			recurseSimplify(factors,r/f);
		}
		f++;
	}
}
	
