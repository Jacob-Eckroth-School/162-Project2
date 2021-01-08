#include "./Deck.h"
#include "./Player.h"
#include <iostream>
using namespace std;

/*******************
 * Function: get_player_hand()
 * Purpose: Getter function that returns a pointer to the player hand.
 * ****************/
Hand *Player::get_player_hand(){
	return &hand;
}
/*******************
 * Function: change_player_hand(Hand)
 * Purpose: Mutator function that updates the playerhand to be the new hand passed to the function.
 * ****************/
void Player::change_player_hand(Hand newhand){
	hand = newhand;
}

/*******************
 * Function: get_player_name()
 * Purpose: getter function that returns a string that contains the player name.
 * ****************/
string Player::get_player_name(){
	return name;
}
/*******************
 * Function: get_player_name()
 * Purpose: getter function that returns a string that contains the player name.
 * ****************/
void Player::set_name(string newname){
	name = newname;
}
/*******************
 * Function: init(string,Deck*) 
 * Purpose: Initializes the player object with the correct stringname, and cards in hand using the deck pointer.
 * ****************/
void Player::init(string playername, Deck *deck){

	hand.init(deck);
	set_name(playername);
}

/*******************
 * Function: Player() 
 * Purpose: A stupid-ass default player-constructor
 * ****************/
Player::Player(){

	set_name("hi");
}
/*******************
 * Function: can_play(Card) 
 * Purpose: Returns true if the player is able to legally play any cards in their hand onto the pile Card, false if they cannot. 
 * ****************/
bool Player::can_play(Card pile){
	int pilerank = pile.get_rank();
	int pilesuit = pile.get_suit();
	for(int i = 0; i < get_player_hand()->get_cards_in_hand(); i++){//for all the cards in their hand.
		if(get_player_hand()->get_hand_cards()[i].get_rank() == pilerank || get_player_hand()->get_hand_cards()[i].get_suit() == pilesuit || get_player_hand()->get_hand_cards()[i].get_rank() == 7){//if the card suit is equal to the pile suit, or the card rank is equal to the rank, or it's an 8
			return true;
		}
	}
	return false;
}
/*******************
 * Function: out_of_cards()
 * Purpose: returns true if the player has zero cards in their hand, false if they have any cards in their hand. 
 * ****************/
bool Player::out_of_cards(){
	if(!(get_player_hand()->get_cards_in_hand())){//if the player is out of cards
		return true;
	}
	return false;

}




