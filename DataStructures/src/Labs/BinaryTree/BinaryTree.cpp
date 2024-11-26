/**
 * @file BinaryTree.cpp
 */


#ifndef TREE_CPP
#define TREE_CPP

#include "BinaryTree.h"
#include <algorithm>
#include <iostream>
#include "TreeNode.h"

template <class T>
BinaryTree<T>::BinaryTree( )
		: overallRoot(nullptr) {
}

template <class T>
BinaryTree<T>::BinaryTree(TreeNode<T>* node, bool fullTree) {
	overallRoot = fullTree ? node : new TreeNode<T>(node->data);
}


template <class T>
BinaryTree<T>::~BinaryTree( ) {
	deleteNode(overallRoot);
}

template <class T>
void BinaryTree<T>::deleteNode(TreeNode<T>* node) {
	if( node ) {
		deleteNode(node->left);
		deleteNode(node->right);

		delete node;
	}
}


template <class T>
void BinaryTree<T>::add(T nums[], int size) {
	for( int i = 0; i < size; ++i )
		insert(nums[i]);
}


template <class T>
void BinaryTree<T>::insert(T val) {

	if( overallRoot )
		insert(val, overallRoot);
	else
		overallRoot = new TreeNode<T>(val);
}

template <class T>
void BinaryTree<T>::insert(T val, TreeNode<T>* node) {
	if( val > node->data ) {
		if( node->right == nullptr )
			node->right = new TreeNode<T>(val);
		else
			insert(val, node->right);
	} else {
		if( node->left == nullptr )
			node->left = new TreeNode<T>(val);
		else
			insert(val, node->left);
	}
}


template <class T>
std::string BinaryTree<T>::traversal(std::string order, std::string separator) {
	int orderInt = 0;
	if( order == "pre" )
		orderInt = 1;
	if( order == "post" )
		orderInt = 2;
	std::string result = "";
	traversal(orderInt, separator, &result, overallRoot);
	int length = result.length( );
	int sepLength = separator.length( );
	if( length > sepLength )
		return result.substr(0, length - sepLength);
	return result;
}

template <class T>
void BinaryTree<T>::traversal(int order, std::string separator, std::string* result, TreeNode<T>* node) {
	if( node ) {
		switch( order ) {
			case 0: // in order (left, this, right)

				traversal(order, separator, result, node->left);
				result->append(std::to_string(node->data) + separator);
				traversal(order, separator, result, node->right);

				break;
			case 1: // pre order (this, left, right)

				result->append(std::to_string(node->data) + separator);
				traversal(order, separator, result, node->left);
				traversal(order, separator, result, node->right);

				break;
			case 2: // post order (left, right, this)

				traversal(order, separator, result, node->left);
				traversal(order, separator, result, node->right);
				result->append(std::to_string(node->data) + separator);

				break;
		}
	}
}


template <class T>
void BinaryTree<T>::printSideways( ) {
	printSideways(overallRoot, 0);
}

template <class T>
void BinaryTree<T>::printSideways(TreeNode<T>* root, int level) {
	if( root ) {
		printSideways(root->right, level + 1);
		for( int i = 0; i < level; i++ )
			std::cout << "    ";
		std::cout << root->data << std::endl;
		printSideways(root->left, level + 1);
	}
}


template <class T>
int BinaryTree<T>::height( ) {
	return height(overallRoot);
}

template <class T>
int BinaryTree<T>::height(TreeNode<T>* root) {
	return root == nullptr ? 0 : 1 + std::max(height(root->left), height(root->right));
}


#endif // TREE_CPP