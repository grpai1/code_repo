//#include "common.h"

#include "Stack.h"

using namespace DataStructure;

void test_expression();

void Stack_test()
{


	Stack s;
	s.pop();
	s.push('A');
	s.push('B');
	s.push('C');
	s.push('D');
	s.push('E');
	s.push('F');
	s.pop();
	s.push('F');
	s.display();

}

int main()
{
	Stack_test();

	//Expression Validation testing
	test_expression();

	return 0;
}
