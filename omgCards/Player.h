#ifndef PLAYER_H
#define PLAYER_H

#include "Hand.h"
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

class Player
{
private:
	string name;
	Hand hand;
	int points;
public:
	Player();
	Player(string name);
	void setName();
	string getName();

	void addCard(Card*);
	//get total value - if over 21 check for Aces of value 11 and convert to value 1
	int evaluate();

	void showHand();
	void setPoints(int bet);
	void reset();

	friend ostream& operator<<(ostream&, const Player&); //display Player's info

};

#endif