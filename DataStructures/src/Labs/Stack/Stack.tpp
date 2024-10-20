//
// Created by gordon.gul on 10/17/2024.
//

#ifndef STACK_TPP
#define STACK_TPP

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
}

template <class T>
void Stack<T>::push(T tempData) {
	Node* tempNode = new Node(tempData);

	if( m_pBottom ) {
		m_pTop->m_pNext = tempNode;
		tempNode->m_pPrevious = m_pTop;
		m_pTop = tempNode;
	} else {
		m_pBottom = m_pTop = tempNode;
	}
}

template <class T>
T Stack<T>::pop( ) {
	// Remove node

	return 0;
}

#endif // STACK_TPP