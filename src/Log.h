//
//  Log.h
//  COP-3503-Project
//
//  Created by Justin on 4/9/14.
//
//

#ifndef __COP_3503_Project__Log__
#define __COP_3503_Project__Log__

#include <iostream>
#include "Number.h"

using namespace std;

class Log : public Number
{
private:
    string type;
	Number* base;
	Number* argument;
    
public:
	Log();
<<<<<<< HEAD
    Log(Number* base, Number* argument);
=======
    //**************
    Log(Number b, Number a);
    void simplify();
    //Log(Number*, Number*);
    //Log(Number*, Number);
    //Log(Number, Number*);
    //**************
    void exponentiate(Rational power);
    void exponentiate(Integer power);
>>>>>>> 40773ff532c3a7ab8062ddec51b7f0aa00c21353
	
	double getValue();
};

#endif /* defined(__COP_3503_Project__Log__) */
