#ifndef HAND_H
#define HAND_H

// Definition of class Hand, but only function prototypes included

#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>
#include <string>
#include "Card.h"


class Hand 
{
private:
   int value;   //  This should hold the total value of the hand.  Update every time you
                //   add a card 
   int number_of_aces;  //  this should hold the number of Aces in the hand, which is
                        //   useful for calculating hand value.  Update every time you
                        //   add a card
   int number_of_cards;  //  this should hold the total number of cards in the hand.
                         //   Update every time you add a card.
   Card * cards[11];  //  an array of 11 Card pointers to point to the hand's cards.
   std::string hand_holder;  // Holds either "Player" or "Dealer"

   void updateValue();  // Private member function that updates the hand's value.
                        //   You must write an implementation for this function.
                        //   It should be called every time you add a card.

public:
   explicit Hand(std::string);  // Constructor, sets hand_holder.  Write an implementation.
   ~Hand();  //  Destructor.  Deallocates all cards.  Write an implementation.
   Hand & operator++();  //  Adds a randomly chosen card to the hand.  It must do so using
                         //   a random number generator, and must use the command 'new'
                         //   to dynamically allocate a new Card.  Write an implementation.
//  Below are a set of overloaded operators for comparing the value of a Hand to the 
//   value of another Hand, or to an int.  You must write implementations for all of these.
   bool operator>(const Hand & rhs) const;  
   bool operator>(int rhs) const;
   bool operator<(const Hand & rhs) const;
   bool operator<(int rhs) const;
   bool operator==(const Hand & rhs) const;
   bool operator==(int rhs) const;
   void printHand();  //  This function should print the cards in the hand, and the total
                      //    value of the hand.  Write an implementation. 
   void printFirstCard();  // This function should print only the first card in the hand 
                           //  (used for dealer).  Write an implementation.

//  Here I'm implementing a copy constructor and an assignment operator for you.
//   It is necessary to write our own copy constructor because of the dynamically
//   allocated memory in this class, see class notes.
//   You shouldn't use these functions in your final code, but they may be useful for debugging
//   purposes, or for the extra credit.   
   Hand (const Hand & hand_to_copy) 
     : hand_holder(hand_to_copy.hand_holder), number_of_aces(hand_to_copy.number_of_aces), 
       number_of_cards(hand_to_copy.number_of_cards), value(hand_to_copy.value) 
   { 
     for (int i = 0; i < number_of_cards; i++)
        cards[i] = new Card(*(hand_to_copy.cards[i]));

     std::cout <<  "Your code called the copy constructor for Hand." <<
        "  It shouldn't do that unless maybe you're doing the extra credit.  FYI"  << std::endl;
   }
   void operator= (const Hand & hand_to_copy)  
   { 
     for (int i = 0; i < number_of_cards; i++)
       delete cards[i];
     hand_holder = hand_to_copy.hand_holder;
     number_of_aces = hand_to_copy.number_of_aces;
     number_of_cards = hand_to_copy.number_of_cards;
     value = hand_to_copy.value;
     for (int i = 0; i < number_of_cards; i++)
       cards[i] = new Card(*(hand_to_copy.cards[i]));

     std::cout <<  "Your code called the assignment operator for Hand." <<
        "  It shouldn't do that unless maybe you're doing the extra credit.  FYI"  << std::endl;
   }
};

#endif
