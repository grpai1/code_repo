#include "Stack.h"

using namespace DataStructure;

void expression_validator(char *str);

void test_expression()
{
	char *str ="(A+B)+(C+D)";
	expression_validator(str);

	char *str1 ="((A+B)+(C+D)";
	expression_validator(str1);

	char *str2 ="((A+B)+[C+D])";
	expression_validator(str2);

	char *str3 ="((A+B)+[C+D]}";
	expression_validator(str3);

}


void expression_validator(char *str)
{

	Stack s1;
	
	for(;*str != '\0';str++)
	{
		if ( (*str == '(') ||  (*str == '[') || (*str == '{'))
		{
			s1.push(*str);
			continue;
		}	

		if( (*str == ')') || (*str == '}') || (*str == ']'))
		{
			char temp = s1.pop_char();

			if( (( temp == '(') && (*str ==')')) ||
				(( temp == '{') && (*str =='}')) ||
				(( temp == '[') && (*str ==']')) )
				continue;
			else
				break;

		}		
		//str++;
	}	


	if((*str == '\0') && (s1.size() == -1))
		std::cout << "Expression good" << endl;
	else
		std::cout << "Expression braces Problem" << endl;

}
