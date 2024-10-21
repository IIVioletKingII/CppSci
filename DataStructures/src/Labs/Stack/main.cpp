#include <iostream>
#include "Stack.h"

int main( ) {
	Stack<int> myStack;

	for( int i = 10; i <= 50; i += 10 )
		myStack.push(i);

	std::cout << myStack.peek( ) << std::endl;

	myStack.print( );

	// for( int i = 0; i < 5; ++i ) {
	// 	std::cout << myStack.pop( ) << std::endl;
	// 	myStack.print( );
	// }


	myStack.~Stack( );

	std::cout << "Deleted" << std::endl;

	myStack.print( );

	return 0;
}