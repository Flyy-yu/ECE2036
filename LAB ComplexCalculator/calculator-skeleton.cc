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

string to_strin(double number){
    ostringstream buff;
    buff<<number;
   return buff.str();
}

string convert(string str)
{
    double value;     
    double angle;
    value = ToDouble(str.substr(0,str.find(">")));
    angle = ToDouble(str.substr(str.find(",")+1));
    double real = value*cos(angle);
    double img = value*sin(angle);
    string real1 = to_strin(real);
    string img1 = to_strin(img);

    return "("+real1+","+img1+")";
}



 


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
            if (temp.find(",")!=0) {  //if the number is regular form
                second = Complex(RemoveParens(operands[1]));
            } else {            //if the number is polor form
                second = Complex(RemoveParens(convert(operands[1])));
            }

        } else if(!operands[1].empty()) {

            if (temp.find(",")!=0) {  //if the number is regular form

                first = Complex(RemoveParens(operands[0]));
            } else {//if the number is polor form
                first = Complex(RemoveParens(convert(operands[0])));
            }
            if (temp.find(",")!=0) {//if the number is regular form
                second = Complex(RemoveParens (operands[1]));
            } else {//if the number is polor form//if the number is polor form
                second = Complex(RemoveParens(convert(operands[1])));
            }
        } else {

            if (temp.find(",")!=0) {//if the number is regular form
                first = Complex(RemoveParens(operands[0]));
            } else {//if the number is polor form
                first = Complex(RemoveParens(convert(operands[0])));
            }
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


