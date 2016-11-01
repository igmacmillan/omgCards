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

	bool isEmpty();
	bool isFull();


	string toString();
	void display();

};
#endif // !STACK_H


