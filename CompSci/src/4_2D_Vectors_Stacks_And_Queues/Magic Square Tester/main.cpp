#include <fstream>

#include "util.h"

// Return the sum of the values in the given row
int sumRow( vector<vector<int> > &square, int row ) {
	int sum = 0;
	for( int col = 0; col < square.size( ); col++ )
		sum += square[col][row];
	return sum;
}

// Return the sum of the values in the given column
int sumCol( vector<vector<int> > &square, int col ) {
	int sum = 0;
	for( int row = 0; row < square[col].size( ); row++ )
		sum += square[col][row];
	return sum;
}

// Return the sum of the values in the main diagonal
int sumMainDiag( vector<vector<int> > &square ) {
	int sum = 0;
	for( int col = 0, row = 0; col < square.size( ) && row < square[col].size( ); col++ )
		sum += square[col][row++];
	return sum;
}

// Return the sum of the values in the other ("reverse") diagonal
int sumOtherDiag( vector<vector<int> > &square ) {
	int sum = 0;
	for( int col = 0, row = square[col].size( ) - 1; col < square.size( ) && row >= 0; col++ )
		sum += square[col][row--];
	return sum;
}

// Return true if the square is magic (all rows, cols, and diags have
// same sum), false otherwise
bool magic( vector<vector<int> > &square ) {
	int magicVal = sumRow( square, 0 );
	for( int col = 1; col < square.size( ); col++ )
		if( sumRow( square, col ) != magicVal )
			return false;
	for( int row = 1; row < square[0].size( ); row++ )
		if( sumCol( square, row ) != magicVal )
			return false;
	if( sumMainDiag( square ) != magicVal || sumOtherDiag( square ) != magicVal )
		return false;
	return true;
}

string getSpaces( int numSpaces ) {
	string result = "";
	for( int i = 0; i < numSpaces; i++ )
		result = result.append( " " );
	return result;
}

// Print the contents of the square, neatly formatted
void printSquare( vector<vector<int> > &square ) {
	int maxLength = 0;
	for( int col = 0; col < square.size( ); col++ )
		for( int row = 0; row < square[col].size( ); row++ )
			if( to_string( square[col][row] ).length( ) > maxLength )
				maxLength = to_string( square[col][row] ).length( );

	for( int col = 0; col < square.size( ); col++ ) {
		for( int row = 0; row < square[col].size( ); row++ )
			cout << getSpaces( maxLength - to_string( square[col][row] ).length( ) ) << square[col][row] << getSpaces( maxLength );
		cout << endl;
	}
}

int main( ) {
	ifstream in;
	in.open( "magic_data.txt" );
	if( in.fail( ) )
		Error( "File didn't open - check the name" );

	int count = 1; // count which square we're on

	string line;
	getline( in, line );
	int size = stoi( line ); // size of next square

	// Expecting -1 at bottom of input file
	while( size != -1 ) {
		// create a new square and read in the data
		vector<vector<int> > square;
		for( int i = 0; i < size; i++ ) {
			vector<int> row;
			getline( in, line );
			vector<string> input = splitLine( line );
			for( int j = 0; j < input.size( ); j++ )
				row.push_back( stoi( input[j] ) );

			square.push_back( row );
		}
		// Print out
		cout << "******** Square " << count << " ********" << endl;
		printSquare( square );

		// Display results
		if( magic( square ) )
			cout << "The Square is magic! Everything sums to " << sumRow( square, 0 ) << "." << endl;
		else
			cout << "The Square is not a magic square." << endl;

		getline( in, line );
		size = stoi( line ); // size of next square
		count++;
	}
	return 0;
}