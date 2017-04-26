//  Blackjack game code.  Dr. Klein 6/20/2016
#include "Blackjack.h"
#include <iostream>

using namespace std;

//  Function to take player's bet.
double takeBet(const double & playerMoney)
{
  double bet; 

  do 
  {
  cout << "Enter bet in dollars, 0 to quit: ";
  cin >> bet;
  if (bet > playerMoney)
    cout << "You don't have that much money!  Enter a lower bet." << endl;
  } while (bet > playerMoney);

  return bet;
}


//  main function
int main()
{
//  Seed the random number generator with current time
  std::srand( static_cast<unsigned int>(time(0)));

//  Player starts with 300 dollars
  double playerMoney = 300.0, playerBet;
//  integer to hold the round number
  int roundNum = 1;

  cout << "Player starts with " << playerMoney << " dollars" << endl;

  cout << "Round " << roundNum << endl;
//  Take bet
  playerBet = takeBet(playerMoney); 


//  Keep playing Blackjack until the player bets 0 dollars, or they are broke.
  while ((playerBet > 0.0) && (playerMoney > 0.0))
  { 
//   Instantiate Blackjack object, which initializes round. 
    Blackjack myBlackjack(playerMoney); 
//   Play the round of Blackjack.  Member function 'play' should return the updated
//     playerMoney.
    playerMoney = myBlackjack.play(playerBet);
    cout<<"your still have: "<<playerMoney<<endl;
//   Take a new bet unless the player is broke.
    if (playerMoney > 0.0)
    {
      cout << endl << endl << "Round " << ++roundNum << endl;
      playerBet = takeBet(playerMoney); 
    }
  }

}
