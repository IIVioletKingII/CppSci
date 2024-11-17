/**
 * @file TreeNode.cpp
 */

#ifndef TREE_NODE_CPP
#define TREE_NODE_CPP

#include "TreeNode.h"
#include <iostream>

template <class T>
TreeNode<T>::TreeNode( )
		: left(nullptr), right(nullptr) {
	// data = nullptr;
}

template <class T>
TreeNode<T>::TreeNode(T value)
		: data(value), left(nullptr), right(nullptr) {
}

template <class T>
TreeNode<T>::TreeNode(T value, TreeNode<T>* left, TreeNode<T>* right)
		: data(value), left(left), right(right) {
}

// template <class T>
// TreeNode<T>::TreeNode(T value, TreeNode<T> left = nullptr, TreeNode<T> right = nullptr) {
// 	this->data = value;
// 	this->left = left;
// 	this->right = right;
// 	std::cout << "Here 2: " << value << std::endl;
// }

// template <class T>
// std::ostream& operator<<(std::ostream& os, const TreeNode<T>& other) {
// 	return (os << other->data);
// }

#endif // TREE_NODE_CPP