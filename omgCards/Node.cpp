#include "Card.h"
#include "Node.h"

Node::Node() : data(NULL), next(NULL)
{ //intentionally empty
}

Node::Node(Card* otherCard) : data(otherCard)
{
	//intentionally empty
}

Node::Node(Card* otherCard, Node* otherNode)
	: data(otherCard), next(otherNode)
{
	//intentionally empty
}

void Node::setData(Card* otherCard)
{
	data = otherCard;
}

Card* Node::getData()
{
	return data;
}

void Node::setNext(Node* otherNode)
{
	next = otherNode;
}
Node* Node::getNext()
{
	return next;
}
