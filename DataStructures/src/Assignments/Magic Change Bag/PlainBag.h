/**
 * @file PlainBag.h
 */

#ifndef PLAINBAG_H
#define PLAINBAG_H

#include "BagInterface.h"

using namespace std;

/**
 * @brief a plain simple bag of 20 items of type T from `BagInterface`
 *
 * @tparam T
 */
template <class T>
class PlainBag : public BagInterface<T> {
	public:
		PlainBag( );
		bool insert(const T& item);
		bool remove(const T& item);
		bool query(const T& item);
		int itemCount(const T& item);
		void empty( );
		int size( );
		bool isEmpty( );
		bool isFull( );
		void print( );
		~PlainBag( ) {
			delete[] m_items;
		}

	private:
		void removeIndex(int index);
		T* m_items;
		int m_size;
};

#include "PlainBag.cpp"
#endif // PLAINBAG_H
