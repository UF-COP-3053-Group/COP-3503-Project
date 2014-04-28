//
//  WolframRequest.h
//  Calculate
//
//  Created by Ian Van Stralen on 4/28/14.
//  Copyright (c) 2014 Nah. All rights reserved.
//

#ifndef __Calculate__WolframRequest__
#define __Calculate__WolframRequest__

#include <iostream>
#include <stdio.h>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <curl/curl.h>

using namespace std;

class WolframRequest{
public:
    WolframRequest(string input);
    WolframRequest(string input, bool decimal);
    string getResult();
    
private:
    string toWolframAlpha (string input, bool deci);
    string result;
};

#endif /* defined(__Calculate__WolframRequest__) */
