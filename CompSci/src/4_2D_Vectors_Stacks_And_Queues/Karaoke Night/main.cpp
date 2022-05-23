#include <fstream>
#include <queue>
#include <vector>

#include "util.h"

struct kareoke {
	string singer;
	int song;
};

int main( ) {
	// Enter your code here

	/*

	Would you like to:
	1. Add a song
	2. Get the next song in the queue
	3. Exit
	> 1
	Please enter the song number(enter to list songs)
	1 - Thriller by Michael Jackson  5:57
	2 - Roar by Katy Perry  3:42
	3 - Don't Stop Believin' by Journey  4:11
	4 - Thunder by  Imagine Dragons  3:24
	5 - Blinding Lights by Weeknd  3:22
	6 - Livin On A Prayer by Bon Jovi  4:24
	7 - Positions by Ariana Grande  2:52
	8 - Ghostbusters by Ray Parker Jr.  4:06
	Please enter the song number(enter to list songs) 3
	Please enter the name of the performer: Kyle
	Would you like to:
	1. Add a song
	2. Get the next song in the queue
	3. Exit
	> 1
	Please enter the song number(enter to list songs) 6
	Please enter the name of the performer: Mimi
	Would you like to:
	1. Add a song
	2. Get the next song in the queue
	3. Exit
	> 2
	Next up: Kyle will be singing Don't Stop Believin' by Journey.
	Would you like to:
	1. Add a song
	2. Get the next song in the queue
	3. Exit
	> 2
	Next up: Mimi will be singing Livin On A Prayer by Bon Jovi.
	Would you like to:
	1. Add a song
	2. Get the next song in the queue
	3. Exit
	> 2
	There are no singers in the queue.
	Would you like to:
	1. Add a song
	2. Get the next song in the queue
	3. Exit
	> 3

	*/

	vector<string> songNames = { "Thriller", "Roar", "Don't Stop Believin'", "Thunder", "Blinding Lights", "Livin On A Prayer", "Positions", "Ghostbusters" };
	vector<string> songAuthors = { "Michael Jackson", "Katy Perry", "Journey", "Imagine Dragons", "Weeknd", "Bon Jovi", "Ariana Grande", "Ray Parker Jr." };
	vector<string> songLengths = { "5:57", "3:42", "4:11", "3:24", "3:22", "4:24", "2:52", "4:06" };

	queue<kareoke> queue;

	while( true ) {
		int input = readInt( 1, 3, "Would you like to:\n1. Add a song\n2. Get the next song in the queue\n3. Exit\n> " );

		if( input == 1 ) { // add a song
			string inputSong = readLine( "Please enter the song number (enter to list songs) " );
			if( inputSong == "" )
				for( int i = 0; i < songNames.size( ); i++ )
					cout << i + 1 << " - " << songNames[i] << " by " << songAuthors[i] << "  " << songLengths[i] << endl;
			else
				queue.push( kareoke{ readLine( "Please enter the name of the performer: " ), stoi( inputSong ) - 1 } );
		} else if( input == 2 ) { // get next song in queue
			if( queue.size( ) > 0 ) {
				kareoke next = queue.front( );
				cout << "Next up: " << next.singer << " will be singing " << songNames[next.song] << " by " << songAuthors[next.song] << "." << endl;
			} else
				cout << "Nothing in queue. The audience is quite boring." << endl;

		} else
			break;
	}

	return 0;
}