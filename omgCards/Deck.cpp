#include "Deck.h"
#include "Card.h"
#include "Stack.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

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
	Deck::Deck(int cap)
		:deck(new Stack(cap)), size(0)
	{
		
	}
	
	int Deck::getSize()
	{
		return size;
	}

	void shuffle()
	{
		
	}
	//Card* Deck::deal()
	//{

	//}
	void Deck::display()
	{
		for (int i = 0; i < size; i++)
		{
			deck[i].display();
		}
	}
	//string Deck::toString()
	//{}


