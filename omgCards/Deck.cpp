
#include "Deck.h"
#include "Card.h"
#include "Stack.h"

#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

	Deck::Deck()
		:deck(new Stack()), size(0)
	{
		for (int s = 0; s < 4; s++)
		{
			for (int r = 0; r < 13; r++)
			{
				deck->push(new Card(r, s));
				size++;
			}
		}
	}

	
	int Deck::getSize()
	{
		return size;
	}

	void Deck::shuffle()
	{
		srand(time(NULL));
		Card* temp[52];
		for (int i = 51; i >= 0; i--)
			temp[i] = deck->pop();

		for (int i = 0; i < 104; i++)
		{
			int n1 = rand() % 52;
			int n2 = rand() % 52;
			Card* a = temp[n1];
			temp[n1] = temp[n2];
			temp[n2] = a;
		}
		for (int i = 0; i < 52; i++)
			deck->push(temp[i]);
	}
	Card* Deck::deal()
	{
		return deck->pop();
	}
	void Deck::display() const
	{
		//for (int i = 0; i < size; i++)
		{
			//deck[i].display();
			deck->display();
		}
	}

	string Deck::toString()
	{	
		return  deck->toString();
	}

	/*
	Deck::Deck(const Deck& other)
		:deck(Stack(*other.deck)), size(0)
	{
		for (int s = 0; s < 4; s++)
		{
			for (int r = 0; r < 13; r++)
			{
				deck->push(new Card(r, s));
				size++;
			}
		}
	}
	Deck& operator = (const Deck& other);
	
	Deck::~Deck()
	{
		(deck->~Stack());
		delete deck;

	}
	*/

	ostream& operator << (ostream& output, const Deck& d)
	{
		d.deck->display();
		return output;
	}

