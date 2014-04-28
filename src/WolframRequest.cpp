//
//  WolframRequest.cpp
//  Calculate
//
//  Created by Ian Van Stralen on 4/28/14.
//  Copyright (c) 2014 Nah. All rights reserved.
//

#include "WolframRequest.h"

WolframRequest::WolframRequest(string input){
    result = toWolframAlpha(input, false);
}

WolframRequest::WolframRequest(string input, bool decimal){
    result = toWolframAlpha(input, decimal);
}

string  WolframRequest::getResult(){
    return result;
}

vector<string> contents;

size_t handle_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
    contents.push_back(string(static_cast<const char*>(ptr), size * nmemb));
    return size * nmemb;
}

/*
 Make a web request to Wolfram Alpha (the calculator to end all calculators)
 Returns either the exact answer or a decimal answer.
 */
string WolframRequest::toWolframAlpha (string input, bool deci){
    string buf; // Have a buffer string
    stringstream ss(input); // Insert the string into a stream
    vector<char> letters;
    
    ostringstream result;
    
    while (ss >> buf) //remove spaces
        result << buf;
    
    for (int x = 0; x < result.str().size(); x++) //make a vector of letters
        letters.push_back(result.str().at(x));
    
    ostringstream result2;
    
    /*
     URL encode the string, which involves taking non-alphanumeric symbols, putting a % in front,
     and then converting the char to its hex representation.
     */
    for (int y = 0; y < letters.size(); y++) {
        if(!isalnum(letters.at(y)) && (letters.at(y) != '-' ||letters.at(y) != '.' || letters.at(y) != '_' || letters.at(y) != '~')){
            string waste = &letters.at(y);
            result2 << '%' << hex << (int)letters.at(y);
        }
        else
            result2 << letters.at(y);
    }
    
    //The actual web request starts here
    CURL *curl;
    CURLcode res;
    
    string query = "http://api.wolframalpha.com/v2/query?input=";
    curl = curl_easy_init();
    if(curl) {
        
        query += result2.str();
        //Exact answer
        if (!deci){
            query += "&appid=22JXWX-YT43YWVEUU&format=plaintext&includepodid=Result&includepodid=Input";
            //curl requires a const char, convert the string accordingly
            const char * arg = query.c_str();
            curl_easy_setopt(curl, CURLOPT_URL, arg);
        }
        //decimal answer
        else{
            query += "&appid=22JXWX-YT43YWVEUU&format=plaintext&includepodid=DecimalApproximation&includepodid=Input";
            const char * arg = query.c_str();
            curl_easy_setopt(curl, CURLOPT_URL, arg);
        }
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,handle_data);
        //Perform the request, res will get the return code
        res = curl_easy_perform(curl);
        
        // Check for errors
        if(res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        
        // always cleanup
        curl_easy_cleanup(curl);
        
    }
    string output;
    size_t pos = contents.at(0).find("DecimalApproximation");
    if (pos != string::npos) {
        output = contents.at(0).substr(contents.at(0).find("<plaintext>", pos)+11);
        
    }
    pos = contents.at(0).find("Result");
    if(pos != string::npos){
        output = contents.at(0).substr(contents.at(0).find("<plaintext>", pos)+11);
    }
    else{
        output = contents.at(0).substr(contents.at(0).find("<plaintext>")+11);
    }
    //cout << query << endl;
    output = output.substr(0,output.find_first_of("<"));
    contents.pop_back();
    result.flush();
    result2.flush();
    ss.flush();
    return output;
}
