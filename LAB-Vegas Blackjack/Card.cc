#include "Card.h"

using namespace std;

Card::Card(){
	initial_value = rand() % 13+1;
	if(initial_value==1){
		typeString = "Ace";
	}else if(initial_value==2){
		typeString = "two";
	}else if(initial_value==3){
			typeString = "three";
	}else if(initial_value==4){
		typeString = "four";
	}else if(initial_value==5){
		typeString = "five";
	}else if(initial_value==6){
		typeString = "six";
	}else if(initial_value==7){
		typeString = "seven";
	}else if(initial_value==8){
		typeString = "eight";
	}else if(initial_value==9){
		typeString = "nine";
	}else if(initial_value==10){
		typeString = "ten";
	}else if(initial_value==11){
		initial_value = 10;
		typeString = "Jack";
	}else if(initial_value==12){
		initial_value = 10;
		typeString = "Queen";
	}else if(initial_value==13){
		initial_value = 10;
		typeString = "King";
	}

}


int Card::getValue () const{
	return initial_value;
}

string Card::getType() const{
	return typeString;
}


