#include "./Game.h"
#include <iostream>
#include <string>
using namespace std;
/***********************
 * Function: set_deck(Deck&)
 * Purpose: Mutator function for the deck member variable, updates it to the deck pased to the function.
 * ********************/
void Game::set_deck(Deck &userdeck){
	deck = userdeck;
}
/***********************
 * Function: get_deck()
 * Purpose: returns a pointer to the deck member variable.
 * ********************/
Deck* Game::get_deck(){
	return &deck;
}
/***********************
 * Function: get_player_array()
 * Purpose: returns a pointer to the player member variable array
 * ********************/
Player* Game::get_player_array(){
	return players;
}
/***********************
 * Function: set_player_array(Player*)
 * Purpose: Updates the players member variable to contain the info passed by the user.
 * ********************/
void Game::set_player_array(Player* playerarray){
	delete[] players;
	players = playerarray;
}

/***********************
 * Function: get_pile()
 * Purpose: returns a pointer to the card on the pile.
 * ********************/
Card* Game::get_pile(){
	return &pile;
}

/***********************
 * Function: set_pile(Card)
 * Purpose: updates the pile member variable to contain the card passed to this function.
 * ********************/
void Game::set_pile(Card newpile){
	pile = newpile;
}
/***********************
 * Function: get_player1_status();
 * Purpose: Getter function for the player1canplay member variable.
 * ********************/
bool Game::get_player1_status(){
	return player1canplay;
}
/***********************
 * Function: get_player2_status();
 * Purpose: Getter function for the player2canplay member variable.
 * ********************/
bool Game::get_player2_status(){
	return player2canplay;
}

/***********************
 * Function: set_player1_status();
 * Purpose: setter function for the player2canplay member variable Updates it to contain the newdata.
 * ********************/
void Game::set_player1_status(bool newdata){
	player1canplay = newdata;
}
/***********************
 * Function: set_player2_status();
 * Purpose: setter function for the player2canplay member variable Updates it to contain the newdata.
 * ********************/
void Game::set_player2_status(bool newdata){
	player2canplay = newdata;
}

/***********************
 * Function: ~Game();
 * Purpose: Destructor function for the Game object that frees the space taken by the players array.
 * ********************/
Game::~Game(){
	delete[] players;
	players = NULL;

}
/***********************
 * Function: Game();
 * Purpose:default Constructor function for the game that sets up the game when the game object is created.
 * ********************/
Game::Game(){

	string player1name = "User";
	string player2name = "Bot";
	player1canplay = false;
	player2canplay = false;
	cout<<"cool"<<endl;
	players = new Player[2];
	cout<<"wow"<<endl;

	players[0].init(player1name,get_deck());

	players[1].init(player2name,get_deck());

	set_pile(get_deck()->draw_card());

	get_deck()->fill_deck();


}
/***********************
 * Function: delete_players()
 * Purpose: frees the space taken by the player member variable array
 * ********************/
void Game::delete_players(){
	delete[] players;
	players = NULL;
}
/***********************
 * Function: player_move()
 * Purpose: makes the player select a card, and makes sure the card is playable onto the pile.
 * ********************/
void Game::player_move(){
	int cardchoice;
	bool validinput ;
	int can_play;
	bool drawcard =false;
	bool is_eight = false;
	bool player1done = false;
	cout<<"\e[2J";//clear screen command
	do{
		cout<<"The bot played a "<<get_pile()->get_card_name()<<endl<<endl; //UI stuff. This could be removed and nothing would really change.
		can_play = get_player_array()[0].can_play(*get_pile());
		if(!can_play && deck_out_of_cards()){ //If the player can't play and the deck is out of cards i.e. player one can't play anymore.
			player1done = true;
			break;
		}
		print_board(); //prints the board
		cardchoice = get_player_input();
		validinput = test_player_input(cardchoice);
		if(!validinput && can_play){ //if the user can play a card in their hand, but they don't select that card
			cout<<"\e[2J\033[1;31mYou can't play that card! Try again!\033[0m"<<endl;
		}else if(!can_play){ //if the user can't play at all.
			players[0].get_player_hand()->draw_to_hand(get_deck()->draw_card());
			cout<<"\e[2J\033[1;31mYou can't play any cards. You have to draw a card.\033[0m"<<endl;
		}
	}while(!validinput);
	if(!player1done){ //if the player actually can successfully play
		players[0].get_player_hand()->play_onto_pile(get_pile(),cardchoice,true);
	}	
}

/***********************
 * Function: get_player_input() 
 * Purpose: returns an int that the player inputs between 1, and the amount of cards in their hand. Error handles this as well.
 * ********************/
int Game::get_player_input(){
	int userinput = 0;
	bool validinput = true;
	string userstring = "";
	cout<<"Which card do you want to play?(1-"<<players[0].get_player_hand()->get_cards_in_hand()<<"):";
	do{	
		if(!validinput){
			cout<<"Invalid input! Please enter an integer between 1 and "<<players[0].get_player_hand()->get_cards_in_hand()<<":";
		}
		validinput = true;
		getline(cin,userstring);
		for(int i = 0; i < userstring.length(); i++){
			if(userstring[i] > '9' || userstring[i] < '0'){ //if it's not an integer
				validinput = false;
			}
		}
		if(userstring == ""){
			validinput = false;
		}

		if(validinput){
			if((stoi(userstring) > players[0].get_player_hand()->get_cards_in_hand())|| (stoi(userstring) <= 0)){ //if that card doesn't actually exists in their hand.
				validinput = false;
			}
		}

	}while(!validinput);
	return stoi(userstring);//returns the int of the string entered by the user
}

/***********************
 * Function: bot_move() 
 * Purpose: Contains functionality to make the bot choose a card and move/draw cards if necessary
 * ********************/
void Game::bot_move(){

	bool player2done = false;
	bool can_play;
	int cardchoice = 0;
	can_play = get_player_array()[1].can_play(*get_pile());//calls canplay function from player object
	while(!(players[1].can_play(*get_pile()))){
		if(!can_play && deck_out_of_cards()){ //if the deck is out of cards, and the bot can't play any cards from it's hand. i.e. the bot is done playing for the game.
			player2done = true;
			break;
		}

		players[1].get_player_hand()->draw_to_hand(get_deck()->draw_card());

	}

	if(!player2done){ //if player2 is not done.
		for(int i = 0; i < players[1].get_player_hand()->get_cards_in_hand();i++){ //go through every card in the bot's hand
			if(players[1].get_player_hand()->get_hand_cards()[i].get_suit() == get_pile()->get_suit() || players[1].get_player_hand()->get_hand_cards()[i].get_rank() == get_pile()->get_rank() || players[1].get_player_hand()->get_hand_cards()[i].get_rank() == 7){ //if the card in their hand either matches the rank or suit of the pile, or it's an eight.

				players[1].get_player_hand()->play_onto_pile(get_pile(),i+1,false);//play that card onto the pile.
				break;
			}
		}
	}

}
/***********************
 * Function: show_pile() 
 * Purpose: prints the card that is on top of the pile, in a pretty color.
 * ********************/
void Game::show_pile(){
	cout<<"\t\t\t\033[1;32mFace up card: \033[0m"<<get_pile()->get_card_name()<<endl;
}

/***********************
 * Function: print_extras() 
 * Purpose: prints how many cards the bot has in their hand, and how many cards the deck has in it.(very pretty colors)
 * ********************/
void Game::print_extras(){
	cout<<"\t\t\t\t\t\033[1;32mThe bot has "<<players[1].get_player_hand()->get_cards_in_hand()<<" cards in it's hand."<<endl;
	cout<<"\t\t\t\t\t\033[1;34mThe deck has "<<get_deck()->get_card_amount()<<" cards in it.\033[0m"<<endl;

}
/***********************
 * Function: test_player_input(int input) 
 * Purpose: returns true if the card chosen by the player can be played, false if it cannot.
 * ********************/

bool Game::test_player_input(int input){//input will be one higher than array position
	int pile_suit = get_pile()->get_suit();
	int pile_rank = get_pile()->get_rank();	
	int user_suit = players[0].get_player_hand()->get_hand_cards()[input-1].get_suit();
	int user_rank = players[0].get_player_hand()->get_hand_cards()[input-1].get_rank();
	if(pile_suit == user_suit || pile_rank == user_rank || user_rank == 7){ //if the rank or suit matches up or if it's an eight.

		return true;
	}
	return false;
}
/***********************
 * Function:print_board() 
 * Purpose: Prints the entire board, including the player hand and the pile card.
 * ********************/
void Game::print_board(){
	print_extras();
	players[0].get_player_hand()->print_hand();
	show_pile();

}
/***********************
 * Function:deck_out_of_cards() 
 * Purpose: returns true if there are 0 cars in the deck, or returns false.
 * ********************/
bool Game::deck_out_of_cards(){
	return !(get_deck()->get_card_amount()); //If there are 0 cards in the deck, return true. Else return false
}

/***********************
 * Function:play() 
 * Purpose: Plays the game, makes the bot move, and player move, until the game is over.
 * ********************/
void Game::play(){
	int gameover = 2; //change to 0 if bot wins, change to 1 if player wins
	bool gamestillgoing = true;
	do{

		if(get_player_array()[0].out_of_cards() || get_player_array()[1].out_of_cards()){ //if either player is out of cards

			break;
		}


		if(!deck_out_of_cards() || get_player1_status() || get_player2_status()) {//if the deck isn't out of cards and players can still play

			set_player1_status(get_player_array()[0].can_play(*get_pile())); //update whether the players can play or not.
			set_player2_status(get_player_array()[1].can_play(*get_pile()));	
			if(get_player1_status() || !deck_out_of_cards()){//if player 1 can play and the deck is not out of cards.		
				player_move();	
			}	
			if(get_player2_status()|| !deck_out_of_cards()){//refer to above	
				bot_move();	
			}
		}else{
			gamestillgoing = false;//game isn't going anymore
		}
	}while(gamestillgoing);
	print_winner();
}

/**************************
 * Function: print_winner()
 * Purpose: Prints the winner of the game, or says it's a tie if it's a tie.
 * ***********************/
void Game::print_winner(){

	int winner;
	bool istie = false;
	if(get_player_array()[0].get_player_hand()->get_cards_in_hand() > get_player_array()[1].get_player_hand()->get_cards_in_hand()){ //if the player has more cards than the bot
		winner = 1; //bot is winner

	}else if(get_player_array()[0].get_player_hand()->get_cards_in_hand() < get_player_array()[1].get_player_hand()->get_cards_in_hand()){ //if player has less cards than bot
		winner = 0; //winner is player

	}else{
		cout<<"It's a tie!"<<endl;//dude why do you even need to read this comment
		istie = true;	
	}
	if(!istie){
		cout<<"Player "<<get_player_array()[winner].get_player_name()<<" wins!!"<<endl;//say which player wins
	}
}

















