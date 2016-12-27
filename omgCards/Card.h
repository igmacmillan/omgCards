#ifndef CARD_H
#define CARD_H

#include <iostream>
#include<string>
using namespace std;

class Card
{
private:
	static string rankAsStr[13];
	int rank;
	static string suitAsStr[4];
	int suit;
	int value;
public:
	Card();
	Card(int r, int s);
	Card(int r, int s, int v);
	void setRank(int r);
	void setSuit(int s);
	void setValue(int v);
	int getRank();
	int getSuit();
	int getValue();
	int compareTo(const Card& otherCard);
	int compareBySuit(const Card& otherCard);
	int compareByRank(const Card& otherCard);
	int compareByValue(const Card& otherCard);
	string toString();
	void display();
	friend ostream& operator << (ostream& output, const Card& c);
};

#endif


