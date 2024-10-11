#include <iostream>

/**
 * @brief recursively prints "Call: Head" n times then backtracks printing "Backtrack: [1,n]"
 *
 * @param n an integer greater than or equal to 0
 */
void head(int n) {
	std::cout << "Call: Head" << std::endl;

	if( n == 0 )
		return;
	else
		head(n - 1);

	std::cout << "Backtrack: " << n << std::endl;
}

/**
 * @brief recursively prints "Call: Tail [n, 1]" then prints "Call: Tail "
 *
 * @param n an integer greater than or equal to 0
 */
void tail(int n) {
	std::cout << "Call: Tail ";

	if( n == 0 )
		return;
	else
		std::cout << n << std::endl;

	tail(n - 1);
}

/**
 * @brief prints "Call: Head" n times then backtracks printing "Backtrack: [1,n]"
 *
 * @param n an integer greater than or equal to 0
 */
void headLoop(int n) {
	for( int i = -1; i < n; ++i )
		std::cout << "Call: Head" << std::endl;
	for( int i = 1; i <= n; ++i )
		std::cout << "Backtrack: " << i << std::endl;
}

/**
 * @brief prints "Call: Tail [n, 1]" then prints "Call: Tail "
 *
 * @param n an integer greater than or equal to 0
 */
void tailLoop(int n) {
	for( int i = n; i > 0; --i )
		std::cout << "Call: Tail " << i << std::endl;
	std::cout << "Call: Tail ";
}

int main( ) {
	int n = 3;

	head(n);
	std::cout << "------" << std::endl;
	headLoop(n);

	std::cout << std::endl
						<< std::endl;

	tail(n);
	std::cout << std::endl
						<< "------" << std::endl;
	tailLoop(n);

	return 0;
}