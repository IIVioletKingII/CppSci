#include <stack>
#include <vector>

#include "util.h"

int main( ) {
	/*

	> 6
	> 5
	> 4
	> +
	9
	> *
	54
	> +
	Error - Not enough numbers in stack
	> 2
	> 3
	> 1
	> +
	4
	> *
	8
	> +
	62
	> exit

	*/

	stack<double> inputs;

	while( true ) {
		string input = readLine( "> " );
		if( input == "exit" )
			break;

		if( input == "+" || input == "-" || input == "*" || input == "/" ) {
			if( inputs.size( ) < 2 )
				cout << "Error - Not enough numbers in stack" << endl;
			else {
				double num2 = inputs.top( );
				inputs.pop( );
				double num1 = inputs.top( );
				inputs.pop( );

				if( input == "+" )
					num1 += num2;
				else if( input == "-" )
					num1 -= num2;
				else if( input == "*" )
					num1 *= num2;
				else
					num1 /= num2;

				cout << num1 << endl;
				inputs.push( num1 );
			}
		} else
			inputs.push( stod( input ) );
	}

	return 0;
}