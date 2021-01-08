#ifndef GAME_H
#define GAME_H

#include "./Deck.h"
#include "./Player.h"

class Game {
	private:
		Deck deck;
		Player *players;
		Card pile;
		bool player1canplay;
		bool player2canplay;
	public:

		~Game();
		bool get_player1_status();
		bool get_player2_status();
		void set_player1_status(bool);
		void set_player2_status(bool);


		void set_deck(Deck& userdeck);
		Deck* get_deck();
		Player* get_player_array();
		void set_player_array(Player* playerarray);
		void set_pile(Card);
		Card* get_pile();
		Game();
		void delete_players();
		void player_move();
		void bot_move();
		void show_pile();
		int get_player_input();
		void print_extras();
		bool test_player_input(int input);
		void update_pile(Card);
		void print_board();
		bool is_game_over();
		bool deck_out_of_cards();
		void play();
		void print_winner();

};

#endif			
