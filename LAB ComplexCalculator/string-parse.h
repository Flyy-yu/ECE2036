
// ECE2036 - String Parsing Functions
//
// Subroutine StringParse

#include <string>

// Note. We will discuss strings in great detail later in class

// Define a type that is an array of strings
typedef std::string StringArray_t[2];
// Define a type that is an array of characters
typedef char CharArray_t[2];

// Function prototype for StringParse
int StringParse(std::string,  // String to parse
                std::string,  // Delimiter set
                StringArray_t,     // Returned substrings
                CharArray_t);      // Returned delimiters

// ToDouble converts a string containing digits and a (possible)
// decimal point to the corresponding floating point value.
double ToDouble(const std::string&); // Convert a string value to double

// RemoveParens removes leading and trailing parentheses from a string.
// For example, if the input string is "(1,2)", the  returned string is "1,2".
std::string RemoveParens(std::string);

// GetString reads a character string from the keyboard.
std::string GetStringFromKeyboard();


