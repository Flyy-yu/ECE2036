//
// EC20360 Program 2 - Complex Number Calculator
// YOUR NAME HERE
// Peiyu Wang

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <cstring>
#include "complex.h"
#include "string-parse.h"
#include <sstream>
using namespace std;

// this function help convert polor complex number to the correct format

int main()
{
    // Add any variables you might need here
    double err;
    string temp;
    Complex first;
    Complex second;
    while(true) {
        string st = GetStringFromKeyboard(); // Get the  next input line
        // The types StringArray_t and CharArray_t are defined in string-parse.h
        // They are fixed length arrays of 2 elements.
        // The StringParse function returns an integer indicating how many
        // of the two are actually used.

        StringArray_t operands; // array of operands
        CharArray_t   delims;   // array of delimiters
        char fk;
        int count = StringParse(st, "+-*/", operands, delims);
        if (count == 0) break; // All done
        // get the complex number here depends different type of input
        if (operands[0].empty()) {
            temp = operands[1];

            second = Complex(RemoveParens(operands[1]));  // set up my Complex number

        } else if(!operands[1].empty()) {
            temp = operands[0];
            first = Complex(RemoveParens(operands[0])); // set up my Complex number
            temp = operands[1];
            second = Complex(RemoveParens (operands[1]));   // set up my Complex number
        } else {
            temp = operands[0];
            first = Complex(RemoveParens(operands[0])); // set up my Complex number
        }

        if (!first.geterror()) {   // if the number is not NaN, start the calculation

            if (delims[0]==0) {
                first=first;
            } else if(delims[0]=='+') { // if+
                first=first+second;

            } else if(delims[0]=='-')  { // if -
                first=first-second;
            } else if (delims[0]=='*') {  //if times
                first=first*second; /* code */
            } else if (delims[0]=='/') { // if div
                first=first/second;

                /* code */
            }
            if (!first.geterror()) {
                first.printcomplex();
            } else {
                cout << "= NaN"<< endl;   //if number is xxx/0
            }

        } else {
            cout << "= NaN"<< endl; //if number is xxx/0
        }

    }

    return 0;  // Successful completion of main()
}

