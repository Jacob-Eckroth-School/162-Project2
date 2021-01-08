#ifndef HAND_H
#define HAND_H


#include "./Card.h"
#include "./Deck.h"

class Hand{
	private:
		Card* cards;
		int n_cards;
	public:
		int get_cards_in_hand();
		void set_cards_in_hand(int number);
		Card* get_hand_cards();
		void update_hand(Card* newhand);
		~Hand();
		Hand(const Hand&);
		Hand& operator = (const Hand&);
		Hand();	
		void init(Deck*);	
		void delete_hand();
		void print_hand();
		void draw_to_hand(Card drawncard);
		void play_onto_pile(Card *, int,bool);
		int get_newsuit();
};

#endif
