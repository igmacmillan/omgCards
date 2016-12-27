#include "Card.h"
#include "Stack.h"

# include<iostream>
# include<string>
#include<cstdlib>
using namespace std;

Stack::Stack()
{
	capacity = 52;
	size = 0;
	stack = new Card*[capacity];
}

Stack::Stack(int c)
{
	capacity = c;
	size = 0;
	stack = new Card*[capacity];
}

bool Stack::push(Card* otherCard)
{
	if (!isFull())
	{
		stack[size] = otherCard;
		size++;
		return true;
	}

	return false;
}

Card* Stack::pop()
{
	if (!isEmpty())
	{
		size--;
		return stack[size];
	}
	else
		return NULL;
}

Card* Stack::peek()
{
	if (!isEmpty())
	{
		return stack[size - 1];
	}
	else
		return NULL;
}

bool Stack::isEmpty()
{
	return (size == 0);
}

bool Stack::isFull()
{
	return (size == capacity);
}

void Stack::display()
{
	for (int i = 0; i < size; i++)
	{
		stack[i]->display();
		cout << endl;
	}
}

string Stack::toString()
{

		string temp ="";
		for (int i = 0; i < size; i++)
		{
			temp +=  stack[i]->toString() + " ";
		}
		return temp;
}

int Stack::getSize() const
{
	return size;
}

int Stack::getCapacity() const
{
	return capacity;
}

Stack::Stack(const Stack& other)
	:capacity(other.getCapacity()), size(other.getSize())
{
	stack = new Card*[capacity];
	for (int i = 0; i < size; i++)
	{
		stack[i] = new Card;
		*stack[i] = *other.stack[i];
	}
}

Stack::~Stack()
{
	for (int i = 0; i < size; i++)
	{
		delete stack[i];
	}
	delete[] stack;
}
Stack& Stack::operator = (const Stack& other)
{
	if (this == &other)
		return *this;
	else
	{
		for (int i = 0; i < size; i++)
		{
			delete stack[i];
		}
		delete[] stack;

		capacity = other.capacity;
		size = other.size;

		stack = new Card*[capacity];
		for (int i = 0; i < size; i++)
		{
			stack[i] = new Card;
			*stack[i] = *other.stack[i];
		}
		return *this;
	}
}
Card* Stack::operator [] (int index)
{
	if (index < 0 || index >= size)
		cout << "Invalid index";
	return stack[index];
}

ostream& operator << (ostream& output, const Stack& s)
{
	for (int i = 0; i < s.size; i++)
	{
		s.stack[i]->display();
		output << endl;
	}
	return output;
}