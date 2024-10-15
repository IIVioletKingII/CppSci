/**
 * @file PlainBag.cpp
 */

#include "PlainBag.h"
#include <iostream>

template <class T>
PlainBag<T>::PlainBag( )
		: m_size(0), m_items(new T[this->capacity]) {
}

template <class T>
bool PlainBag<T>::insert(const T& item) {
	if( m_size < this->capacity ) {
		m_items[m_size++] = item;
		return true;
	}
	return false;
}

template <class T>
void PlainBag<T>::removeIndex(int index) {
	for( int i = index + 1; i < m_size; ++i )
		m_items[i - 1] = m_items[i];
	if( index < m_size )
		--m_size;
}

template <class T>
bool PlainBag<T>::remove(const T& item) {
	for( int i = 0; i < m_size; ++i ) {
		if( m_items[i] == item ) {
			removeIndex(i);
			return true;
		}
	}
	return false;
}

template <class T>
bool PlainBag<T>::query(const T& item) {
	for( int i = 0; i < m_size; ++i )
		if( m_items[i] == item )
			return true;
	return false;
}

template <class T>
int PlainBag<T>::itemCount(const T& item) {
	int numFound = 0;
	for( int i = 0; i < m_size; ++i )
		if( m_items[i] == item )
			++numFound;
	return numFound;
}

template <class T>
void PlainBag<T>::empty( ) {
	m_size = 0;
}

template <class T>
int PlainBag<T>::size( ) {
	return m_size;
}

template <class T>
bool PlainBag<T>::isEmpty( ) {
	return m_size == 0;
}

template <class T>
bool PlainBag<T>::isFull( ) {
	return m_size == this->capacity;
}

template <class T>
void PlainBag<T>::print( ) {
	std::cout << std::endl
						<< "Bag Contents:";
	for( int i = 0; i < m_size; ++i )
		cout << m_items[i] << " ";
}

// template <class T>
// PlainBag<T>::~PlainBag( ) {
// }