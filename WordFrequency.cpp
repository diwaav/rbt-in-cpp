// CITE lowering words: 
// https://thispointer.com/converting-a-string-to-upper-lower-case-in-c-using-stl-boost-library/

// CITE: based off of professor's fileio

/********************************************************************************* 
* Diwa Ashwini Vittala, dashwini
* 2022 Spring CSE101 PA8
* WordFrequency.cpp
* WordFrequency client
**********************************************************************************/

#include<iostream>
#include<fstream>
#include<string>
#include<iostream>
#include <locale>
#include<stdexcept>
#include <stdio.h>
#include <ctype.h>
#include <algorithm>
#include "Dictionary.h"

using namespace std;

#define MAX_LEN 300

int main(int argc, char * argv[]){
    size_t begin, end, len;
    ifstream in;
    ofstream out;
    string line;
    string token;
    string delim = " \t\\\"\',<.>/?;:[{]}|`~!@#$%^&*()-_=+0123456789";

    if( argc != 3 ){
        cerr << "Usage: " << argv[0] << " <input file> <output file>" << endl;
        return(EXIT_FAILURE);
    }

    in.open(argv[1]);
    if( !in.is_open() ){
        cerr << "Unable to open file " << argv[1] << " for reading" << endl;
        return(EXIT_FAILURE);
    }

    out.open(argv[2]);
    if( !out.is_open() ){
        cerr << "Unable to open file " << argv[2] << " for writing" << endl;
        return(EXIT_FAILURE);
    }

    Dictionary A;
    while( getline(in, line) )  {
        for_each(line.begin(), line.end(), [](char & c) {
            c = ::tolower(c);
        });

        len = line.length();

        begin = min(line.find_first_not_of(delim, 0), len);
        end   = min(line.find_first_of(delim, begin), len);
        token = line.substr(begin, end-begin);

        while( token!="" ){
            if (A.contains(token)) {
                A.setValue(token, A.getValue(token) + 1);
            } else {
                A.setValue(token, 1);
            }
            begin = min(line.find_first_not_of(delim, end+1), len);
            end   = min(line.find_first_of(delim, begin), len);
            token = line.substr(begin, end-begin);
        }
   }
   out << A << "\n";
   in.close();
   out.close();

   return(EXIT_SUCCESS);
}



