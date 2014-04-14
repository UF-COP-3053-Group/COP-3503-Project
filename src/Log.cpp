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

Log::Log(Number b, Number a){
    this->base=b;
    this->argument=a;
}

void Log::simplify()
{

}

void Log::exponentiate(Rational power){
    //needs class implementation
}

void Log::exponentiate(Integer power){
    //needs class implementation
}

string Log::getType()
{
	return "l";
}
