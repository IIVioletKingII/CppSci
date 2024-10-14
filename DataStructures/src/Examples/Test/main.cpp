#include <iostream>
using namespace std;

int mystery2(int a) {
	if( a == 1 )
		return 2;
	return 1 + mystery2(a / 10) + mystery2(a / 10);
}

int mystery(int j) {
	if( j == 1 )
		return 1;
	return 2 * mystery(j - 1) + 5 * mystery(j - 2);
}

int main( ) {
	// int x = 4, *px = &x;
	// int y = 8, &ry = y;

	// ry = *px;
	// *px = x + y;

	// cout << x << endl;
	// cout << *px << endl;
	// cout << y << endl;
	// cout << ry << endl;
	// cout << mystery2(5) << endl;

	// cout << mystery(2) << endl;

	int A[10];
	int* pa;
	pa = A;

	// *pa = *pa + 1;

	// pa = &A[2];

	// *pa = 1;

	// A = A + 1;

	return 0;
}

/*

5: Mystery needs to have a base case for "j == 0" or "j < 0" because if j is 0 or 1, the recursive calls will pass negative numbers causing an infinite loop.

Just an fyi, Question 6 asks about two functions f and g but the code shows functions x and y.
*/

void x( ) {
	double a = 2.3;
	double* ap = &a;
}
void y( ) {
	double* p = new double(3.4);
}