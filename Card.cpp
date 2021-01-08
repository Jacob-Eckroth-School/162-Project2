#include "./Card.h"
#include <iostream>
#include <string>
using namespace std;

/*************************
 * Function: Card(int,int)
 * Purpose: Card constructor that takes in 2 ints that represent the suit and rank. Sets the card name based on the suit and rank.
 * **********************/
Card::Card(int inputsuit, int inputrank){
	set_rank(inputrank);
	set_suit(inputsuit);
	set_card_name();
}

/*************************
 * Function: Card()
 * Purpose: Default card constructor with no parameters, makes sure values are ok
 * **********************/
Card::Card(){

	rank = 0;
	suit = 0;
	cardname = "";

}
/*************************
 * Function:set_rank(int) 
 * Purpose: mutator for the card rank
 * **********************/
void Card::set_rank(int inputrank){
	rank = inputrank;	
}
/*************************
 * Function:set_suit(int) 
 * Purpose: mutator for the card suit
 * **********************/
void Card::set_suit(int inputsuit){
	suit = inputsuit;
}
/*************************
 * Function:Card(const Card&) 
 * Purpose: Copy Constructor for card object. Note: Fairly certain this is never used.
 * **********************/
Card::Card(const Card& old_obj){

	rank = old_obj.rank;
	suit = old_obj.suit;
	cardname = old_obj.cardname;

}

/*************************
 * Function:get_rank() 
 * Purpose: Retriever function to return the rank of a card object
 * **********************/
int Card::get_rank(){
	return rank;

}
/*************************
 * Function:get_suit() 
 * Purpose: Retriever function to return the suit of a card object
 * **********************/
int Card::get_suit(){
	return suit;
}

/*************************
 * Function:get_card_name() 
 * Purpose: Retriever function to return the string that holds the card name in a card object
 * **********************/
string Card::get_card_name(){
	return cardname;
}

/*************************
 * Function:set_card_name()
 * Purpose: sets the card name string based on the rank and suit of the card.
 * **********************/

void Card::set_card_name(){
	string stringrank = "";
	string stringsuit = "";
	string cardtitle = "";
	switch(rank){
		case 0:
			stringrank = "Ace";
			break;
		case 1:
			stringrank = "Two";
			break;
		case 2:
			stringrank = "Three";
			break;
		case 3:
			stringrank = "Four";
			break;
		case 4:
			stringrank = "Five";
			break;
		case 5:
			stringrank = "Six";
			break;
		case 6:
			stringrank = "Seven";
			break;
		case 7:
			stringrank = "Eight";
			break;
		case 8:
			stringrank = "Nine";
			break;
		case 9:
			stringrank = "Ten";
			break;
		case 10:
			stringrank = "Jack";
			break;
		case 11:
			stringrank = "Queen";
			break;
		case 12:
			stringrank = "King";
			break;
		default:
			cout<<"shit we fucked up"<<endl;
			break;
	}
	switch(suit){
		case 0:
			stringsuit = "Clubs";
			break;
		case 1:
			stringsuit = "Hearts";
			break;
		case 2:
			stringsuit = "Spades";
			break;
		case 3:
			stringsuit = "Diamonds";
			break;
		default:
			cout<<"this should never happen"<<endl;
			break;
	}
	cardtitle = cardtitle + stringrank +" of " + stringsuit;
	cardname = cardtitle;
}





