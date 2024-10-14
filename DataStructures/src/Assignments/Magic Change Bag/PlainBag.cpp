/**
 * @file PlainBag.cpp
 */

#include "PlainBag.h"
#include <iostream>

template <class T>
PlainBag<T>::PlainBag( )
		: m_size(0), m_capacity(20), m_items(new T[m_capacity]) {
	// std::cout << "Created PlainBag " << m_items[0] << std::endl;
}
template <class T>
bool PlainBag<T>::insert(const T& item) {
	if( m_size < m_capacity ) {
		m_items[m_size++] = item;
		std::cout << " * Inserting item " << item << " at " << m_size - 1 << std::endl;
		return true;
	}
	return false;
}

template <class T>
bool PlainBag<T>::remove(const T& item) {
	bool removed = false;
	for( int i = 0; i < m_size; ++i ) {
		if( m_items[i] == item ) {
			removeIndex(i);
			removed = true;
		}
	}
	return removed;
}
template <class T>
void removeIndex(int index) {
	for( int i = index + 1; i < m_size; ++i )
		m_items[i - 1] = m_items[i];
	if( index < m_size )
		--m_size;
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
	int removed = 0;
	for( int i = 0; i < m_size; ++i )
		if( m_items[i] == item )
			++removed;
	return removed;
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
	return m_size == m_capacity;
}
template <class T>
void PlainBag<T>::print( ) {
	std::cout << "Bag Contents:";
	for( int i = 0; i < m_size; ++i )
		cout << " " << m_items[i];
	std::cout << std::endl;
}
// template <class T>
// PlainBag<T>::~PlainBag( ) {
// }