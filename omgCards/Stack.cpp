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
		stack[i]->Card::display();
		cout << endl;
	}
}

string Stack::toString()
{

		string temp ="";
		for (int i = 0; i < size; i++)
		{
			temp +=  stack[i]->toString();
		}
		return temp;
	
}