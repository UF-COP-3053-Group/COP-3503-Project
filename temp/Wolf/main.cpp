//
//  main.cpp
//  Wolfram
//
//  Created by Ian Van Stralen on 4/14/14.
//  Copyright (c) 2014 Nah. All rights reserved.
//
//  API documentation
// http://products.wolframalpha.com/api/documentation.html
#include <stdio.h>
#include <curl/curl.h>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

vector<string> contents;

size_t handle_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
    contents.push_back(string(static_cast<const char*>(ptr), size * nmemb));
    return size * nmemb;
}

int main(void)
{
    CURL *curl;
    CURLcode res;
    // for reference more than anything
    const string appid = "22JXWX-YT43YWVEUU";
    string buffer;
    
    curl = curl_easy_init();
    if(curl) {
        //Exact answer
        //curl_easy_setopt(curl, CURLOPT_URL, "http://api.wolframalpha.com/v2/query?input=1%2F3%2B7&appid=22JXWX-YT43YWVEUU&format=plaintext&includepodid=Result");
        curl_easy_setopt(curl, CURLOPT_URL, "http://api.wolframalpha.com/v2/query?input=1%2F3%2B7&appid=22JXWX-YT43YWVEUU&format=plaintext&includepodid=DecimalApproximation");
        /* example.com is redirected, so we tell libcurl to follow redirection */
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,handle_data);
        /* Perform the request, res will get the return code */
        res = curl_easy_perform(curl);
        
        /* Check for errors */
        if(res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        
        /* always cleanup */
        curl_easy_cleanup(curl);
        
    }
    string output = contents.at(0).substr(contents.at(0).find("<plaintext>")+11);
    output = output.substr(0,output.find_first_of("<"));
    cout << output;
    return 0;
}

