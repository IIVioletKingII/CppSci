/**
 * @file TreeNode.cpp
 */

#ifndef TREE_NODE_H
#define TREE_NODE_H

#include <iostream>

/**
 * @brief Node of a Tree
 */
template <class T>
class TreeNode {
	public:
		TreeNode( );
		TreeNode(T value);
		TreeNode(T value, TreeNode<T>* left, TreeNode<T>* right);
		// TreeNode(T value, TreeNode<T> left = nullptr, TreeNode<T> right = nullptr);

		// friend std::ostream& operator<<(std::ostream& os, const TreeNode<T>& other);

		// private:
		T data;
		TreeNode<T>* left;
		TreeNode<T>* right;
};

#include "TreeNode.cpp"

#endif // TREE_NODE_H