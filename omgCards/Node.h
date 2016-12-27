
#ifndef NODE_H
#define NODE_H

#include "Card.h"

class Node
{
private:
	Card* data;
	Node* next;
public:
	Node();
	Node(Card*);
	Node(Card*, Node*);
	void setData(Card*);
	Card* getData();
	void setNext(Node*);
	Node* getNext();
};


#endif // !NODE_H
