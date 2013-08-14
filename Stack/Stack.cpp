/* Stack Data Structure Implementation */

//TODO - To make it generic using templates

#include "../common.h"
#include "Stack.h"

namespace DataStructure
{

Stack::Stack():MAX(25),top(-1)
{

}

Stack::Stack(int max):MAX(max),top(-1)
{

}


void Stack::push(char _chr)
{
	if(top == (MAX -1 ))
	{
		cout << "Stack is full" << endl;
	}
	else
	{
		chr.push_back(_chr);
		top++;
	}
}

void Stack::pop()
{

	if(top == -1)
	{
		cout << "Stack is empty" << endl;
	}
	else
	{
		chr.pop_back();
		top--;
	}
}

char Stack::pop_char()
{

	char temp='\0';
	if(top == -1)
	{ 
		cout << "Stack is empty" << endl;
		 
	}
	else
	{
		temp = chr[top];
		chr.pop_back();
		top--;
	}
	return temp;

}


void Stack::display()

{
	for (int i=0 ; i<= top ; i++)
	{
		cout << chr[i] <<endl;

	}

}



int Stack::size()

{
	return top;

}

}//namespace
