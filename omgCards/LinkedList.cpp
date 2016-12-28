
#include "LinkedList.h"
#include "Deck.h"
#include "Card.h"
#include "Stack.h"

Card* LinkedList::getHead()
{
	return head->getData();
}

Card* LinkedList::getTail()
{
	return tail->getData();
}

bool LinkedList::isEmpty()
{
	if (0 == size)
		return true;
	else
		return false;
}

LinkedList::LinkedList()
	:size(0)
{
	head = NULL;
	tail = NULL;
}

LinkedList::LinkedList(LinkedList& otherList)
	:size(otherList.size)
{
	head = new Node(*otherList.head);
	tail = new Node(*otherList.tail);
	//head = new Node(new Card(*otherList.head->getData()), new Node(*otherList.head->getNext()));
	//tail = new Node(new Card(*otherList.tail->getData()), new Node(*otherList.tail->getNext()));
	Node* trav = head;
	Node* travOther = otherList.head;
	for (int i = 0; i < size - 1; i++)
	{
		travOther = travOther->getNext();
		//trav->setNext(new Node(new Card(*travOther->getData()), new Node(*travOther->getNext())));
		trav->setNext(new Node(*travOther));
		trav = trav->getNext();
	}
}

LinkedList& LinkedList::operator = (const LinkedList& otherList)
{
	if (this == &otherList)
		return *this;
	else
	{
		Node* trav = head;
		for (int i = 0; i < size; i++)
		{
			Node* temp = trav->getNext();
			delete trav;
			trav = temp;
		}
		size = otherList.size;
		head = new Node(*otherList.head);
		tail = new Node(*otherList.tail);
		trav = head;
		Node* travOther = otherList.head;
		for (int i = 0; i < size - 1; i++)
		{
			travOther = travOther->getNext();
			trav->setNext(new Node(*travOther));
			trav = trav->getNext();
		}

	}
}

LinkedList::~LinkedList()
{
	Node* trav = head;
	for (int i = 0; i < size; i++)
	{
		Node* temp = trav->getNext();
		delete trav;
		trav = temp;
	}
}

Card* LinkedList::getAtIndex(int index)
{
	if (index < 0 || index > size)
	{
		cerr << "Invalid Index: " << index << endl;
		return false;
	}
	if (index == 0)
		return getHead();
	else if (index == size)
		return getTail();
	else
	{
		Node* trav = head;

		for (int i = 0; i < index; i++)
		{
			trav = trav->getNext();
		}
		return trav->getData();
	}
}

int LinkedList::getSize()
{
	return size;
}

bool LinkedList::insertAtIndex(Card* data, int index)
{
	if (index < 0 || index > size)
	{
		cerr << "Invalid Index: " << index << endl;
		return false;
	}

	if (index == 0)
		insertAtHead(data);
	else if (index == size)
		insertAtTail(data);
	else
	{
		Node* trav = head;

		for (int i = 0; i < index - 1; i++)
		{
			trav = trav->getNext();
		}
		trav->setNext(new Node(data, trav->getNext()));
		size++;
	}
}

Card* LinkedList::removeAtIndex(int index)
{
	if (index < 0 || index > size)
	{
		cerr << "Invalid Index: " << index << endl;
	}

	if (index == 0)
		removeAtHead();
	else if (index == size - 1)
		removeAtTail();
	else
	{
		Node* trav = head, *trav2 = head;

		for (int i = 0; i < index; i++)
		{
			trav = trav->getNext();
		}
		Card* temp = trav->getData();
		for (int i = 0; i < index - 1; i++)
		{
			trav2 = trav2->getNext();
		}
		trav2->setNext(trav->getNext());
		size--;
		return temp;
	}
}

bool LinkedList::contains(Card* data)
{
	if (!data->compareTo(*(head->getData())))
		return true;
	else if (!data->compareTo(*(tail->getData())))
		return true;
	else
	{
		Node* trav = head;
		for (int i = 0; i < size; i++)
		{

			if (!data->compareTo(*(trav->getData())))
				return true;
			trav = trav->getNext();
		}
	}
	return false;
}

int LinkedList::search(Card* data)
{
	if (!data->compareTo(*(head->getData())))
		return 0;
	else if (!data->compareTo(*(tail->getData())))
		return size - 1;
	else
	{
		Node* trav = head;
		for (int i = 0; i < size; i++)
		{

			if (!data->compareTo(*(trav->getData())))
				return i;
			trav = trav->getNext();
		}
	}
}

const Card& LinkedList::operator[] (int index)
{
	if (isEmpty())
	{
		cout << "List is empty";
		exit(1);
	}
	else if (index < 0 || index >= size)
	{
		cout << "Invalid index";
		exit(1);
	}
	else if (0 == index)
		return *(head->getData());
	else if (size - 1 == index)
		return *(tail->getData());
	else
	{
		Node* trav = head;

		for (int i = 0; i < index; i++)
		{
			trav = trav->getNext();
		}
		return *(trav->getData());
	}

}
ostream& operator << (ostream& output, const LinkedList& list)
{
	Node* trav = list.head;
	for (int i = 0; i < list.size; i++)
	{
		trav->getData()->display();
		cout << endl;
		trav = trav->getNext();
	}
	return output;
}

//private
void LinkedList::insertAtHead(Card* data)
{
	if (isEmpty())
	{
		head = new Node(data);
		tail = head;
	}
	else
	{
		head = new Node(data, head);
	}
	
	size++;
}
void LinkedList::insertAtTail(Card* data)
{
	if (isEmpty())
	{
		insertAtHead(data);
	}

	else
	{
		tail->setNext(new Node(data));
		tail = tail->getNext();
		size++;
	}
}

Card* LinkedList::removeAtHead()
{
	Card* temp = head->getData();
	head = head->getNext();
	size--;
	return temp;
}

Card* LinkedList::removeAtTail()
{
	Card* temp = tail->getData();
	Node* trav = head;
	for (int i = 0; i < size - 1; i++)
	{
		trav = trav->getNext();
	}
	//delete tail;
	tail = trav;
	size--;
	return temp;
}

Card* LinkedList::remove(Card* data)
{
	Card* temp = NULL;
	if (!data->compareTo(*(head->getData())))
		temp = removeAtHead();
	else if (!data->compareTo(*(tail->getData())))
		temp = removeAtTail();
	else
	{
		Node* trav = head;
		for (int i = 0; i < size; i++)
		{

			if (!data->compareTo(*(trav->getData())))
			{
				temp = removeAtIndex(i);
				
			}
			trav = trav->getNext();
		}
	}
	if (temp != NULL)
		return temp;
	else
	{
		cerr << "The card is not in the deck.\n";
		return NULL;
	}
}

