/**
 * @file Tree.h
 */

#ifndef TREE_H
#define TREE_H

#include "TreeNode.h"

template <class T>
class Tree {
	public:
		Tree( );
		Tree(const TreeNode<T> node);
		Tree(TreeNode<T>* node, bool fullTree);

		~Tree( );

		void insert(T val);
		void printSideways( );
		// String toString( );
		// void trim(T min, T max);
		void tighten( );
		TreeNode<T> tighten(TreeNode<T>* node);
		void add(T nums[], int size);
		Tree combineWith(Tree t);
		TreeNode<T> getIfValid(TreeNode<T>* node, bool left);
		TreeNode<T> combineWith(TreeNode<T>* n1, TreeNode<T>* n2);
		// List<Integer> inOrderList( );
		// void inOrderList(TreeNode node, ArrayList<Integer> list);
		void evenLevels( );
		int height( );
		void makePerfect( );
		TreeNode<T> makePerfect(TreeNode<T>* node, int maxHeight, int lvl);
		int matches(Tree tree);

	private:
		void deleteNode(TreeNode<T>* node);

		void insert(T val, TreeNode<T>* node);
		void printSideways(TreeNode<T>* root, int level);
		// TreeNode<T> trim(T min, T max, TreeNode<T>* node);

		TreeNode<T> evenLevels(TreeNode<T>* node, int lvl);
		int height(TreeNode<T>* root);
		int matches(TreeNode<T>* n1, TreeNode<T>* n2);

		TreeNode<T>* overallRoot;
};

#include "Tree.cpp"

#endif // TREE_H