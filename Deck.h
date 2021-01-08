#ifndef DECK_H
#define DECK_H


#include "./Card.h"


class Deck{
	private:
		Card *cards;
		int n_cards;
	public:
		void set_card_amount(int amount);
		int get_card_amount();
		Card* get_cards();
		void set_cards(Card *cards);
		void fill_deck();
		Deck();
		~Deck();
		void delete_deck();
		void print_cards();
		Card draw_card();
};

#endif
