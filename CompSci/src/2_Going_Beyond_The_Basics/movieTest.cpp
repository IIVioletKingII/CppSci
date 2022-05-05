#include <math.h>

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

struct movie {
	string title, actor;
	int year;
	double rating;
};

vector<string> splitLn( string input, char delimeter ) {
	vector<string> output;
	istringstream stream( input );
	string token;

	while( getline( stream, token, delimeter ) )
		output.push_back( token );
	return output;
}

void inputMoviesFromFile( vector<movie> &movieList ) {
	ifstream inputFile;
	inputFile.open( "movies.txt" );

	while( true ) {
		string line;
		getline( inputFile, line );

		if( inputFile.fail( ) )
			break;

		// title; year; actor; rating
		movie inputMovie;

		vector<string> inputs = splitLn( line, ';' );

		inputMovie.title = inputs[0];
		inputMovie.year = stoi( inputs[1] );
		inputMovie.actor = inputs[2];
		inputMovie.rating = stod( inputs[3] );

		movieList.push_back( inputMovie );
	}
	inputFile.close( );
}

void printMovie( movie movie, bool includeEndLine = true ) {
	cout << "Title: " << movie.title << endl;
	cout << "Year: " << movie.year << endl;
	cout << "Actor: " << movie.actor << endl;
	cout << "Rating: " << movie.rating << endl;
	if( includeEndLine )
		cout << endl;
}

void printMovie( movie movie, int &loops, bool includeEndLine = true ) {
	printMovie( movie, includeEndLine );
	loops++;
}

void inputMovieFromUserInput( vector<movie> &movieList ) {
	movie inputMovie;

	string inYear, inRating;

	cin.ignore( );

	cout << "Please enter the title: ";
	getline( cin, inputMovie.title );

	cout << "Please enter an actor (Last, First): ";
	getline( cin, inputMovie.actor );

	cout << "Please enter the year: ";
	cin >> inputMovie.year;

	cout << "Please enter the rating (1-10): ";
	cin >> inputMovie.rating;
	while( inputMovie.rating < 1 || inputMovie.rating > 10 ) {
		cout << "Please enter a valid rating between 1 and 10: ";
		cin >> inputMovie.rating;
	}

	movieList.push_back( inputMovie );
}

int getValidIntInput( string inputMessage = "Please enter an int.", int min = INT_MIN, int max = INT_MAX, string errorMessage = "Not a valid number. Please try again." ) {
	string searchInput;
	// cin.ignore( );
	bool validInput = false;
	int searchIntput;
	while( !validInput ) {
		cout << inputMessage;
		getline( cin, searchInput );

		try {
			searchIntput = stoi( searchInput );
			validInput = true;
			if( searchIntput < min || searchIntput > max )
				throw logic_error( "Please pick a number between " + to_string( min ) + " and " + to_string( max ) + "." );
		} catch( invalid_argument ) {
			cout << errorMessage << endl;
			validInput = false;
		} catch( exception const &e ) {
			cout << e.what( ) << endl;
			validInput = false;
		}
	}
	return searchIntput;
}

int getValidDoubleInput( string inputMessage = "Please enter a number.", double min = -INFINITY, double max = INFINITY, string errorMessage = "Not a valid number. Please try again." ) {
	string searchInput;
	// cin.ignore( );
	bool validInput = false;
	double searchNumput;
	while( !validInput ) {
		cout << inputMessage;
		getline( cin, searchInput );

		try {
			searchNumput = stoi( searchInput );
			validInput = true;
			if( searchNumput < min || searchNumput > max )
				throw logic_error( "Please pick a number between " + to_string( min ) + " and " + to_string( max ) + "." );
		} catch( invalid_argument ) {
			cout << errorMessage << endl;
			validInput = false;
		} catch( exception const &e ) {
			cout << e.what( ) << endl;
			validInput = false;
		}
	}
	return searchNumput;
}

int main( ) {
	// Enter Your Code Here

	/*
		For this final part of our Movie Database in this unit, we are going to add a search feature to the menu.

		Once the user selects to search, you should call the search function that prompts the user for a field to search. If they search for an Actor or Title, then prompt them for a string to search for. If they choose to search for a year or rating, prompt them for a range (i.e. starting and ending year or min and max rating).

		Your search menu should take a numeric option and you should catch any invalid characters and separately catch any value that is not in the range. (See sample output). As a challenge, see if you can also catch invalid entries for the year and rating search.

		Once you have a valid search criteria, use the list function you created earlier to print out the results.

		Sample Output:

		Would you like to (s)earch, (l)ist movies or (e)xit? s
		Search menu:
		1. Search by Title
		2. Search by Year
		3. Search by Actor
		4. Search by Rating
		Enter option: title
		Not a valid number. Please try again.
		Enter option: 0
		Please enter a number between 1 and 4.
		Enter option: 1
		Please enter a title to search for: star
		Title: Secrets of Superstar Fitness
		Year: 2002
		Actor: Schwarzenegger, Arnold
		Rating: 5.3

		Total Count: 1
		Would you like to (s)earch, (l)ist movies or (e)xit? s
		Search menu:
		1. Search by Title
		2. Search by Year
		3. Search by Actor
		4. Search by Rating
		Enter option: y
		Not a valid number. Please try again.
		Enter option: 2
		Please enter the starting year to search: 2010
		Please enter the ending year to search: 2012
		Title: MSN Exclusives
		Year: 2012
		Actor: Hanson, Zac
		Rating: 6.7

		...

		Title: MSN Exclusives
		Year: 2012
		Actor: Hanson, Taylor (III)
		Rating: 6.7

		Total Count: 11
		Would you like to (s)earch, (l)ist movies or (e)xit? e
	*/

	vector<movie> movies;

	int movieCount;

	inputMoviesFromFile( movies );

	string input;
	while( input != "e" ) {
		// cout << "Would you like to (a)dd a movie, (l)ist movies, or (e)xit? ";
		cout << "Would you like to (s)earch, (l)ist movies or (e)xit? ";
		cin >> input;
		if( input == "s" ) {
			cout << "Search menu:" << endl
					 << "1. Search by Title" << endl
					 << "2. Search by Year" << endl
					 << "3. Search by Actor" << endl
					 << "4. Search by Rating" << endl;

			string searchInput;
			cin.ignore( );
			bool validInput = false;
			int searchIntput;
			while( !validInput ) {
				cout << "Enter option: ";
				getline( cin, searchInput );

				try {
					searchIntput = stoi( searchInput );
					validInput = true;
					if( searchIntput > 4 || searchIntput < 1 )
						throw logic_error( "Please pick a number between 1 and 4." );
				} catch( invalid_argument ) {
					cout << "Not a valid number. Please try again." << endl;
					validInput = false;
				} catch( exception const &e ) {
					cout << e.what( ) << endl;
					validInput = false;
				}
			}

			switch( searchIntput ) {
				case 1: { // title
					int loops = 0;
					cout << "Please enter a title to search for: ";
					getline( cin, searchInput );
					for( movie curMovie : movies )
						if( curMovie.title.find( searchInput ) != string::npos )
							printMovie( curMovie, loops );
					cout << "Total Count: " << loops << endl;
					break;
				}
				case 2: { // year
					int startYear, endYear, loops = 0;
					startYear = getValidIntInput( "Please enter the starting year to search: " );
					endYear = getValidIntInput( "Please enter the ending year to search: ", startYear );
					cout << "Please enter the starting year to search: ";
					cin >> startYear;
					cout << "Please enter the ending year to search: ";
					cin >> endYear;
					for( movie curMovie : movies )
						if( curMovie.year >= startYear && curMovie.year <= endYear )
							printMovie( curMovie, loops );
					cout << "Total Count: " << loops << endl;
					break;
				}
				case 3: { // actor
					int loops = 0;
					cout << "Please enter an actor to search for: ";
					getline( cin, searchInput );
					for( movie curMovie : movies )
						if( curMovie.actor.find( searchInput ) != string::npos )
							printMovie( curMovie, loops );
					cout << "Total Count: " << loops << endl;
					break;
				}
				case 4: { // rating
					int minRating, maxRating, loops = 0;
					minRating = getValidDoubleInput( "Please enter the minimum rating to search (inclusive): ", 1, 10 );
					maxRating = getValidDoubleInput( "Please enter the maximum rating to search (inclusive): ", minRating, 10 );
					for( movie curMovie : movies )
						if( curMovie.rating >= minRating && curMovie.rating <= maxRating )
							printMovie( curMovie, loops );
					cout << "Total Count: " << loops << endl;
					break;
				}
			}

		} else if( input == "l" ) {
			cout << "-------------------- " << endl;
			for( movie curMovie : movies )
				printMovie( curMovie );

			cout << "Movie Count: " << movies.size( ) << endl;
		}
	}

	return 0;
}