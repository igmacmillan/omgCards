#ifndef LINKEDLIST_H
#define LINEDLIST_H

#include "Card.h"
#include "Node.h"

class LinkedList 
{
private:
	Node* head;
	Node* tail;
	int size;

	void insertAtHead(Card* data);
	void insertAtTail(Card* data);

	Card* removeAtHead();
	Card* removeAtTail();

	bool isEmpty();

public:
	LinkedList();
	LinkedList(LinkedList& otherList);
	Card* getHead();
	Card* getTail();
	Card* getAtIndex(int);
	int getSize();
	bool insertAtIndex(Card* data, int index);
	Card* removeAtIndex(int index);
	Card* remove(Card* data);
	bool contains(Card* data);
	int search(Card* data);
	const Card& operator[] (int index);
	friend ostream& operator << (ostream&, LinkedList&);
	LinkedList& operator = (const LinkedList& otherList);
	~LinkedList();

};

#endif