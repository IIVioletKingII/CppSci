#include <iostream>
#include <sstream> // String Stream
#include <vector>

using namespace std;

vector<string> splitLn( string input, char delimeter = ' ' );

int main( ) {
	cout << "Please enter a phrase: ";
	string phrase;
	getline( cin, phrase );

	vector<string> words = splitLn( phrase );

	for( string word : words ) {
		cout << word << endl;
	}

	return 0;
}

vector<string> splitLn( string input, char delimeter ) {
	vector<string> output;
	// This line turns a string into an input stream
	istringstream stream( input );
	string token;

	/* Now that the string is a stream, we can use
	 * getline on it. This is the 3 parameter
	 * version that can take only one item at a time,
	 * split based on the delimeter. That item gets
	 * added to a vector, then returned.
	 */

	while( getline( stream, token, delimeter ) ) {
		// token holds the new value as we loop
		output.push_back( token );
	}
	return output;
}