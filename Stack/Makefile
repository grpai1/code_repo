CPP=g++

main.o:	main_stack_test.cpp expression_stack_program.o libStack.so
	g++ -L/home/grpai1/code_repo/Stack main_stack_test.cpp expression_stack_program.o -o main.o -lStack
	export LD_LIBRARY_PATH=/home/grpai1/code_repo/Stack${LD_LIBRARY_PATH:+:$LD_LIBRARY_PATH}

expression_stack_program.o:	expression_stack_program.cpp
	g++ -c expression_stack_program.cpp -o expression_stack_program.o

libStack.so:	Stack.o
	$(CPP) -shared -o libStack.so Stack.o
Stack.o:	Stack.cpp Stack.h
	$(CPP) -c -fPIC Stack.cpp -o Stack.o

clean:
	rm -f *.o
	rm -f *.so
