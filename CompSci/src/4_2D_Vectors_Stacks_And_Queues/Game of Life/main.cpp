#include <vector>

#include "util.h"

int BOARD_SIZE = 15;

void printBoard( vector<vector<char> > &square ) {
	for( int col = 0; col < square.size( ); col++ ) {
		for( int row = 0; row < square[col].size( ); row++ )
			cout << square[col][row] << " ";
		cout << endl;
	}
}

vector<vector<char> > createRandBoard( int numActive ) {
	vector<vector<char> > board;
	for( int row = 0; row < BOARD_SIZE; row++ ) {
		vector<char> curRow;
		for( int col = 0; col < BOARD_SIZE; col++ )
			curRow.push_back( 'O' );
		board.push_back( curRow );
	}

	while( numActive > 0 ) {
		int rand = randInt( 1, BOARD_SIZE * BOARD_SIZE ) - 1;
		if( board[rand / BOARD_SIZE][rand % BOARD_SIZE] != 'X' ) {
			board[rand / BOARD_SIZE][rand % BOARD_SIZE] = 'X';
			numActive--;
		}
	}

	return board;
}

/**
 * @brief Get the Surrounding characters of the point given
 *
 * @return an array of the numbers of X's and O's neighboring this position respectively
 */
vector<int> getNeighboringChars( vector<vector<char> > board, int row, int col ) {
	vector<int> neighboringNums{ 0, 0 };

	for( int curRow = max( 0, row - 1 ); curRow < min( row + 2, BOARD_SIZE ); curRow++ ) {
		for( int curCol = max( 0, col - 1 ); curCol < min( col + 2, BOARD_SIZE ); curCol++ ) {
			if( curRow == row && curCol == col )
				continue;
			if( board[curRow][curCol] == 'X' )
				neighboringNums[0]++;
			else
				neighboringNums[1]++;
		}
	}

	// cout << "(" << row << ", " << col << "): " << touchingNums[0] << ", " << touchingNums[1] << endl;
	return neighboringNums;
}

void updateBoard( vector<vector<char> > &board, vector<vector<char> > oldBoard ) {
	for( int row = 0; row < oldBoard.size( ); row++ ) {
		for( int col = 0; col < oldBoard.size( ); col++ ) {
			vector<int> numNeighboringChars = getNeighboringChars( oldBoard, row, col );
			if( oldBoard[row][col] == 'X' && ( numNeighboringChars[0] != 2 && numNeighboringChars[0] != 3 ) )
				board[row][col] = 'O';
			else if( oldBoard[row][col] == 'O' && numNeighboringChars[1] == 3 )
				board[row][col] = 'X';
		}
	}
}

int main( ) {
	/*

		The game is played on a square board. (We will use a default value of 15 by 15, but you can update this.) Each position on the board represents either a living cell (X) or a dead cell (O).

		The initial board will have some living and some dead cells. In each round, the status of each cell gets updated based on the following rules:

		If the cell is alive:
		It stays alive if 2 or 3 of its neighbors are also alive
		Otherwise it dies

		If the cell is dead:
		It becomes alive if exactly 3 of its neighbors are alive
		Otherwise it remains dead
		A neighbor is considered any cell touching the current cell horizontally, vertically, or diagonally. A cell in the middle will have 8 neighbors. Cells on the edges and corners will have fewer.

		Part 2 - Adding the Simulator
		In this part, you will add the simulator. This should execute with a function and print the board after each round. Before moving on to the next round, give the user an option to continue or exit.

		A couple of hints:

		When counting the number of neighbors, be sure to think about the edge cases and don’t count the current cell you are on
		The new status of each cell is dependent on the state of the board at the beginning of each turn, not the status as it updates throughout the turn. You will need a snapshot of that starting state to do your comparisons.

	*/

	int rand = readInt( 1, BOARD_SIZE * BOARD_SIZE, "Please enter number of active cells between 1 and " + to_string( BOARD_SIZE * BOARD_SIZE ) + ": " );

	vector<vector<char> > board = createRandBoard( rand );

	while( true ) {
		printBoard( board );

		if( readLine( "Press Enter to continue (exit to quit) " ) == "exit" )
			break;

		updateBoard( board, board );
	}

	return 0;
}