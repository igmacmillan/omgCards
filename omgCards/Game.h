#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Hand.h"
#include "LinkedList.h"
#include "Deck.h"
#include "Card.h"
#include "Stack.h"

#include <iostream>
#include <cstdlib>


class Game
{
private:
	Player player;
	Player dealer;
	Deck deck;
	LinkedList list;
	int wager;

public:
	Game();
	//Deck& createDeck();
	void createList();
	void bet();
	void playGame();
	void round();
	void deal();
	int playerTurn();
	int dealerTurn();
	int assess(int p, int d);
	void prizes(int i);

};

#endif // !"GAME_H"