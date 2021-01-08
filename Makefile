#Makefile for Crazy Eights
CC = g++ -std=c++11 -g
exe_file = crazy_eights
$(exe_file): Player.o Card.o Deck.o Prog.o Hand.o Game.o
	$(CC) Player.o Prog.o Card.o Deck.o Hand.o Game.o -o $(exe_file)

Prog.o: Prog.cpp
	$(CC) -c Prog.cpp
Card.o: Card.cpp
	$(CC) -c Card.cpp
Deck.o: Deck.cpp
	$(CC) -c Deck.cpp
Player.o: Player.cpp
	$(CC) -c Player.cpp
Hand.o: Hand.cpp
	$(CC) -c Hand.cpp
Game.o: Game.cpp
	$(CC) -c Game.cpp

%.o: %.cpp
	$(CC) -c $<
clean:
	rm -f *.out *.o crazy_eights
