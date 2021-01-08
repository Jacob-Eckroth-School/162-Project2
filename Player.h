#ifndef PLAYER_H
#define PLAYER_H
#include "./Hand.h"
#include "./Deck.h"
class Player{
	private:
		Hand hand;
		string name;
	public:
		Hand *get_player_hand();
		void change_player_hand(Hand newhand);
		string get_player_name();
		void set_name(string name);
		void init(string, Deck*);	
		Player();

		bool can_play(Card);
		bool out_of_cards();
};











#endif
