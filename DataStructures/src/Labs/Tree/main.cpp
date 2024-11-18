/**
 * @file main.cpp
 */

#include "Tree.h"
#include "TreeNode.h"

using namespace std;

// template <class T>
// TreeNode<T> i(Tree<T> val) {
// 	return new TreeNode(val, nullptr, nullptr);
// }

template <class T>
TreeNode<T>* t(T val, TreeNode<T>* l = nullptr, TreeNode<T>* r = nullptr) {
	return new TreeNode<T>(val, l, r);
}

TreeNode<int>* i(int val, TreeNode<int>* l = nullptr, TreeNode<int>* r = nullptr) {
	return new TreeNode<int>(val, l, r);
}

TreeNode<string>* s(string val, TreeNode<string>* l = nullptr, TreeNode<string>* r = nullptr) {
	return new TreeNode<string>(val, l, r);
}

int main( ) {
	// TreeNode<int>* a = new TreeNode<int>(3);
	// TreeNode<int> b(5);
	// TreeNode<int> test(7, a, &b);

	// cout << "A: " << test << endl;


	// Tree<string> tree = Tree<string>(s("A", s("B", s("D"), s("E")), s("C", s("F"), s("G"))), true);
	// Tree<int> tree = Tree<int>(i(1, i(2, i(4), i(5)), i(3, i(6), i(7))), true);
	// Tree<int> tree = Tree<int>(i(14, i(2, i(1), i(3)), i(11, i(10, i(7)), i(30, i(40)))), true);

	// Tree<int> tree = Tree<int>(i(3, i(4, i(0), i(9, nullptr, i(8))), i(7, nullptr, i(2))), true);
	// Tree<int> tree2 = Tree<int>(t<int>(3, t<int>(6, t<int>(0, nullptr, t<int>(8)), nullptr), t<int>(7, t<int>(9), t<int>(2))), true);

	Tree<int> tree = Tree<int>( );
	int array[11] = {2, 8, 9, 7, 6, 4, 1, 0, 3, 4, 5};
	tree.add(array, 11);

	// Tree<int> tree2 = Tree<int>( );
	// int array[7] = {1};
	// tree2.add(array, 7);


	tree.insert(1);
	tree.traversal( );
	tree.traversal("pre");
	tree.traversal("post");
	cout << "-----------------------" << endl;
	tree.printSideways( );
	// tree2.printSideways( );

	// cout << "-----------------------" << endl;

	// cout << ("height: " + tree.matches(tree2));
	// tree.makePerfect( );

	// cout << tree.inOrderList() << endl;
	// cout << "-----------------------" << endl;

	// tree.printSideways( );
	// cout << "-----------------------" << endl;

	return 0;
}