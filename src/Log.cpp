//
//  Log.cpp
//  COP-3503-Project
//
//  Created by Justin on 4/9/14.
//
//

#include "Log.h"

/**
 * Constructor
 */
Log::Log()
{
	// TODO: Create the constructor
}

Log::Log(Number* base, Number* argument){
    this->base = base;
    this->argument = argument;
    type="l";
}

/**
 * Returns the numerical value of this object as a double
 */
double Log::getValue()
{
	//FIXME: Implement this
	return (log(argument)/log(base));
}


Expression* Log::add(Number *num , Expression *caller)
{
	//TODO
	return caller;

}

Expression* Log::subtract(Number *num , Expression *caller)
{
	//TODO
	return caller;

}

Expression* Log::multiply(Number *num , Expression *caller)
{
	//TODO
	return caller;

}

Expression* Log::divide(Number *num , Expression *caller)
{
	//TODO
	return caller;

}

string Log::toString()
{
	return "log"+base+":"+argument;
}

Expression* Log::simplify()
{
	//simplifies logs down to addition and subtraction of prime factors
	Calculator calc = new Calculator();
	string s="";
	string ss="";
	if(this->argument->getType()=="Integer")
	{
		int i = 2;
			vector<int> factors;
			while(i < this->argument)
			{
				if((0 == this->argument% i ) and isPrime(i))
				{
					factors.push_back(i);
				}
				i++;
			}

			for(int i = 0; i < factors.size()-1; ++i)
			{
				s=s+"log"+this->base+"("+factors[i]+") + ";
			}
			s=s+"log"+this->base+"("+factors[factors.size()-1]+")";
			return calc.parseInput(s);
	}
	if (this->argument->getType()=="Rational")
	{
		this->argument->simplify();

	}

}

bool Log::isPrime(int n)
{
	int j = 2;
	while(j < n)
	{
		if(0 == n % j)
			return false;
		j++;
	}
	return true;
}




