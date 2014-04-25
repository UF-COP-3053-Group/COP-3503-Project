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

Log::Log(Number* base, Number* argument){
    this->base = base;
    this->argument = argument;
}

/**
* Returns the numerical value of this object as a double
*/
double Log::getValue()
{
//FIXME: Implement this
return 0.0;
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
	//TODO
	throw logic_error("No one has written this part of the method yet");;

}


/**
 * Will exponentiate this log by the passed Number* num
 */
Expression* Log::exponentiate(Number* num)
{
	throw logic_error("No one has written exponentiate for Log yet");
}


string Log::toString()
{
	throw logic_error("No one has built this method yet");
}


