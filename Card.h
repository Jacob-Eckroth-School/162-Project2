#ifndef CARD_H
#define CARD_H
#include <string>
using namespace std;
class Card{

	private:
		int rank;
		int suit;
		string cardname;
	public:
		void set_rank(int rank);
		void set_suit(int suit);
		int get_rank();
		int get_suit();
		string get_card_name();
		void set_card_name();
		Card();
		Card(int,int);
		Card(const Card& old_obj);
};

#endif

