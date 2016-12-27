#include "Card.h"

#include <iostream>
#include <cstring>
using namespace std;

string Card::rankAsStr[13] = { "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King" };

string Card::suitAsStr[4] = { "Spade", "Heart", "Club", "Diamond" };

Card::Card(int r, int s)
{
	rank = r;
	suit = s;
	value = r + 1;
}

Card::Card(int r, int s, int v)
{
	rank = r;
	suit = s;
	value = v;
}

Card::Card()
{
	rank = 1;
	suit = 3;
	value = 2;

}

void Card::setRank(int r)
{
	rank = r;
}

void Card::setSuit(int s)
{
	suit = s;
}

void Card::setValue(int v)
{
	value = v;
}

int Card::getRank()
{
	return rank;
}

int Card::getSuit()
{
	return suit;
}

int Card::getValue()
{
	return value;
}

int Card::compareTo(const Card& otherCard)
{
	if (rank - otherCard.rank != 0)
	{
		return (rank - otherCard.rank);
	}
	else
	{
		return (suit - otherCard.suit);
	}

}

int Card::compareBySuit(const Card& otherCard)
{
	return (suit - otherCard.suit);
}

int Card::compareByRank(const Card& otherCard)
{
	return (rank - otherCard.rank);
}

int Card::compareByValue(const Card& otherCard)
{
	return (value - otherCard.value);
}

string Card::toString()
{
	return rankAsStr[rank] + " of " + suitAsStr[suit];
}

void Card::display()
{
	cout << rankAsStr[rank] << " of " << suitAsStr[suit];
}

ostream& operator << (ostream& output, const Card& c)
{
	output << c.rankAsStr[c.rank] << " of " << c.suitAsStr[c.suit];
	return output;
}


