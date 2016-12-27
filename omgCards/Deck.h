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
	int getSize();
	void shuffle();
	Card* deal();
	void display() const;
	string toString();

	//Deck(const Deck& other);
	//Deck& operator = (const Deck& other);
	//~Deck();
	friend ostream& operator << (ostream& output, const Deck& d);
};


#endif

