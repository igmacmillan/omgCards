#ifndef Deck_H
#define Deck_H
#include "stack.h"

class Deck
{
private:
	Stack* deck;
	int size;
public:
	Deck();
	Deck(int cap);
	int getSize();
	void shuffle();
	Card* deal();
	void display();
	string toString();
};


#endif

