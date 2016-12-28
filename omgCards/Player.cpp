#include "Player.h"
#include <iostream>
#include <string.h>
#include <stdlib.h>

Player::Player()
	:name("player1"), points(200)
{
		Hand hand;
}

Player::Player(string name)
	: name(name), points(200)
{
	Hand hand;
}

void Player::setName()
{
	string n;
	cout << "Please enter your name: ";
	cin >> n;
	name = n;
	cout << endl;
}

string Player::getName()
{
	return name;
}

void Player::addCard(Card* c)
{
	hand.insertLast(c);
}

int Player::evaluate()
{
	int total = 0;
	total = hand.evaluate();
	if (total > 21)
	{
		hand.convertAcesDown();
	}
	total = hand.evaluate();
	return total;
}

void Player::showHand()
{
	hand.displayHand();
}

void Player::setPoints(int bet)
{
	points = points + bet;
}

int Player::getPoints()
{
	return points;
}

void Player::reset()
{
	hand.remove();
}

ostream& operator<<(ostream& output, const Player& p)
{
	output << "Name: " << p.name << endl
		<< "Money: " << p.points << endl;

	return output;
}