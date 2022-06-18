#include "util.h"

using namespace std;

void inputBoard( vector<vector<int> >& board, int height = 9, int width = 9 ) {
	for( int h = 0; h < height; h++ ) {
		for( int w = 0; w < width; w++ ) { // goes through row first
			cin >> board[h][w];
			if( board[h][w] < 0 || board[h][w] > 9 ) {
				cout << "Invalid Entry. Restart" << endl;
				inputBoard( board );
				return;
			}
		}
	}
}

void printBoard( vector<vector<int> >& board ) {
	for( int h = 0; h < board.size( ); h++ ) {
		for( int w = 0; w < board[0].size( ); w++ )
			cout << ( ( board[h][w] == 0 ) ? " " : to_string( board[h][w] ) ) << ( ( w % 3 == 2 && w != 8 ) ? " | " : " " );
		cout << endl
				 << ( ( h % 3 == 2 && h != 8 ) ? "----------------------\n" : "" );
	}
}

bool rowContains( vector<vector<int> >& board, int row, int a ) {
	for( int w = 0; w < board[0].size( ); w++ ) // row position
		if( board[row][w] == a )
			return true;
	return false;
}

bool colContains( vector<vector<int> >& board, int column, int a ) {
	for( int h = 0; h < board.size( ); h++ ) // column
		if( board[h][column] == a )
			return true;
	return false;
}

pair<int, int> boardToNonetPos( pair<int, int> boardPos ) {
	return pair<int, int>{ boardPos.first / 3, boardPos.second / 3 };
}

pair<int, int> boardToNonetPos( int first, int second ) {
	return pair<int, int>{ first / 3, second / 3 };
}

bool nonetContains( vector<vector<int> >& board, pair<int, int> pos, int a ) {
	for( int h = pos.second * 3; h < pos.second * 3 + 3; h++ )
		for( int w = pos.first * 3; w < pos.first * 3 + 3; w++ )
			if( board[h][w] == a )
				return true;
	return false;
}

bool numberValid( vector<vector<int> >& board, pair<int, int> pos, int a ) {
	return !rowContains( board, pos.second, a ) && !colContains( board, pos.first, a ) && !nonetContains( board, boardToNonetPos( pos ), a );
}

void findSolution( vector<vector<int> >& ogBoard, vector<vector<int> > board, pair<int, int> pos ) {
	if( ogBoard[pos.second][pos.first] == 0 ) {
		for( int i = 1; i <= 9; i++ ) {
			if( numberValid( board, pos, i ) ) {
				board[pos.second][pos.first] = i;
				if( pos.first == 8 && pos.second == 8 ) {
					ogBoard = board;
					return;
				}
				findSolution( ogBoard, board, ( ( pos.first < 8 ) ? pair<int, int>{ pos.first + 1, pos.second } : pair<int, int>{ 0, pos.second + 1 } ) );
			}
		}
		if( board[pos.second][pos.first] == 0 )
			return;
	}

	findSolution( ogBoard, board, ( ( pos.first < 8 ) ? pair<int, int>{ pos.first + 1, pos.second } : pair<int, int>{ 0, pos.second + 1 } ) );
}

int main( ) {
	// Enter your code here

	/*

killer
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
1 9 0 0 0 0 0 0 4
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 9 0

normal
9 0 6 0 1 0 0 7 0
0 0 0 7 0 3 9 0 6
5 0 7 0 9 0 0 8 0
3 8 1 0 0 0 0 0 0
0 6 0 0 0 1 8 9 0
0 5 9 0 2 0 1 6 0
0 0 5 0 0 0 0 3 8
0 0 0 1 8 0 0 0 0
0 0 0 0 7 4 6 0 0

	*/

	// vector<vector<int> > board( 9, vector<int>( 9 ) );

	// inputBoard( board );

	vector<vector<int> > board{
			{ 9, 0, 6, 0, 1, 0, 0, 7, 0 },
			{ 0, 0, 0, 7, 0, 3, 9, 0, 6 },
			{ 5, 0, 7, 0, 9, 0, 0, 8, 0 },
			{ 3, 8, 1, 0, 0, 0, 0, 0, 0 },
			{ 0, 6, 0, 0, 0, 1, 8, 9, 0 },
			{ 0, 5, 9, 0, 2, 0, 1, 6, 0 },
			{ 0, 0, 5, 0, 0, 0, 0, 3, 8 },
			{ 0, 0, 0, 1, 8, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 7, 4, 6, 0, 0 } };

	findSolution( board, board, pair<int, int>{ 0, 0 } );

	cout << endl;
	printBoard( board );

	return 0;
}