#include "Hand.h"
#include "LinkedList.h"
#include "Deck.h"
#include "Card.h"
#include "Stack.h"

#include <iostream>
#include <cstdlib>


Hand::Hand()
{
	hand = new LinkedList;
}


Hand::Hand(Hand& otherHand)
{
	hand = new LinkedList(*otherHand.hand);
}

Hand::~Hand()
{
	delete hand;
}

Hand& Hand::operator =(Hand& otherHand)
{
	if (this == &otherHand)
		return *this;
	else
	{
		delete hand;
		hand = new LinkedList(*otherHand.hand);
		return *this;
	}
}

int Hand::getCount()
{
	return hand->getSize();
}

//void insertByRank(Card*);
void Hand::insertLast(Card* c)
{
	hand->insertAtIndex(c, (hand->getSize()));
}

void Hand::remove()
{
	//delete hand;
	int size = hand->getSize();
	for (int i = 0; i < size; i++)
		hand->removeAtIndex(0);
	//hand = NULL;
}

int Hand::evaluate() const
{
	int total = 0;
	for (int i = 0; i < hand->getSize(); i++)
	{
		Card* c = hand->getAtIndex(i);
		total += c->getValue();
	}
	return total;
}
void Hand::convertAcesDown()
{
	for (int i = 0; i < hand->getSize(); i++)
	{
		if (hand->getAtIndex(i)->getValue() == 11)
			hand->getAtIndex(i)->setValue(1);
	}
}

int Hand::compare(const Hand& otherHand)
{
	return evaluate() - otherHand.evaluate();
}
bool Hand::isEmpty()
{
	if (hand == NULL)
		return true;
	else
		return false;
}

void Hand::displayHand() const
{
	for (int i = 0; i < hand->getSize(); i++)
	{
		hand->getAtIndex(i)->display();
		cout << endl;
	}
}

ostream& operator<<(ostream& output, const Hand& h)
{
	//output h.hand;
	for (int i = 0; i < h.hand->getSize(); i++)
	{
		h.hand->getAtIndex(i)->display();
	}
	return output;
}
