#include <iostream>

/**
 * @brief prints "Call: Head" n times then backtracks printing "Backtrack: [1,n]"
 *
 * @param n an integer greater than or equal to 0
 */
void head(int n) {
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
void tail(int n) {
	for( int i = n; i > 0; --i )
		std::cout << "Call: Tail " << i << std::endl;
	std::cout << "Call: Tail ";
}