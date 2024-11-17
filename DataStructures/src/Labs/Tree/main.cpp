/**
 * @file main.cpp
 */

#include "Tree.h"
#include "TreeNode.h"

// template <class T>
// TreeNode<T> n(Tree<T> val) {
// 	return new TreeNode(val, nullptr, nullptr);
// }

template <class T>
TreeNode<T>* t(T val, TreeNode<T>* l = nullptr, TreeNode<T>* r = nullptr) {
	TreeNode<T>* n = new TreeNode<T>(val, l, r);
	return n;
}


template <class T>
TreeNode<int>* n(T val, TreeNode<int>* l = nullptr, TreeNode<int>* r = nullptr) {
	TreeNode<int>* n = new TreeNode<int>(val, l, r);
	return n;
}

int main( ) {
	TreeNode<int>* a = new TreeNode<int>(3);
	TreeNode<int> b(5);
	TreeNode<int> test(7, a, &b);

	// std::cout << "A: " << test << std::endl;

	// Tree<int>* tree = new Tree<int>( );
	// Tree<int>* tree2 = new Tree<int>( );

	Tree<int> tree = Tree<int>(n(3, n(4, n(0), n(9, nullptr, n(8))), n(7, nullptr, n(2))), true);
	Tree<int> tree2 = Tree<int>(t<int>(3, t<int>(6, t<int>(0, nullptr, t<int>(8)), nullptr), t<int>(7, t<int>(9), t<int>(2))), true);
	int array[11] = {2, 8, 9, 7, 6, 4, 1, 0, 3, 4, 5};
	tree.add(array, 11);


	tree.printSideways( );
	std::cout << "-----------------------" << std::endl;
	tree2.printSideways( );

	// std::cout << "-----------------------" << std::endl;

	// std::cout << ("height: " + tree.matches(tree2));
	// tree.makePerfect( );

	// std::cout << tree.inOrderList() << std::endl;
	// std::cout << "-----------------------" << std::endl;

	// tree.printSideways( );
	// std::cout << "-----------------------" << std::endl;

	return 0;
}