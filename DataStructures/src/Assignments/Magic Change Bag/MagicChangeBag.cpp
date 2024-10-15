/**
 * @file MagicChangeBag.cpp
 */

#include "MagicChangeBag.h"

template <class T>
MagicChangeBag<T>::MagicChangeBag( )
		: m_size(0), m_hiddenSize(0), m_items(new T[this->capacity]), m_hiddenItems(new T[this->capacity]) {
}

template <class T>
bool MagicChangeBag<T>::insert(const T& item) {
	if( m_size + m_hiddenSize < this->capacity ) {
		m_hiddenItems[m_hiddenSize++] = item;
		// std::cout << " * Inserting item " << item << " at " << m_size - 1 << std::endl;
		return true;
	}
	return false;
}

template <class T>
void MagicChangeBag<T>::removeIndex(T& arr, int& size, const int index) {
	for( int i = index + 1; i < size; ++i )
		arr[i - 1] = arr[i];
	if( index < size )
		--size;
}

template <class T>
bool MagicChangeBag<T>::remove(const T& item) {
	// moves all hidden items
	bool success = false;
	for( int i = 0; i < m_size; ++i ) {
		if( success )
			m_items[i] = m_items[i + 1];

		if( !success && m_items[i] == item ) {
			success = true;
			--i;
		}
	}
	if( success )
		--m_size;

	bool foundInHidden = false;

	for( int arrI = m_size, hArrI = 0; arrI < m_size + m_hiddenSize; ++arrI, ++hArrI ) {
		if( !success && !foundInHidden && m_hiddenItems[hArrI] == item ) {
			success = foundInHidden = true;
			++hArrI;
		}
		m_items[arrI] = m_hiddenItems[hArrI];
	}

	m_size += m_hiddenSize - (foundInHidden ? 1 : 0);
	m_hiddenSize = 0;

	return success;
}

template <class T>
bool MagicChangeBag<T>::query(const T& item) {
	for( int i = 0; i < m_size; ++i )
		if( m_items[i] == item )
			return true;
	return false;
}

template <class T>
int MagicChangeBag<T>::itemCount(const T& item) {
	int numFound = 0;
	for( int i = 0; i < m_size; ++i )
		if( m_items[i] == item )
			++numFound;
	return numFound;
}

template <class T>
void MagicChangeBag<T>::empty( ) {
	m_size = 0;
	m_hiddenSize = 0;
}

template <class T>
int MagicChangeBag<T>::size( ) {
	return m_size;
}

template <class T>
bool MagicChangeBag<T>::isEmpty( ) {
	return m_size == 0;
}

template <class T>
bool MagicChangeBag<T>::isFull( ) {
	return m_size == this->capacity;
}

template <class T>
void MagicChangeBag<T>::print( ) {
	std::cout << std::endl
						<< "Bag Contents:";
	for( int i = 0; i < m_size; ++i )
		std::cout << m_items[i] << " ";
}
// template <class T>
// MagicChangeBag<T>::~MagicChangeBag( ) {
// }