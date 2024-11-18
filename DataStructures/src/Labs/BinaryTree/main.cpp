/**
 * @file main.cpp
 */

#include "BinaryTree.h"
#include "TreeNode.h"

using namespace std;

int main( ) {
	BinaryTree<int> tree = BinaryTree<int>( );
	int array[9] = {2, 8, 9, 7, 4, 1, 0, 3, 5};
	tree.add(array, 9);
	tree.insert(6);

	cout << "-----------------------" << endl;

	string orders[3] = {"in", "pre", "post"};
	for( int i = 0; i < 3; i++ )
		cout << orders[i] << "-order:\t" << tree.traversal(orders[i]) << endl;

	cout << "-----------------------" << endl;

	tree.printSideways( );

	cout << "-----------------------" << endl;

	cout << "height: " << tree.height( ) << endl;

	cout << "-----------------------" << endl;

	return 0;
}