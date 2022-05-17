#include <stack>

#include "util.h"

int main( ) {
	// Enter your code here

	stack<string> history;

	stack<string> backwardsHistory;

	int input = 0;

	while( input != 4 ) {
		input = readInt( 1, 4, "Would you like to: \n1 - Go to a new site\n2 - Go Back\n3 - Go Forward\n4 - Exit\n>> 1" );
		if( input == 1 ) {
			history.push( readLine( "Enter the new site to browse: " ) );
			cout << "You are currently browsing " << history.top( ) << endl;
		} else if( input == 2 ) { // go back
			if( history.size( ) == 0 )
				cout << "You do not have any history" << endl;
			else {
				backwardsHistory.push( history.top( ) );
				cout << "You are currently browsing " << history.top( ) << endl;
				history.pop( );
			}
		} else if( input == 3 ) {
			if( backwardsHistory.size( ) == 0 )
				cout << "You do not have any history" << endl;
			else {
				history.push( backwardsHistory.top( ) );
				cout << "You are currently browsing " << backwardsHistory.top( ) << endl;
				backwardsHistory.pop( );
			}
		}
	}

	return 0;
}