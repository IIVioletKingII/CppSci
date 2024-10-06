#include <iostream>
using namespace std;

int main( ) {
	int x = 4, *px = &x;
	int y = 8, &ry = y;

	// ry = *px;
	// *px = x + y;

	cout << x << endl;
	// cout << *px << endl;
	cout << y << endl;
	// cout << ry << endl;

	return 0;
}