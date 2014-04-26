//
// Log.cpp
// COP-3503-Project
//
// Created by Justin on 4/9/14.
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

Log::Log(Number* b, Number* a){
    //cout<<"here"<<endl;
	type = "log";

	//cout<<a->getValue()<<endl;
	//cout<<argument->getValue()<<endl;
	this->base = b;
	//cout<<b->getValue()<<endl;
	//cout<<base->getValue()<<endl;
	//cout<<"here"<<endl;
	if(a->getValue()<=0)
	{
		throw invalid_argument("Argument cannot be equal to less than zero");
	}
	this->argument = a;
	//cout<<"Created"<<endl;
	//if(!this->simplified())
	//this->simplify();
    //argument = new Integer(3);
}
Log::Log(Integer *b, Integer *a)
{
	//cout<<"here"<<endl;
	type = "log";

	this->base = b;
		if(a->getValue()<=0)
		{
			throw invalid_argument("Argument cannot be equal to less than zero");
		}
		this->argument = a;
		//cout<<"here"<<endl;
	    //this->argument = new Integer(9);
	    //cout<<"here"<<endl;
	    //this->simplify();

}

Log::~Log()
{

}
/**
* Returns the numerical value of this object as a double
*/
double Log::getValue()
{
return log(argument->getValue())/log(base->getValue());
	//return 0.0;
}

Number* Log::getBase()
{
	return this->base;
}
Number* Log::getArgument()
{
	return this->argument;
}
Expression* Log::add(Number *num)
{
	string bad;
		if(num->getType()=="log")
		{
		Log* log = dynamic_cast<Log*>(num);
		return this->add(log);
		}
		else
		{
			bad += this->toString();
			bad +=" + ";
			bad +=num->toString();
			return this->toExpression(bad);
		}

}

Expression* Log::subtract(Number *num)
{
	string bad;
			if(num->getType()=="log")
			{
			Log* log = dynamic_cast<Log*>(num);
			return this->subtract(log);
			}
			else
			{
				bad += this->toString();
				bad +=" - ";
				bad +=num->toString();
				return this->toExpression(bad);
			}

}
Expression* Log::add(Log *num)
{

	if(this->base->getValue()==num->getBase()->getValue())
	{
		//Integer* ti84 = dynamic_cast<Integer*>(ti84);
		//Integer* tier1 = dynamic_cast<Integer*>(tier1);
		//this->argument=argument->getValue()*num->getArgument()->getValue();//(Number)(ti84->getInt()*tier1->getInt());
		return new Expression(this);
	}
	return new Expression(this);
}

Expression* Log::subtract(Log *num)
{
	//TODO
	throw logic_error("No one has written this part of the method yet");;

}

Expression* Log::multiply(Number *num)
{
	//TODO
	throw logic_error("No one has written this part of the method yet");;

}

Expression* Log::divide(Number *num)
{
	string bad;
	if(num->getType()=="log")
	{
	Log* log = dynamic_cast<Log*>(num);
	return this->divide(log);
	}
	else
	{
		bad += this->toString();
		bad +=" / ";
		bad +=num->toString();
		return this->toExpression(bad);
	}

}
Expression* Log::divide(Log *num)
{
	if(this->base->getValue()==num->getBase()->getValue())
	this->base =num->getArgument();
	return new Expression(new Log(this->base,this->argument));
}

/**
 * Will exponentiate this log by the passed Number* num
 */
Expression* Log::exponentiate(Number* num)
{
	throw logic_error("No one has written exponentiate for Log yet");
}

string Log::getType()
{
	return this->type;
}

string Log::toString()
{
	string str;
		str += "log_";
		str += this->base->toString();
		str += ":";
		str +=	this->argument->toString();
		return str;
	//throw logic_error("No one has built this method yet");
	//return "Log"+this->base->toString()+"("+this->argument->toString()+")";
}
Expression* Log::simplify()
{
	int c=2;
			vector<int> factors;
			//factors.clear();
			//~calc();
			string str="";
			string fin="";
			ostringstream ss;
			//cout<<"1"<<endl;
			if (argument->getType()=="Integer")
	{
		Integer* bae = dynamic_cast<Integer*>(argument);
		while(c<bae->getInt()||!(this->isPrime(bae->getInt())))
				{
			//cout<<"2"<<endl;
			if((0==bae->getInt()%c)&&this->isPrime(c))
					{
						factors.push_back(c);
						bae=new Integer(bae->getInt()/c);
					}
			else
				{
				c++;
				}
				}
		//cout<<"3"<<endl;
				for(int i=0;i<factors.size();i++)
				{
					ss<<factors[i];
					str=ss.str();
					fin+="log_";
					fin+=base->toString();
					fin+=":";
					fin+=str;
					fin+=" + ";
				}
				//cout<<"4"<<endl;
				ss<<factors[factors.size()-1];
				str=ss.str();
				str = str.substr(0,str.size()-1);
				cout<<str<<endl;
				fin+="log_";
				fin+=base->toString();
				fin+=":";
				fin+=str;
				//Expression* done =calc.parseInput(fin);
				//cout<<fin<<endl;
				//cout<<"5"<<endl;
				return toExpression(str);
	}
		//int base = (int)this->base->getValue();
		//int argument = (int) this->argument->getValue();

		return new Expression(this);
}
Expression* Log::toExpression(string exp)
{
	Calculator calc = Calculator();
	return calc.parseInput(exp);
}
bool Log::isPrime(int n)
{
	int j=2;
			while(j<n)
			{
				if(0==n%j)
					return false;
				j++;
			}
	return true;
}
bool Log::simplified()
{
	if (argument->getType()=="Integer")
	{
		Integer* beach = dynamic_cast<Integer*>(argument);
		if(this->isPrime(beach->getInt()))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
		return false;
}

