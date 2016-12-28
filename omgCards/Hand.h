#ifndef HAND_H
#define HAND_H

#include "LinkedList.h"
#include "Deck.h"
#include "Card.h"
#include "Stack.h"
#include <iostream>
using namespace std;

class Hand
{
private:
	LinkedList* hand;
public:
	Hand();
	Hand(Hand&);
	~Hand();
	Hand& operator=(Hand&);
	int getCount();
	//void insertByRank(Card*);
	void insertLast(Card*);
	void remove();
	int evaluate() const;
	void convertAcesDown();
	int compare(const Hand&);
	bool isEmpty();
	void displayHand() const;
	friend ostream& operator<<(ostream&, const Hand&);
	
};

#endif