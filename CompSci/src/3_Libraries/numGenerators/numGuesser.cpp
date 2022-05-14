#include "util.h"

using namespace std;

int main( ) {
	// Enter your code here

	int randomNum = randInt( 1, 100 );

	int guess = 0;

	while( guess != randomNum ) {
		guess = readInt( 1, 100, "Guess a number between 1 and 100: ", "That is not between 1 and 100! Guess again: " );
		string out = guess == randomNum ? "Congratulation! You guessed the number!" : ( guess < randomNum ? "Higher!" : "Lower!" );

		cout << "out" << endl;
	}

	return 0;
}