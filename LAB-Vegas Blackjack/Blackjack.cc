#include "Blackjack.h"


double Blackjack::play(double bet)
{

    ++playerHand;
    ++playerHand;
    ++dealerHand;
    ++dealerHand;
    dealerHand.printFirstCard();
    playerHand.printHand();

    if (playerHand==21) {
        if (dealerHand==21) {
            cout<<"push"<<endl;
            return playerMoney;
        } else {
            cout<<"player Blackjack"<<endl;
            return playerMoney+bet*1.5;
        }

    }
    if (playerHand>21) {
        cout<<"player lost GG"<<endl;
        return playerMoney-bet;
    }

    if (dealerHand>21) {
        cout<<"player win!"<<endl;
        return playerMoney+bet;
    }

    if (dealerHand==21) {
        cout<<"player Blackjack"<<endl;
        return playerMoney-bet;
    }

    //第一轮结束
    //player 加牌
    while(this->queryPlayer()==Hit_or_Stand::HIT) {
        ++playerHand;
        playerHand.printHand();
        if (playerHand>20) {
            break;
        }
    }

    if (dealerHand<17) {
        ++dealerHand;
        dealerHand.printHand();
    } else {
        dealerHand.printHand();
    }
    //选手结束,开始比较
    if (playerHand>21) {
        cout<<"player lost GG"<<endl;
        return playerMoney-bet;
    }

    if (playerHand==21) {
        if (dealerHand==21) {
            cout<<"push"<<endl;
            return playerMoney;
        } else {
            cout<<"player win!"<<endl;
            return playerMoney+bet;
        }
    }


    if(playerHand<21) {
        if (dealerHand>21) {
            cout<<"player win!"<<endl;
            return playerMoney+bet;
        } else if (dealerHand==21) {
            cout<<"player lost GG"<<endl;
            return playerMoney-bet;

        } else {
            if (playerHand==dealerHand) {
                cout<<"push"<<endl;
                return playerMoney;
            }
            playerHand>dealerHand ? cout<<"player win!"<<endl: cout<<"player lost GG"<<endl;
            playerHand>dealerHand ? playerMoney+=bet : playerMoney-=bet;
        }
    }


    return playerMoney;
}

Hit_or_Stand Blackjack::queryPlayer()
{
    string hitors="";
    cout<<"hit or stand: ";
    while(1) {
        cin>>hitors;
        if (hitors=="h") {
            return Hit_or_Stand::HIT;
        } else if(hitors=="s") {
            return Hit_or_Stand::STAND;
        }

        cout<<"enter again: "<<endl;
    }
}


