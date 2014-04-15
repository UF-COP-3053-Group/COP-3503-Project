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
 Number* Log::getBase()
 {
	 return this->base;
 }

 Number* Log::getArgument()
 {
	 return this->argument;
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
	if (num->getType()=="l"&&this->base==num->getBase())
	{
		this->base=num->getArgument();
		return new Expression(new Log(this->base,this->argument));
	}
	return caller;

}

string Log::toString()
{
	ostringstream rtnStream;
	rtnStream << this->simplify(); //correct method to use?
	string rtnString = rtnStream.str();
	return rtnString;
}

Expression* Log::simplify()
{
	//simplifies logs down to addition and subtraction of prime factors
	Calculator calc = Calculator();
	string s="";
	string ss="";
	vector<int> factors;
	int i = 2;
	if(this->argument->getType()=="Integer")
	{
		 i = 2;

			while(i < (this->getArgument()->getValue()))
			{
				if((0 == fmod((this->getArgument()->getValue()),double(i)) ) and isPrime(i)) //fmod must be used to get modulus of doubles
				{
					factors.push_back(i);
				}
				i++;
			}

			for(int i = 0; i < factors.size()-1; ++i)
			{
				char buffer [10];
				string converted = sprintf(buffer, "%d", factors[i]);
				s=s+"log"+this->base->toString()+"("+converted+") + "; //itoa is not standard C++, changed to result from sprintf

			}
			s=s+"log"+this->base->toString()+"("+string(itoa(factors[i-1]))+")";
			return calc.parseInput(s);
	}
	if (this->argument->getType()=="Rational")
	{
		this->argument->simplify();
		i = 2;

					while(i < (Rational)this->argument->getNum())
					{
						if((0 == (Rational)this->argument->getNum()% i ) and isPrime(i))
						{
							factors.push_back(i);
						}
						i++;
					}

					for(int i = 0; i < factors.size()-1; ++i)
					{
						s=s+"log"+this->base->toString()+"("+string(itoa(factors[i]))+") + ";
					}
					s=s+"log"+this->base->toString()+"("+string(itoa(factors[i-1]))+")";
					factors.clear();
					 i = 2;

										while(i < (Rational)this->argument->getDen())
										{
											if((0 == (Rational)this->argument->getDen()% i ) and isPrime(i))
											{
												factors.push_back(i);
											}
											i++;
										}

										for(int i = 0; i < factors.size()-1; ++i)
										{
											ss=ss+"log"+this->base->toString()+"("+string(itoa(factors[i]))+") - ";
										}
										s=s+"log"+this->base->toString()+"("+string(itoa(factors[i-1]))+")";
				s=s+" - "+ss;
				return calc.parseInput(s);

	}
	if (this->argument->getType()=="r")
	{
		s=(Radical)this->argument->getRadicand()->toString()+" * ( ";
		if((Radical)this->argument->getBase()->getType()=="Integer")
			{
				 i = 2;

					while(i < this->argument->getBase())
					{
						if((0 == this->argumen->getBase()% i ) and isPrime(i))
						{
							factors.push_back(i);
						}
						i++;
					}

					for(int i = 0; i < factors.size()-1; ++i)
					{
						s=s+"log"+this->base->toString()+"("+string(itoa(factors[i]))+") + ";
					}
					s=s+"log"+this->base->toString()+"("+string(itoa(factors[i-1]))+") )";
					return calc.parseInput(s);
			}
		if (this->argument->getBase()->getType()=="Rational")
			{
				(Rational)this->argument->getBase()->simplify();
				i = 2;

							while(i < (Rational)this->argument->getBase()->getNum())
							{
								if((0 == (Rational)this->argument->getBase()->getNum()% i ) and isPrime(i))
								{
									factors.push_back(i);
								}
								i++;
							}

							for(int i = 0; i < factors.size()-1; ++i)
							{
								s=s+"log"+this->base->toString()+"("+string(itoa(factors[i]))+") + ";
							}
							s=s+"log"+this->base->toString()+"("+string(itoa(factors[i-1]))+")";
							factors.clear();
							 i = 2;

												while(i < (Rational)this->argument->getBase()->getDen())
												{
													if((0 == (Rational)this->argument->getBase()->getDen()% i ) and isPrime(i))
													{
														factors.push_back(i);
													}
													i++;
												}

												for(int i = 0; i < factors.size()-1; ++i)
												{
													ss=ss+"log"+this->base->toString()+"("+string(itoa(factors[i]))+") - ";
												}
												s=s+"log"+this->base->toString()+"("+string(itoa(factors[i-1]))+") )";
						s=s+" - "+ss;
						return calc.parseInput(s);

			}

	}
	return new Expression(new Log(this->base,this->argument));

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




