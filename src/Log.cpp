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
	return "log_"+base+":"+argument;
}






