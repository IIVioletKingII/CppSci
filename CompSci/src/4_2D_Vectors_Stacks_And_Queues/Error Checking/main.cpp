#include <fstream>
#include <stack>

#include "util.h"

int main( ) {
	ifstream inputFile;
	inputFile.open( readLine( "Please enter a file to check: " ) );

	stack<char> paranthesis;
	int lineNum = 0;

	while( true ) {
		lineNum++;
		string line;
		getline( inputFile, line );

		if( inputFile.fail( ) )
			break;

		for( int i = 0; i < line.length( ); i++ ) {
			if( line.at( i ) == '(' || line.at( i ) == '[' || line.at( i ) == '{' )
				paranthesis.push( line.at( i ) );
			if( line.at( i ) == ')' && paranthesis.top( ) == '(' )
				paranthesis.pop( );
			else if( line.at( i ) == ']' && paranthesis.top( ) == '[' )
				paranthesis.pop( );
			else if( line.at( i ) == '}' && paranthesis.top( ) == '{' )
				paranthesis.pop( );
			else if( line.at( i ) == ')' || line.at( i ) == ']' || line.at( i ) == '}' )
				throw logic_error( "Error: Line: " + to_string( lineNum ) + " Expecting " + paranthesis.top( ) + " but found " + line.at( i ) );
		}
	}
	inputFile.close( );

	if( paranthesis.size( ) == 0 )
		cout << "Your code looks good!";

	return 0;
}