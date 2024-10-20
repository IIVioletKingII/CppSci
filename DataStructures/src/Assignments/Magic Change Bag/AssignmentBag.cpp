// main.cpp--See sample run located after the main function
#include <iostream>
#include "MagicChangeBag.h"
#include "PlainBag.h"

using namespace std;
template <class T>

void testBag(BagInterface<T>& bag) {
	T value;
	T item1 = 1;
	T item2 = 2;
	for( int i = 0; i < 20; i++ ) {
		value = rand( ) % 6 + 1; // assume storing integers for sake of simplicity
		bag.insert(value);
	}
	bag.print( );
	cout << "\nNumber of items:" << bag.size( );
	cout << "\nNumber of ones:" << bag.itemCount(item1);
	bag.remove(item1);
	bag.print( );
	cout << "\nNumber of items:" << bag.size( );
	cout << "\nNumber of ones:" << bag.itemCount(item1);
	cout << "\nNumber of twos:" << bag.itemCount(item2);
};

int main( ) {
	cout << "\n..............................." << endl;
	cout << "Testing Plain Bag" << endl;
	BagInterface<int>* bag = new PlainBag<int>;
	testBag(*bag);
	cout << "\n..............................." << endl;
	cout << "Testing Magic Change Bag" << endl;
	bag = new MagicChangeBag<int>;
	testBag(*bag);
	return 0;
}

int main2( ) {
	// main2( );
	// cout << endl
	// 		 << "------------------------" << endl;
	// BagInterface<int>* bag = new MagicChangeBag<int>;
	// int test = 25;
	// for( int i = 0; i < 15; ++i ) {
	// 	int value = rand( ) % 6 + 1; // assume storing integers for sake of simplicity
	// 	bool success = bag->insert(value);
	// 	// cout << "Success: " << (success ? "true" : "false") << endl;
	// }

	// bag->print( );
	// bag->remove(3);
	// bag->print( );

	// for( int i = 0; i < 15; ++i )
	// 	bag->insert(rand( ) % 6 + 1);
	// cout << "\nSize: " << bag->size( ) << endl;
	// bag->print( );
	// bag->remove(6);
	// bag->print( );

	// cout << "\nSize: " << bag->size( ) << endl;
	return 0;
}
/*
Sample Run:
Testing Plain Bag

6 6 5 5 6 5 1 1 5 3 6 6 2 4 2  6 2 3 4 1

Bag content:2 2 6 3 5 3 1 3 6 2 1 6 1 3 4 6 2 2 5 5
Number of items:20
Number of ones:3
Bag content:2 2 6 3 5 3 3 6 2 1 6 1 3 4 6 2 2 5 5
Number of items:19
Number of ones:2
Number of twos:5

...............................

Testing Magic Change Bag

Bag content:
Number of items:0
Number of ones:0
Bag content:4 2 4 6 5 4 4 1 3 2 2 3 3 2 3 4 2 2 4 4
Bag content:4 2 4 6 5 4 4 3 2 2 3 3 2 3 4 2 2 4 4
Number of items:19
Number of ones:0
Number of twos:6
*/