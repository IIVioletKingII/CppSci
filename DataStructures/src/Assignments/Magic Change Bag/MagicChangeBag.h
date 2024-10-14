/**
 * @file MagicChangeBag.h
 */

#ifndef MAGIC_CHANGE_BAG_H
#define MAGIC_CHANGE_BAG_H

#include "BagInterface.h"

using namespace std;

template <class T>
class MagicChangeBag : public BagInterface<T> {
	public:
		MagicChangeBag( );
		bool insert(const T& item);
		bool remove(const T& item);
		bool query(const T& item);
		int itemCount(const T& item);
		void empty( );
		int size( );
		bool isEmpty( );
		bool isFull( );
		void print( );
		~MagicChangeBag( ) {}

	private:
		std::vector<int> m_items;
		int m_size = 0;
		const int m_capacity = 20;
};

#include "MagicChangeBag.cpp"
#endif // MAGIC_CHANGE_BAG_H
