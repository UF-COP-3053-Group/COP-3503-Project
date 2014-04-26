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
	//TODO
	throw logic_error("No one has written this part of the method yet");;

}

Expression* Log::subtract(Number *num)
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
	Log* log = dynamic_cast<Log*>(num);
	return this->divide(log);

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
	int base = (int)this->base->getValue();
		int argument = (int) this->argument->getValue();
		Calculator calc = Calculator();
		vector<int> factors;
		string str="";
		string fin="";
		ostringstream ss;
		int c=2;
		while(c<argument&&!(this->isPrime(argument)))
		{
			if((0==argument%c)&&this->isPrime(c))
			{
				factors.push_back(c);
			}
			c++;
		}
		for(int i=0;i<factors.size()-1;i++)
		{
			ss<<factors[i];
			str=ss.str();
			fin+="log_";
			fin+=this->base->toString();
			fin+=":";
			fin+=str;
			fin+=" ";
		}
		ss<<factors[factors.size()-1];
		str=ss.str();
		fin+="log_";
		fin+=this->base->toString();
		fin+=":";
		fin+=str;
		Expression* done =calc.parseInput(fin);
		cout<<calc.toString(done);
		return done;
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

