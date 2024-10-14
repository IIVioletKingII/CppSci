/**
 * @file MagicChangeBag.cpp
 */

#include "MagicChangeBag.h"

template <class T>
MagicChangeBag<T>::MagicChangeBag( )
		: m_size(0) {
}
template <class T>
bool MagicChangeBag<T>::insert(const T& item) {
	return false;
}

template <class T>
bool MagicChangeBag<T>::remove(const T& item) {
	return false;
}
template <class T>
bool MagicChangeBag<T>::query(const T& item) {
	return false;
}
template <class T>
int MagicChangeBag<T>::itemCount(const T& item) {
	return 0;
}
template <class T>
void MagicChangeBag<T>::empty( ) {
}
template <class T>
int MagicChangeBag<T>::size( ) {
	return 0;
}
template <class T>
bool MagicChangeBag<T>::isEmpty( ) {
	return false;
}
template <class T>
bool MagicChangeBag<T>::isFull( ) {
	return false;
}
template <class T>
void MagicChangeBag<T>::print( ) {
}
// template <class T>
// MagicChangeBag<T>::~MagicChangeBag( ) {
// }