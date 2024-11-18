/**
 * @file BinaryTree.h
 */

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "TreeNode.h"

/**
 * @brief a binary tree
 */
template <class T>
class BinaryTree {
	public:
		/** @brief Creates an empty Binary Tree */
		BinaryTree( );
		/**
		 * @brief Creates an empty Binary Tree with a root of `node`
		 *
		 * @param node new root of the tree
		 * @param fullTree if false (default) will only copy `node`'s value - else will copy the entire node structure
		 */
		BinaryTree(TreeNode<T>* node, bool fullTree = false);
		~BinaryTree( );

		/**
		 * @brief inserts a list of items into the tree
		 *
		 * @param items a list of `T` items to insert into the tree
		 * @param size the size of the list
		 */
		void add(T items[], int size);

		/**
		 * @brief inserts a single item into the tree
		 *
		 * @param val value to be inserted
		 */
		void insert(T val);

		/** @brief prints the tree sideways */
		void printSideways( );

		/** @return the height of the tree */
		int height( );

		/**
		 * @brief prints a(n) in/pre/post-order
		 *
		 * @param order  "in", "pre", or "post"
		 * @return
		 */
		std::string traversal(std::string order = "in", std::string separator = ", ");

	private:
		/**
		 * @param order 0 - in, 1 - pre, 2 - post
		 */
		void traversal(int order, std::string separator, std::string* result, TreeNode<T>* node);

		/**
		 * @brief properly deletes the node and all of its children
		 *
		 * @param node
		 */
		void deleteNode(TreeNode<T>* node);

		/**
		 * @brief inserts a value under a node
		 *
		 * @param val value to be inserted
		 * @param node node to be inserted below
		 */
		void insert(T val, TreeNode<T>* node);

		/**
		 * @brief prints root at an indentation
		 *
		 * @param root
		 * @param level
		 */
		void printSideways(TreeNode<T>* root, int level);

		/**
		 * @param root the *top of the tree
		 * @return the max height below `root`
		 */
		int height(TreeNode<T>* root);

		TreeNode<T>* overallRoot;
};

#include "BinaryTree.cpp"

#endif // BINARY_TREE_H