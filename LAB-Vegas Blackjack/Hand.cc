    #include "Hand.h"
    using namespace std;

    Hand::Hand(string type)
    {
    hand_holder = type;
    value=0;
    number_of_aces=0;
    number_of_cards=0;
    }


    Hand &Hand::operator++()
    {
    cout<< cards[number_of_cards]<<endl;
    cards[number_of_cards] = new Card();
    if (cards[number_of_cards]->getType()=="Ace") {
        number_of_aces++;
    }
    number_of_cards++;
    this->updateValue();
    return *this;
    }

    bool Hand::operator>(const Hand & rhs) const
    {
    return value>rhs.value;
    }

    bool Hand::operator>(int rhs) const
    {

    return value>rhs;
    }


    bool Hand::operator<(const Hand & rhs) const
    {
    return value<rhs.value;
    }

    bool Hand::operator<(int rhs) const
    {
    return value<rhs;
    }


    bool Hand::operator==(const Hand & rhs) const
    {
    return value==rhs.value;
    }

    bool Hand::operator==(int rhs) const
    {
    return value==rhs;
    }

    Hand::~Hand()
    {
    for (int i = 0; i < number_of_cards; ++i)
    {
        delete cards[i];
    }
    }

    void Hand::printHand()
    {
    cout<<hand_holder<<" card is: ";
    for (int i = 0; i < number_of_cards; ++i) {
        cout<<cards[i].getType()<<" ";
    }
    cout<<endl<<hand_holder<<" value is: "<<value<<endl;
    }

    void Hand::printFirstCard()
    {
    cout<<hand_holder<<" first card is: ";
    cout<<cards[0]->getType()<<endl<<endl<<endl;
    }

    void Hand::updateValue()
    {
    value=0;
    for (int i = 0; i < number_of_cards; ++i) {
        if (cards[i]->getType()!="Ace") {
            value += cards[i]->getValue();
        }
    }

    if (number_of_aces>0)
    {

        if ((value+number_of_aces-1+11)>21 ) {
            value+=number_of_aces;
        } else {

            value+=11+number_of_aces-1;
        }
        
    }


    }
