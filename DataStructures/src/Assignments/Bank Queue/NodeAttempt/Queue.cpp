/**
 * @file Queue.cpp
 */

#ifndef QUEUE_CPP
#define QUEUE_CPP

#include "Queue.h"
#include <iostream>

template <class T>
Queue<T>::~Queue( ) {
	while( m_front ) {
		Node* temp = m_front;
		m_front = m_front->m_next;
		temp->m_next = nullptr;
		delete temp;
	}
	m_front = m_back = nullptr;
}


template <class T>
void Queue<T>::enqueue(const T& input) {
	if( !isFull( ) ) {
		std::cout << input << std::endl;
		T* data = new T(input);
		Node* newNode = new Node(data);

		if( m_front ) {
			m_back->m_next = newNode;
			m_back = newNode;
		} else {
			m_back = m_front = newNode;
		}
		++m_length;
	}
}

template <class T>
T& Queue<T>::dequeue( ) {
	// T result = m_front->m_data;
	// if( m_front ) {
	// 	m_front = m_front->m_next;
	// 	--m_length;
	// }
	// return result;
	// return nullptr;
}

template <class T>
T& Queue<T>::peek( ) {
	// return m_front->m_data;
	// return nullptr;
}

template <class T>
void Queue<T>::print( ) {
	Node* cur = m_front;
	std::cout << "F [ ";
	while( cur ) {
		T& data = *cur->m_data;
		std::cout << "(" << data << ")" << (cur->m_next ? "," : "") << " ";
		cur = cur->m_next;
	}
	std::cout << "] B" << std::endl;
}

template <class T>
bool Queue<T>::isEmpty( ) {
	return m_length == 0;
}

template <class T>
bool Queue<T>::isFull( ) {
	return m_length == 100;
}

#endif // QUEUE_CPP