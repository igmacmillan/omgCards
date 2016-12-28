#include "Card.h"
#include "Stack.h"
#include "Deck.h"
#include "LinkedList.h"
#include "Hand.h"
#include "Player.h"
#include "Game.h"

#include<iostream>
using namespace std;

int main()
{
	Game game;
	game.playGame();


	/*
	cout << "This displays the default card constructor:\n";
	Card c;
	cout << c;
	cout << endl << endl;
	
	Stack s;

	cout << "Adds 2 cards to a stack and test deck dislay\n";
	s.push(new Card(0, 0));
	s.push(new Card(4, 2));
	//s.display();
	cout << s;
	cout << endl;

	
	
	

	Stack s2;
	s2 = s;
	cout << "The below second stack was made equal to the first, but with a card added\n";
	
	s2.push(new Card(11, 3));
	s2.display();

	cout << endl << "original stack:\n";
	*s[0] = *s2[2];
	cout << s;
	*/

	/*
	Deck d;
	d.shuffle();
	//cout << d;
	string s;
	s = d.toString();
	//cout << d;
	cout << endl << "now i will make a linked list and print it\n";
	Card* c = new Card(0, 2);
	cout << "Card C is: " << *c << endl;
	LinkedList l;
	
	for (int i = 0; i < 10; i++)
		l.insertAtIndex(d.deal(), i);
	//l.insertAtIndex(c, 10);
	cout << l << endl;
	
	Hand h, h2;
	Player one("ian");
	one.addCard(l.removeAtIndex(0));
	one.addCard(l.removeAtIndex(0));
	Card* ace = new Card(0, 0);
	one.addCard(ace);
	cout << one;
	one.showHand();
	int total;
	total = one.evaluate();
	cout << "the total is: " << total;
	
	*/
	
	
	


	/*
	h.insertLast(l.removeAtIndex(0));
	cout << "This is my hand: " << h << endl << endl;
	h2.insertLast(l.removeAtIndex(0));
	cout << "reprinting the list\n" << l;
	cout << endl << endl << "The other hand is: " << h2;
	cout << endl << "Comparing the two hands";
	int compare;
	compare = h.compare(h2);
	if (compare > 0)
		cout << "The first hand wins";
	else
		cout << "The second had wins";
	*/
	





	/*
	LinkedList l2;
	l2 = l;


	l2.removeAtIndex(1);
	cout << "New list missing index 1: \n" << l2;

	cout << endl << "Original again\n" << l;
	
	
	
	
	cout << "Below is the new list from the copy constructor\n";
	LinkedList l2(l);
	cout << l2;
	Card* c1 = l2.getTail();
	cout << "The card at tail is" << *c1;
	
	
	l.remove(c);
	cout << l << endl;
	
	bool b;

	b = l.contains(c);
	if (b)
		cout << "The card is in the deck";
	else
		cout << "No, the card is not in the deck";
		
	Card* h, *t;
	Card* i;
	t = l.getTail();
	h = l.getHead();
	i = l.getAtIndex(4);
	int size = l.getSize();
	cout << "The head is: " << *h << endl
		<< "The tail is: " << *t << endl
		<< "The card at i is: " << *i << endl;
	
	Card* c = l.removeAtIndex(2);
	cout << "The card removed is: " << *c << endl;
	cout << "The new list is:\n" << l;
	cout << "The size is: " << l.getSize() << endl;
	*/




	

	/*
	string deck;
	deck = s.toString();
	for (int i = 0; i < 3; i++)
	{
		cout << deck[i];
		cout << endl;
	}
	
	cout << "\nTest pop\n";
	Card* dealCard = s.pop();
	dealCard[0].display();
	cout << endl << endl << "Test pop 2nd time to ensure decrement works\n";
	dealCard = s.pop();
	dealCard[0].display();
	cout << endl << endl;

	cout << "Test peek\n";
	Card* top = s.peek();
	top[0].display();

	
	cout << endl << endl << "test build deck and print it\n";
	Deck d;
	//d.shuffle();
	d.display();

	

	

	
	int go;
	cout << endl << "Press any key to continue";
	cin >> go;
	*/
	return 0;
}