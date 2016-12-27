#include "Card.h"
#include "Stack.h"
#include "Deck.h"
#include "LinkedList.h"

#include<iostream>
using namespace std;

int main()
{
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

	
	Deck d;
	d.shuffle();
	//cout << d;
	string s;
	s = d.toString();
	//cout << d;
	cout << endl << "now i will make a linked list and print it\n";
	//Card* c = d.deal();
	LinkedList l;
	//l.insertAtIndex(c, 0);
	for (int i = 0; i < 52; i++)
		l.insertAtIndex(d.deal(), i);
	cout << l << endl;
	/*
	Card* h, *t;
	Card* i;
	t = l.getTail();
	h = l.getHead();
	i = l.getAtIndex(4);
	int size = l.getSize();
	cout << "The head is: " << *h << endl
		<< "The tail is: " << *t << endl
		<< "The card at i is: " << *i << endl;
	*/
	Card* c = l.removeAtIndex(2);
	cout << "The card removed is: " << *c << endl;
	cout << "The new list is:\n" << l;
	cout << "The size is: " << l.getSize() << endl;





	

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