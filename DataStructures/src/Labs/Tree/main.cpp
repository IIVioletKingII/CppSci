/**
 * @file main.cpp
 */

#include "Tree.h"
#include "TreeNode.h"

// template <typename T>
// TreeNode<T> n(Tree<T> val) {
// 	return new TreeNode(val);
// }

// template <class T>
// TreeNode<T> n(T val, TreeNode<T> l, TreeNode<T> r) {
// 	return new TreeNode(val, l, r);
// }

int main( ) {
	TreeNode<int> a(3);
	TreeNode<int> b(5);
	// TreeNode<int> test(7, a, b);

	// Tree<int>* tree = new Tree<int>( );
	// Tree<int>* tree2 = new Tree<int>( );

	// Tree<int> tree = new Tree<int>(n(3, n(4, n(0), n(9, nullptr, n(8))), n(7, nullptr, n(2))), true);
	// Tree<int> tree2 = new Tree<int>(n(3, n(6, n(0, nullptr, n(8)), nullptr), n(7, n(9), n(2))), true);
	// int array[11] = {2, 8, 9, 7, 6, 4, 1, 0, 3, 4, 5};
	// tree.add(array, 11);

	// std::cout << "-----------------------" << std::endl;

	// tree.printSideways( );
	// tree2.printSideways( );

	// std::cout << "-----------------------" << std::endl;

	// std::cout << ("height: " + tree.matches(tree2));
	// tree.makePerfect( );

	// std::cout << tree.inOrderList() << std::endl;
	// std::cout << "-----------------------" << std::endl;

	// tree.printSideways( );
	// std::cout << "-----------------------" << std::endl;

	return 0;
}