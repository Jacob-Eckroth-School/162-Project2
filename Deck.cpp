#include "./Deck.h"
#include <cstdlib>
#include <iostream>
using namespace std;
/*****************************
 * Function: set_card_amount(int)
 * Purpose: Mutator function for the n_cards, updates it to hold the int amount.
 * ***************************/
void Deck::set_card_amount(int amount){
	n_cards = amount;	
}
/*****************************
 * Function:get_card_amount()
 * Purpose: Retriever function that returns the int n_cards
 * ***************************/
int Deck::get_card_amount(){
	return n_cards;
}
/*****************************
 * Function:get_cards()
 * Purpose: Retriever function for the array of cards in the deck. Returns a pointer to the card array
 * ***************************/
Card* Deck::get_cards(){
	return cards;
}
/****************************
 * Function: set_cards(Card*)
 * Purpose: Mutator function that updates the cards member variable to contain the new card array inputcards
 * *************************/	
void Deck::set_cards(Card* inputcards){	
	delete_deck();
	cards = inputcards;
}

/****************************
 * Function: ~Deck()
 * Purpose: deconstructor function for the Deck object, that deletes the card array in the deck.
 * *************************/	
Deck::~Deck(){

	delete[] cards;	
	cards = NULL;
}
/****************************
 * Function: Deck()
 * Purpose: Constructor function that fills the deck object with 52 cards shuffled.  
 * *************************/	
Deck::Deck(){

	set_card_amount(52);
	cards = new Card[n_cards];
	fill_deck();

}
/****************************
 * Function: fill_deck() 
 * Purpose: Fills the deck with 52 random cards.
 * *************************/	

void Deck::fill_deck(){
	srand(time(NULL));	
	bool cardused[4][13];
	int generated_rank = 0;
	int generated_suit = 0;		
	for(int i = 0; i < 4; i++){ //loops through all cards
		for(int j = 0; j < 13; j++){
			cardused[i][j] = false;
		}
	}
	for(int i = 0; i < n_cards; i++){
		do{
			generated_rank = rand()%13;
			generated_suit = rand() % 4;
		}while(cardused[generated_suit][generated_rank]);//if card is used, generate a new random card	
		cards[i] = Card(generated_suit, generated_rank);
		cardused[generated_suit][generated_rank] = true;	
	}

}

/****************************
 * Function: delete_deck() 
 * Purpose: Frees the space taken by the cards array.
 * *************************/	

void Deck::delete_deck(){	
	delete[] cards;
	cards = NULL;
}
/****************************
 * Function: print_cards()
 * Purpose: Prints all the cards in the deck. Note, never called.
 * *************************/	
void Deck::print_cards(){
	for(int i = 0; i < get_card_amount(); i++){
		cout<<cards[i].get_card_name()<<i<<endl;
	}
}

/****************************
 * Function: draw_card()
 * Purpose: Returns the top card of the deck, and removes that card from the cards array.
 * *************************/	
Card Deck::draw_card(){
	Card topcard;
	topcard = cards[n_cards-1]; //51 at the start
	Card *newdeck = new Card[n_cards -1];
	for(int i = 0; i < n_cards-1; i++){ //update new deck

		newdeck[i] = cards[i];
	}
	delete_deck();
	cards = newdeck;
	n_cards--;
	return topcard;//returns the card to be drawn
}







