/******************************
 * Program: crazy_eights
 * Author: Jacob Eckroth
 * Date: 1/28/2020
 * Description: Plays a game of crazy eights against a bot
 * Input: Player input
 * Output: The fun that you get from playing crazy eights against a bot, which is approximately zero
 * ***************************/
#include "./Card.h"
#include "./Deck.h"
#include "./Game.h"
#include <iostream>
#include <cstdlib>
using namespace std;

bool play_again();

//Do I really need a function header for my main function. I mean come on guys, this is ridiculous
int main(){ //You know what this is
	do{
		Game game;//I wonder what this line does.
		game.play(); //such vague function names
	}while(play_again()); //tests if the player wants to play again
	return 0;
}

/*************************
 * Function: play_again()
 * Purpose: Returns a bool that represents whether the player wants to play the game again.
 * **********************/
bool play_again(){
	string userinput;
	bool validinput = false;
	cout<<"Do you want to play again?(0:no, 1:yes):";
	do{
		getline(cin,userinput);
		if(userinput == "0" || userinput == "1"){
			validinput=true;
		}else{
			cout<<"Invalid input. Please enter either 0 or 1:";
		}
	}while(!validinput);
	return stoi(userinput);
}

