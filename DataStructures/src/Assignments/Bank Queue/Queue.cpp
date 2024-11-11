/**
 * @file Queue.cpp
 */

#ifndef QUEUE_CPP
#define QUEUE_CPP

#include "Queue.h"
#include <iostream>

template <class T>
Queue<T>::Queue( )
		: m_length(25), m_front(0), m_back(-1) {
	m_array = new T[m_length];
}

template <class T>
Queue<T>::~Queue( ) {
	delete[] m_array;
	// Results in: "Exception has occurred. - Unknown signal"
}

template <class T>
void Queue<T>::enqueue(const T& input) {
	if( !isFull( ) ) {
		if( m_back > m_length )
			setSize(m_back - m_front + 25);

		m_array[++m_back] = input;
		++m_length;
	}
}

template <class T>
T& Queue<T>::dequeue( ) {
	if( m_back < 0 )
		throw std::out_of_range("Call to dequeue() on empty queue.");
	if( m_front > 20 )
		shiftQueue( );
	int frontIndex = m_front;
	if( m_front++ == m_back ) {
		m_front = 0;
		m_back = -1;
	}
	return m_array[frontIndex];
}

template <class T>
T& Queue<T>::peek( ) {
	return m_array[m_front];
}

template <class T>
void Queue<T>::print( ) {

	std::cout << "F [";
	for( int i = m_front; i <= m_back; ++i )
		std::cout << " (" << m_array[i] << ")" << (i < m_back - 1 ? "," : "");
	std::cout << " ] B" << std::endl;
}

template <class T>
bool Queue<T>::isEmpty( ) {
	return m_back == -1;
}

template <class T>
bool Queue<T>::isFull( ) {
	return m_back - m_front == 100;
}

template <class T>
void Queue<T>::shiftQueue( ) {
	int i = 0;
	for( int j = m_front; i < m_back; ++i, ++j )
		m_array[i] = m_array[j];

	m_front = 0;
	m_back = i;
}

template <class T>
void Queue<T>::setSize(int newLength) {
	m_length = newLength;
	T* newArr = new T[newLength];

	int i = 0;
	for( int j = m_front; i < m_back; ++i, ++j )
		newArr[i] = m_array[j];

	delete[] m_array;
	m_array = newArr;
	m_front = 0;
	m_back = i;
}

#endif // QUEUE_CPP