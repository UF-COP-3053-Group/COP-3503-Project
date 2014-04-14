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
    Log(Number* base, Number* argument);
	
	double getValue();
};

#endif /* defined(__COP_3503_Project__Log__) */
