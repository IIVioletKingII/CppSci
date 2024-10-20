#include <iostream>
#include "Stack.h"

int main( ) {
	Stack<int> myStack;

	myStack.push(100);
	std::cout << myStack.peek( ) << std::endl;

	return 0;
}