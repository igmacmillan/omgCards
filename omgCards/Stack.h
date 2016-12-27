#ifndef STACK_H
#define STACK_H

#include "Card.h"

#include<iostream>
#include<string>
using namespace std;

class Stack
{
private:
	Card** stack;
	int capacity;
	int size;
public:
	Stack();
	Stack(int c);
	bool push(Card*);
	Card* pop();
	Card* peek();
	int getSize() const;
	int getCapacity() const;

	bool isEmpty();
	bool isFull();


	string toString();
	void display();

	Stack(const Stack& other);
	~Stack();
	Stack& operator = (const Stack& other);
	Card* operator [] (int index);
	friend ostream& operator << (ostream& output, const Stack& s);


};
#endif // !STACK_H


