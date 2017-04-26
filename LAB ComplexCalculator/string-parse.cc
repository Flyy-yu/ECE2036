//
// ECE2036 - String Parsing Function for ECE2036 Complex Calculator
//

#include <iostream>
#include <stdlib.h>
#include "string-parse.h"

using namespace std;

// Subroutine StringParse
int StringParse(string st,       // String to parse
                string delimSet, // Delimiter set
                StringArray_t subStr,         // Returned substrings
                CharArray_t   delims)         // Returned delimiters
{
  string::size_type i = 0;
  int count = 0;
  if (st.empty()) return 0; // No operands
  while(i< st.length())
    {
      string::size_type k = i;
      if (st[i] == '(')
        { // Found an open paren, advance to close
          k = st.find(')', i);
          if (k == string::npos)
            { // Not found?
              cout << "Malformed input string.  Missing close paren" << endl;
            }
        }
      string::size_type j = st.find_first_of(delimSet, k);
      if (j == string::npos)
        { // Not found
          subStr[count] = st.substr(i, j);
          delims[count] =  '\0';
          count++;
          i = j;
        }
      else
        {
          subStr[count] = st.substr(i, j-i);
          delims[count] = st[j];
          count++;
          i = j + 1;
        }
      if (count == 2) break; // Do not overflow the output arrays
    }
  return count;  // Number of substrings
}

double ToDouble(const string& st)
{
  return atof(st.c_str()); // Convert string to double
}

string RemoveParens(string st)
{
  if (st[0] != '(')
    {
      cout << "Oops, RemoveParens called but no leading paren" << endl;
      cout << "st is " << st << endl;
    }
  if (st[st.length()-1] != ')')
    {
      cout << "Oops, RemoveParens called but no trailing paren" << endl;
      cout << "st is " << st << endl;
    }
  return st.substr(1, st.length()-2);
}

string GetStringFromKeyboard()
{
  string l;
  getline(cin, l);
  string::size_type i = 0;
  
  while(true)
    { // Remove any spaces, end-of-line characters or tabs
      string::size_type i = l.find_first_of(" \n\t");
      if (i == string::npos) return l; // No more spaces or eol
      l.erase(i, 1);
    }
  return l;
}

