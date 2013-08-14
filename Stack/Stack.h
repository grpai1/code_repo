#ifndef _STACK_H
#define _STACK_H

#include "../common.h"
#include <vector>

namespace DataStructure
{

class Stack
{

	vector<char> chr;
	int top;

	const int MAX;
public:

	//ctor's
	Stack();
	Stack(int max);

	//Stack Operations
	void push(char _chr);
	void pop();

	//Pop operation to pop put char
	char pop_char();
	int size();	

	//Display the contents of the Stack
	void display();

};

}//namespace
#endif
