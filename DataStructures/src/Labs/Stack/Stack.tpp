//
// Created by gordon.gul on 10/17/2024.
// Modfied by sam.depoule on 10/20/2024.
//

#include "Stack.h"

template <class T>
Stack<T>::Node::Node(T tempData) {
	m_data = tempData;
	m_pPrevious = nullptr;
	m_pNext = nullptr;
}


template <class T>
Stack<T>::Stack( ) {
	m_pTop = nullptr;
	m_pBottom = nullptr;
}

template <class T>
Stack<T>::~Stack( ) {
	// Delete Stack
	while( m_pBottom && m_pBottom->m_pNext ) {
		m_pBottom = m_pBottom->m_pNext;
		m_pBottom->m_pPrevious = m_pBottom->m_pPrevious->m_pNext = nullptr;
	}
	m_pTop = nullptr;
	m_pBottom = nullptr;
}

template <class T>
void Stack<T>::push(T tempData) {
	Node* newNode = new Node(tempData);

	if( m_pBottom ) {
		m_pTop->m_pNext = newNode;
		newNode->m_pPrevious = m_pTop;
		m_pTop = newNode;
	} else {
		m_pBottom = m_pTop = newNode;
	}
}

template <class T>
T Stack<T>::pop( ) {
	// Remove node

	if( m_pTop == nullptr )
		throw std::out_of_range("Call to pop() on empty stack.");

	T topData = m_pTop->m_data;

	if( m_pTop == m_pBottom ) {
		m_pTop = nullptr;
		m_pBottom = nullptr;
	} else {
		Node* tempNode = m_pTop->m_pPrevious;
		tempNode->m_pNext = nullptr;
		m_pTop = tempNode;
	}

	return topData;
}