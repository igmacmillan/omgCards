#include "Card.h"
#include "Stack.h"
#include "Deck.h"

#include<iostream>
using namespace std;

int main()
{
	cout << "This displays the default card constructor:\n";
	Card c;
	c.display();
	cout << endl << endl;
	
	Stack s;

	cout << "Adds 2 cards to a deck and test deck dislay\n";
	s.push(new Card(0, 0));
	s.push(new Card(4, 2));
	s.display();
	cout << endl;

	
	cout << "Add a 3rd card and print toString:\n";
	s.push(new Card(11, 3));
	
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
	d.display();

	

	

	
	int go;
	cout << endl << "Press any key to continue";
	cin >> go;
}