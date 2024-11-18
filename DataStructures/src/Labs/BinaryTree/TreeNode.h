/**
 * @file TreeNode.cpp
 */

#ifndef TREE_NODE_H
#define TREE_NODE_H

/**
 * @brief Node of a Tree
 */
template <class T>
class TreeNode {
	public:
		/** @brief Creates an empty Tree Node */
		TreeNode( );
		/**
		 * @brief Construct a new Tree Node object
		 *
		 * @param value value of node
		 * @param left node's left child (default nullptr)
		 * @param right node's right child (default nullptr)
		 */
		TreeNode(T value, TreeNode<T>* left = nullptr, TreeNode<T>* right = nullptr);

		T data;
		TreeNode<T>* left;
		TreeNode<T>* right;
};

#include "TreeNode.cpp"

#endif // TREE_NODE_H