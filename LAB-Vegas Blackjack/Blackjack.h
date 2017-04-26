#ifndef BLACKJACK_H
#define BLACKJACK_H

#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>
#include <string>
#include "Hand.h"
#include <ctime>
#include <cstdlib>

enum Hit_or_Stand { HIT, STAND };

class Blackjack
{
  private:
    double playerMoney, playerBet;
//  Objects of class Hand representing the player's hand and the dealer's hand.
    Hand playerHand, dealerHand;
//  An object of enumerated type Hit_or_Stand that holds the player's choice.
    Hit_or_Stand playerChoice;

//  Member function to obtain the player's choice.
    Hit_or_Stand queryPlayer(); //  Write an implementation of this function.  It must
                                //   keep querying the player until a valid choice is
                                //   entered, then return that choice as a Hit_or_Stand. 
    

  public:
//   Constructor.  I have written this implementation for you.
    Blackjack(double money)
     :playerMoney(money), playerHand("Player"), dealerHand("Dealer")
    {}


//   Member function 'play' should play a round of Blackjack according to the rules
//    of the game, and return the updated playerMoney. 
    double play(double bet); // Write an implementation of this function. 
};

#endif
