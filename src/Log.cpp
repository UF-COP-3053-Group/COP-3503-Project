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

<<<<<<< HEAD
Log::Log(Number* base, Number* argument){
    this->base = base;
    this->argument = argument;
=======
Log::Log(Number b, Number a){
    this->base=b;
    this->argument=a;
}

void Log::simplify()
{

>>>>>>> 40773ff532c3a7ab8062ddec51b7f0aa00c21353
}

/**
 * Returns the numerical value of this object as a double
 */
double Log::getValue()
{
	//FIXME: Implement this
	return 0.0;
}
<<<<<<< HEAD
=======

void Log::exponentiate(Integer power){
    //needs class implementation
}

string Log::getType()
{
	return "l";
}
>>>>>>> 40773ff532c3a7ab8062ddec51b7f0aa00c21353
