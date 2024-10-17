/**
 * @file MagicChangeBag.h
 */

#ifndef MAGIC_CHANGE_BAG_H
#define MAGIC_CHANGE_BAG_H

#include "BagInterface.h"

using namespace std;

/**
 * @brief a magical bag of 20 items of type T from `BagInterface`
 *
 * @tparam T
 */
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
		~MagicChangeBag( ) {
			delete[] m_items;
			delete[] m_hiddenItems;
		}

	private:
		void removeIndex(T& arr, int& size, const int index);

		T* m_items;
		T* m_hiddenItems;
		int m_size;
		int m_hiddenSize;
};

#include "MagicChangeBag.cpp"
#endif // MAGIC_CHANGE_BAG_H
