#include <string>

using namespace std;

string upperCase( string phrase ) {
	for( int i = 0; i < phrase.length( ); i++ )
		phrase[i] = toupper( phrase[i] );
	return phrase;
}