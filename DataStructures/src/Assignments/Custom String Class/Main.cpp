#include <iostream>
#include <string>
using namespace std;
#include "SLLString.h"

int main( ) {
	SLLString str("Hello world!");
	SLLString newStr;

	newStr = str;

	newStr += SLLString(" CS@BC");
	newStr[6] = 'W';

	cout << str << endl;												 // Hello World! CS@BC
	cout << "Length: " << str.length( ) << endl; // 18

	int loc = newStr.findSubstring("World");
	cout << loc << endl; // 6

	// newStr.erase('H');															// erase the letter l
	// cout << newStr << endl;													// Heo Word! CS@BC
	// cout << "Length: " << newStr.length( ) << endl; // 15

	// newStr.erase('C');
	// cout << newStr << endl;													// Heo Word! S@B
	// cout << "Length: " << newStr.length( ) << endl; // 13

	return 0;
}