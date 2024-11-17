/**
 * @file Tree.cpp
 */


#ifndef TREE_CPP
#define TREE_CPP

#include "Tree.h"
#include <algorithm>
#include <iostream>
#include "TreeNode.h"

template <class T>
Tree<T>::Tree( ) {
}


template <class T>
Tree<T>::Tree(TreeNode<T> node) {
}


template <class T>
Tree<T>::Tree(TreeNode<T> node, bool fullTree) {
	overallRoot = fullTree ? node : new TreeNode(node.value);
}

template <class T>
Tree<T>::~Tree( ) {
}

template <class T>
void Tree<T>::insert(T val) {

	if( overallRoot )
		insert(val, overallRoot);
	else
		overallRoot = new TreeNode(val);
}


template <class T>
void Tree<T>::insert(T val, TreeNode<T> node) {
	if( val > node.value ) {
		if( node.right == nullptr )
			node.right = new TreeNode(val);
		else
			insert(val, node.right);
	} else {
		if( node.left == nullptr )
			node.left = new TreeNode(val);
		else
			insert(val, node.left);
	}
}


template <class T>
void Tree<T>::printSideways( ) {
	printSideways(overallRoot, 0);
}


template <class T>
void Tree<T>::printSideways(TreeNode<T> root, int level) {
	if( root != nullptr ) {
		printSideways(root.right, level + 1);
		for( int i = 0; i < level; i++ )
			std::cout << "    ";
		std::cout << root.value << std::endl;
		printSideways(root.left, level + 1);
	}
}

template <class T>
void Tree<T>::trim(T min, T max) {
	overallRoot = trim(min, max, overallRoot);
}


template <class T>
TreeNode<T> Tree<T>::trim(T min, T max, TreeNode<T> node) {

	if( node == nullptr )
		return nullptr;

	if( node.value < min )
		return trim(min, max, node.right);
	if( node.value > max )
		return trim(min, max, node.left);

	if( node.left != nullptr )
		node.left = trim(min, max, node.left);
	if( node.right != nullptr )
		node.right = trim(min, max, node.right);

	return node;
}


template <class T>
void Tree<T>::tighten( ) {
	overallRoot = tighten(overallRoot);
}


template <class T>
TreeNode<T> Tree<T>::tighten(TreeNode<T> node) {

	if( node != nullptr ) {
		if( (node.left != nullptr && node.right != nullptr) || (node.left == nullptr && node.right == nullptr) ) {
			node.left = tighten(node.left);
			node.right = tighten(node.right);
		} else
			return tighten(node.left != nullptr ? node.left : node.right);
	}

	return node;
}


template <class T>
void Tree<T>::add(T nums[], int size) {
	for( int i = 0; i < size; ++i )
		insert(nums[i]);
}



template <class T>
Tree<T> Tree<T>::combineWith(Tree t) {
	Tree val = new Tree( );
	val.overallRoot = combineWith(overallRoot, t == nullptr ? nullptr : t.overallRoot);
	return val;
}


template <class T>
TreeNode<T> Tree<T>::getIfValid(TreeNode<T> node, bool left) {
	if( node == nullptr )
		return nullptr;
	return left ? node.left : node.right;
}


template <class T>
TreeNode<T> Tree<T>::combineWith(TreeNode<T> n1, TreeNode<T> n2) {
	int val = 0;
	if( n1 != nullptr )
		val += 1;
	if( n2 != nullptr )
		val += 2;

	if( val == 0 )
		return nullptr;
	return new TreeNode(
			val,
			combineWith(
					getIfValid(n1, true),
					getIfValid(n2, true)),
			combineWith(
					getIfValid(n1, false),
					getIfValid(n2, false)));
}


// template <class T>
// List<Integer> Tree<T>::inOrderList( ) {
// 	ArrayList<Integer> list = new ArrayList<>( );
// 	if( overallRoot != nullptr )
// 		inOrderList(overallRoot, list);
// 	return list;
// }


// template <class T>
// void Tree<T>::inOrderList(TreeNode node, ArrayList<Integer> list) {
// 	if( node.left != nullptr )
// 		inOrderList(node.left, list);
// 	list.add(node.data);
// 	if( node.right != nullptr )
// 		inOrderList(node.right, list);
// }


template <class T>
void Tree<T>::evenLevels( ) {
	overallRoot = evenLevels(overallRoot, 1);
}


template <class T>
TreeNode<T> Tree<T>::evenLevels(TreeNode<T> node, int lvl) {
	if( node == nullptr )
		return nullptr;
	if( lvl++ % 2 == 1 && node.left == nullptr && node.right == nullptr )
		return nullptr;

	node.left = evenLevels(node.left, lvl);
	node.right = evenLevels(node.right, lvl);
	return node;
}


template <class T>
int Tree<T>::height( ) {
	return height(overallRoot);
}


template <class T>
int Tree<T>::height(TreeNode<T> root) {
	return root == nullptr ? 0 : 1 + std::max(height(root.left), height(root.right));
}


template <class T>
void Tree<T>::makePerfect( ) {
	overallRoot = makePerfect(overallRoot, height( ), 1);
}


template <class T>
TreeNode<T> Tree<T>::makePerfect(TreeNode<T> node, int maxHeight, int lvl) {
	if( node != nullptr ) {
		lvl++;
		if( lvl <= maxHeight ) {
			if( node.left == nullptr )
				node.left = new TreeNode(0);
			if( node.right == nullptr )
				node.right = new TreeNode(0);
		}
		node.left = makePerfect(node.left, maxHeight, lvl);
		node.right = makePerfect(node.right, maxHeight, lvl);
	}
	return node;
}


template <class T>
int Tree<T>::matches(Tree tree) {
	return matches(overallRoot, tree.overallRoot);
}


template <class T>
int Tree<T>::matches(TreeNode<T> n1, TreeNode<T> n2) {
	if( n1 == nullptr || n2 == nullptr )
		return 0;
	return (n1.value == n2.value ? 1 : 0) + (n1.left != nullptr && n2.left != nullptr ? matches(n1.left, n2.left) : 0) + (n1.right != nullptr && n2.right != nullptr ? matches(n1.right, n2.right) : 0);
}


#endif // TREE_CPP