#include <math.h>

#include "util.h"

using namespace std;

string getSpaces( int numSpaces ) {
	string result = "";
	for( int i = 0; i < numSpaces; i++ )
		result = result.append( " " );
	return result;
}

void printSquare( vector<vector<int> > &square, bool rightJustified = true, string spacing = "" ) {
	int maxLength = 0;
	for( int col = 0; col < square.size( ); col++ )
		for( int row = 0; row < square[col].size( ); row++ )
			if( to_string( square[col][row] ).length( ) > maxLength )
				maxLength = to_string( square[col][row] ).length( );

	if( spacing == "" )
		spacing = getSpaces( ceil( sqrt( 0.51 * maxLength ) ) );
	for( int col = 0; col < square.size( ); col++ ) {
		for( int row = 0; row < square[col].size( ); row++ )
			cout << ( rightJustified ? "" : to_string( square[col][row] ) ) << getSpaces( maxLength - to_string( square[col][row] ).length( ) ) << ( rightJustified ? to_string( square[col][row] ) : "" ) << spacing;
		cout << endl;
	}
}

vector<vector<int> > createGradient( int width = 1, int height = 1, int seed = 1, int step = 1 ) {
	vector<vector<int> > square;

	for( int row = 0; row < height; row++ ) {
		vector<int> newRow;
		for( int col = 0; col < width; col++ )
			newRow.push_back( seed + ( row * step ) + ( col * step ) );
		square.push_back( newRow );
	}
	return square;
}

int main( ) {
	/*

	You have been hired by Preschool Painters to come up with a series of paint-by-number gradients. Of course, you immediately thought of your Data Structures class and figured you could crank out a bunch of these using a 2D vector!

	For this exercise, you will prompt the user for four values:

	grid width
	grid height
	seed value
	step value
	Given these inputs, you should start in the top-left corner with the seed value and then increase by the step as you go right and down. For example, a 5 by 4 grid with a seed of 2 and a step of 4 would look like this:

	2   6   10  14  18
	6   10  14  18  22
	10  14  18  22  26
	14  18  22  26  30
	Your program should be able to take the inputs, produce the gradient, then print it with each cell tab separated. (Remember to add "\t" to your output stream to tab separate.)

	Sample Output:

	Please enter a width: 6
	Please enter a height: 7
	Please enter a seed value: 7
	Please enter a step value: 2
	7   9   11  13  15  17
	9   11  13  15  17  19
	11  13  15  17  19  21
	13  15  17  19  21  23
	15  17  19  21  23  25
	17  19  21  23  25  27

	*/

	int width = readInt( "Please enter a width: " );
	int height = readInt( "Please enter a height: " );

	int seed = readInt( "Please enter a seed value: " );
	int step = readInt( "Please enter a step value: " );

	vector<vector<int> > gradient = createGradient( width, height, seed, step );
	printSquare( gradient );

	return 0;
}