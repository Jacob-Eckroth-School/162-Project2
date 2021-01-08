#include "./Deck.h"
#include "./Card.h"

#include "./Hand.h"
#include <iostream>
/******************
 * Function: get_card_in_hand()
 * Purpose: returns the amount of cards in the hand object.
 * ****************/
int Hand::get_cards_in_hand(){
	return n_cards;
}
/******************
 * Function: set_card_in_hand(int)
 * Purpose: updates the amount of cards in the hand to int number.
 * ****************/
void Hand::set_cards_in_hand(int number){
	n_cards = number;
}

/******************
 * Function: get_hand_cards()
 * Purpose: returns a pointer to the array with all the cards in it in the hand object.
 * ****************/
Card* Hand::get_hand_cards(){
	return cards;
}

/******************
 * Function: update_hand(Card*)
 * Purpose: Updates the hand to hold a new array of cards, and frees previous used memory
 * ****************/
void Hand::update_hand(Card* newhand){
	delete_hand();
	cards = newhand;
}

/******************
 * Function: ~Hand()
 * Purpose: Hand deconstructor, that clears memory used by the cards array
 * ****************/

Hand::~Hand(){
	delete[]cards;
	cards = NULL;

}

/******************
 * Function: Hand(const Hand&)
 * Purpose: copy constructor for the hand object that is probably never called
 * ****************/
Hand::Hand(const Hand& old_obj){

	n_cards =old_obj.n_cards;
	cards = new Card[n_cards];	
}

/******************
 * Function: Hand::operator=(const Hand&)
 * Purpose: operator overload for the Hand object. Also never used!
 * ****************/
Hand& Hand::operator=(const Hand& old_obj){
	delete[] this->cards;	
	n_cards = old_obj.n_cards;
	cards = old_obj.cards;

	return *this;

}
/******************
 * Function: init(Deck*)
 * Purpose: Initializes the hand to hold all values that are necessary
 * ****************/
void Hand::init(Deck *deck){
	int startinghand = 7;//change this if the game ever changes
	set_cards_in_hand(startinghand);
	delete_hand();
	cards = new Card[get_cards_in_hand()];
	for(int i = 0; i < startinghand;i++){
		cards[i] = deck->draw_card();	
	}
}
/******************
 * Function:Hand() 
 * Purpose: Default hand constructor. Doesn't do much.
 * ****************/
Hand::Hand(){

	n_cards = 0;
	cards = NULL;

}
/******************
 * Function:draw_to_hand(Card) 
 * Purpose: Updates the hand to include one more card, in this case the drawncard Card.
 * ****************/
void Hand::draw_to_hand(Card drawncard){
	Card* newhand = new Card[n_cards+1];
	for(int i = 0; i < n_cards; i++){
		newhand[i] = cards[i];
	}
	newhand[n_cards] = drawncard;
	n_cards++;	
	update_hand(newhand);	
}

/******************
 * Function:delete_hand() 
 * Purpose: Frees dynamic memory taken by the cards array
 * ****************/
void Hand::delete_hand(){
	delete[] cards;
	cards = NULL;

}
/******************
 * Function:print_hand() 
 * Purpose: prints the player hand, and how many cards are in it.
 * ****************/
void Hand::print_hand(){
	cout<<"\033[0;35mYour hand:\033[0m";//colored text
	for(int i = 0; i < get_cards_in_hand(); i++){
		cout<<"\nCard "<<i+1<<": "<<cards[i].get_card_name();
	}
}
/******************
 * Function:get_newsuit() 
 * Purpose: returns an int between 0-3 that corresponds to which suit the player wants to switch to when they play an 8.
 * ****************/
int Hand::get_newsuit(){
	string userinput = "";
	bool validinput = true;
	cout<<"You played an 8! What suit do you want the bot to have to play?"<<endl;
	cout<<"(Clubs:0, Hearts:1, Spades:2, Diamonds:3):";
	do{
		getline(cin,userinput);
		for(int i = 0; i < userinput.length(); i++){
			if(userinput == "" || userinput[i] < '0' || userinput[i] >'3' || stoi(userinput) > 3 || stoi(userinput) < 0){ //testing if input is valid
				validinput = false;
				cout<<"Invalid input. Please enter an integer betwen 0 and 3:";
				break;
			}else{
				validinput = true;
			}
		}
	}while(!validinput);
	return stoi(userinput);
}
/******************
 * Function:play_onto_pile(Card*,int,bool) 
 * Purpose: Plays the card at cardfromhand position in a hand onto the pile, updates hand and pile accordingly.
 * ****************/
void Hand::play_onto_pile(Card* pile, int cardfromhand, bool isnotbot){

	Card* newhand = new Card[get_cards_in_hand()-1];
	int arrpos = 0;
	int newsuit = 0;
	int newrank= 0;
	bool iseight = false;

	for(int i = 0; i < get_cards_in_hand(); i++){
		if(!(i == cardfromhand-1)){ //if the card in the hand isn't the card played make the newhand have that card
			newhand[arrpos]=get_hand_cards()[i];
			arrpos++;
		}
	}
	if(get_hand_cards()[cardfromhand-1].get_rank() == 7 && isnotbot){//testing if it's an eight and its not a bot
		iseight = true; 
		newsuit = get_newsuit();
		newrank = get_hand_cards()[cardfromhand-1].get_rank();
	}
	if(iseight && isnotbot){//if it's an eight and the bot isn't playing
		Card newcard;
		newcard= Card(newsuit, newrank);
		*pile = newcard;
	}else{
		*pile = get_hand_cards()[cardfromhand-1];//update the pile.
	}
	delete_hand();
	cards = newhand;
	n_cards--;
}



