//
//  Radical.h
//  COP-3503-Project
//
//  Created by Justin on 4/9/14.
//  Editied by Tylor on 4/11/2014.
//

#ifndef __COP_3503_Project__Radical__
#define __COP_3503_Project__Radical__

#include <iostream>
#include "Number.h"

using namespace std;

class Radical : public Number
{
private:
    
public:
	Radical();
    Radical(Number base, Number radicand);
};

#endif /* defined(__COP_3503_Project__Radical__) */
