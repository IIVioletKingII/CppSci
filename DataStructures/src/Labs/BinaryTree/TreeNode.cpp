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
}

template <class T>
TreeNode<T>::TreeNode(T value, TreeNode<T>* left, TreeNode<T>* right)
		: data(value), left(left), right(right) {
}

#endif // TREE_NODE_CPP