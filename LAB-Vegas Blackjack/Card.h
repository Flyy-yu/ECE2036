#ifndef CARD_H   // include guard
#define CARD_H
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>
#include <string>

#include <math.h>
using namespace std;
class Card
{
  private:
//  Data members of class Card
    std::string typeString; //  this will store a string corresponding to the
                            //   card type, e.g. "Ace", or "Two", or "Jack"
    int initial_value;  //  this will hold an integer corresponding to the initial value
                        //   of the card type.  For an Ace initial_value = 11, 
                        //   a Two initial_value = 2, a Three initial_value = 3, etc.
                        //   Jack, Queen, and King should each have initial_value = 10
                        //  It is called 'initial value' because the value of an Ace
                        //   will be effectively reduced to 1 if the Hand's value gets too big.
                        //   But this will be handled in class Hand.
   
  public:
    Card();   //  write an implementation for this constructor.  It should call a random
              //   number generator to produce a random number between 1 - 13, and then
              //   assign the typeString accordingly, i.e. 1 becomes an "Ace", 2 becomes a "Two",
              //   3 becomes a "Three", etc.  11 becomes a "Jack", 12 becomes a "Queen", 
              //   13 becomes a "King".  Also set the initial_value of the card.
    std::string getType() const;  // write an implementation for this function.  It should
                                  //  return the string typeString
    int getValue() const;   //  write an implementation for this function.  It should 
                            //   return the int initial_value
};

#endif
