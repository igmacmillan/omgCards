#include "Game.h"
#include <iostream>
#include <string.h>

Game::Game()
	:wager(0)
{
	string n;
	cout << "Welcome to Ian's Sunnyside Casino." << endl
		<< "Enjoy the BlackJack" << endl << endl;

	//Player player();
	player.setName();
	//Player dealer("Dealer");
	Deck deck;
	LinkedList list;
}

/*
void Game::createDeck()
{
	d.shuffle();
	return d;
}
*/

void Game::createList()
{
	deck.shuffle();
	if (list.getSize() > 0)
	{
		cout << "Sorry we are a small casino, and we only have one deck. Please play again. Thank you.\n";
		exit(0);
	}
	for (int i = 0; i < 52; i++)
		list.insertAtIndex(deck.deal(), i);
}

void Game::playGame()
{
	//cout << "Welcome to Ian's Sunnyside Casino." << endl
		//<< "Enjoy the BlackJack" << endl << endl;
	
	char again;
	do
	{
		round();
		cout << "Play again?(Y/N)\n";
		cin >> again;
		cout << endl;
	} while (again == 'Y' || again == 'y');

	cout << "Thanks for playing!\n";
}

void Game::round()
{
	int playerTotal, dealerTotal, prize;
	if (list.getSize() < 10)
	{
		cout << "Shuffling...\n";
		createList();
	}
	bet();
	deal();
	playerTotal = playerTurn();
	dealerTotal = dealerTurn();
	prize = assess(playerTotal, dealerTotal);
	prizes(prize);
	player.reset();
	dealer.reset();
}

void Game::bet()
{
	cout << player;
	cout << "How much would you like to bet this hand? ";
	cin >> wager;
	while (wager > player.getPoints() || wager < 0)
	{
		cout << "You dont have enough money. Please enter a valid amount: ";
		cin >> wager;
	}
	cout << endl;
}

void Game::deal()
{
	string name = player.getName();
	player.addCard(list.removeAtIndex(0));
	dealer.addCard(list.removeAtIndex(0));
	player.addCard(list.removeAtIndex(0));
	//cout << player.getName() << "'s Hand\n";
	cout << name << "'s Hand\n";
	player.showHand();
	cout << endl << "Dealer's Hand\n";
	dealer.showHand();
	cout << "???\n" << endl;
	dealer.addCard(list.removeAtIndex(0));
}

int Game::playerTurn()
{
	char decision;
	int t = player.evaluate();
	if (t == 21)
		return 99;
	cout << "Would you like to hit or stay(H/S): ";
	cin >> decision;
	while (decision != 'h' && decision != 'H' && decision != 's' && decision != 'S')
	{
		cout << "That is not a valid options. Would you like to hit or stay(H/S): ";
		cin >> decision;
	}
	while (decision == 'h' || decision == 'H')
	{
		player.addCard(list.removeAtIndex(0));
		player.showHand();
		cout << endl;
		t = player.evaluate();
		if (t > 21)
		{
			cout << "You busted." << endl;;
			break;
		}
		cout << "Would you like to hit or stay(H/S): ";
		cin >> decision;
		while (decision != 'h' && decision != 'H' && decision != 's' && decision != 'S')
		{
			cout << "That is not a valid options. Would you like to hit or stay(H/S): ";
			cin >> decision;
		}
	}
	return t;
}

int Game::dealerTurn()
{
	int t = dealer.evaluate();
	if (t == 21)
		return 99;
	cout << endl << "Dealer's Hand\n";
	dealer.showHand();
	cout << endl;
	while (t < 17)
	{
		cout << "Dealer hits\n";
		dealer.addCard(list.removeAtIndex(0));
		cout << "Dealer's Hand\n";
		dealer.showHand();
		cout << endl;
		t = dealer.evaluate();
	}
	if (t > 21)
		cout << "Dealer busts.\n";
	return t;	
}

int Game::assess(int p, int d)
{
	if (p == 99 && d == 99)
		return 0;
	else if (p == 99)
		return 1;
	else if (d == 99)
		return 2;
	else if (p > 21 && d > 21)
		return 3;
	else if (p > 21 && d <= 21)
		return 4;
	else if (p <= 21 && d > 21)
		return 5;
	else if (p == d)
		return 6;
	else if (p > d)
		return 7;
	else
		return 8;
}

void Game::prizes(int i)
{
	switch (i)
	{
	case 0:
		cout << "Double BlackJack. PUSH\n" << player << endl;
		break;
	case 1:
		cout << "You have BlackJack. You WIN\n";
		player.setPoints(wager);
		cout << player << endl;
		break;
	case 2:
		cout << "Dealer has BlackJack. You LOSE\n";
		player.setPoints(-wager);
		cout << player << endl;
		break;
	case 3:
		cout << "Both player and dealer busted. PUSH\n" << player << endl;
		break;
	case 4:
		cout << "You busted. Dealer WINS\n";
		player.setPoints(-wager);
		cout << player << endl;
		break;
	case 5:
		cout << "Dealer busts. You WIN\n";
		player.setPoints(wager);
		cout << player << endl;
		break;
	case 6:
		cout << "PUSH\n";
		cout << player << endl;
		break;
	case 7:
		cout << "You WIN\n";
		player.setPoints(wager);
		cout << player << endl;
		break;
	case 8:
		cout << "Dealer WINS\n";
		player.setPoints(-wager);
		cout << player << endl;
		break;
	}
}