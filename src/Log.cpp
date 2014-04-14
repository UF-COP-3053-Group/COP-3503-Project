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
	return calc.toString(simplify());
}

Expression* Log::simplify()
{
	//simplifies logs down to addition and subtraction of prime factors
	Calculator calc = new Calculator();
	string s="";
	string ss="";
	vector<int> factors;
	if(this->argument->getType()=="Integer")
	{
		int i = 2;

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
				s=s+"log"+this->base->toString()+"("+factors[i].toString()+") + ";
			}
			s=s+"log"+this->base->toString()+"("+factors[factors.size()-1].toString()+")";
			return calc.parseInput(s);
	}
	if (this->argument->getType()=="Rational")
	{
		this->argument->simplify();
		int i = 2;

					while(i < this->argument->getNum())
					{
						if((0 == this->argument->getNum()% i ) and isPrime(i))
						{
							factors.push_back(i);
						}
						i++;
					}

					for(int i = 0; i < factors.size()-1; ++i)
					{
						s=s+"log"+this->base->toString()+"("+factors[i].toString()+") + ";
					}
					s=s+"log"+this->base->toString()+"("+factors[factors.size()-1].toString()+")";
					factors.clear();
					int i = 2;

										while(i < this->argument->getDen())
										{
											if((0 == this->argument->getDen()% i ) and isPrime(i))
											{
												factors.push_back(i);
											}
											i++;
										}

										for(int i = 0; i < factors.size()-1; ++i)
										{
											ss=ss+"log"+this->base->toString()+"("+factors[i].toString()+") - ";
										}
										s=s+"log"+this->base->toString()+"("+factors[factors.size()-1].toString()+")";
				s=s+" - "+ss;
				return calc.parseInput(s);

	}
	if (this->argument->getType()=="r")
	{
		s=this->argument->getRadicand()->toString()+" * ( ";
		if(this->argument->getBase->getType()=="Integer")
			{
				int i = 2;

					while(i < this->argument->getBase())
					{
						if((0 == this->argumen->getBase()t% i ) and isPrime(i))
						{
							factors.push_back(i);
						}
						i++;
					}

					for(int i = 0; i < factors.size()-1; ++i)
					{
						s=s+"log"+this->base->toString()+"("+factors[i].toString()+") + ";
					}
					s=s+"log"+this->base->toString()+"("+factors[factors.size()-1].toString()+") )";
					return calc.parseInput(s);
			}
		if (this->argument->getBase()->getType()=="Rational")
			{
				this->argument->getBase()->simplify();
				int i = 2;

							while(i < this->argument->getBase()->getNum())
							{
								if((0 == this->argument->getBase()->getNum()% i ) and isPrime(i))
								{
									factors.push_back(i);
								}
								i++;
							}

							for(int i = 0; i < factors.size()-1; ++i)
							{
								s=s+"log"+this->base->toString()+"("+factors[i].toString()+") + ";
							}
							s=s+"log"+this->base->toString()+"("+factors[factors.size()-1].toString()+")";
							factors.clear();
							int i = 2;

												while(i < this->argument->getBase()->getDen())
												{
													if((0 == this->argument->getBase()->getDen()% i ) and isPrime(i))
													{
														factors.push_back(i);
													}
													i++;
												}

												for(int i = 0; i < factors.size()-1; ++i)
												{
													ss=ss+"log"+this->base->toString()+"("+factors[i].toString()+") - ";
												}
												s=s+"log"+this->base->toString()+"("+factors[factors.size()-1].toString()+") )";
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




