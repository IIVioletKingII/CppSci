/**
 * @file SLLString.cpp
 * @author Sam DePoule
 */

#ifndef SLLSTRING_CPP
#define SLLSTRING_CPP

#include "SLLString.h"
#include <string>

SLLString::SLLString( ) {
	m_pHead = nullptr;
	m_pTail = nullptr;
	m_length = 0;
}

SLLString::SLLString(const std::string& other) {
	m_length = other.length( );
	if( m_length > 0 ) {
		m_pHead = new Node(other[0]);
		Node* node = m_pHead;

		for( int i = 1; i < m_length; ++i ) {
			node->m_next = new Node(other[i]);
			node = node->m_next;
		}
		m_pTail = node;
	}
}

SLLString::SLLString(const SLLString& other) {
	if( other.m_pHead ) {
		m_pHead = new Node(other.m_pHead->data);
		Node* oth = other.m_pHead;
		Node* node = m_pHead;
		m_length = 1;

		while( oth->m_next ) {
			oth = oth->m_next;

			node->m_next = new Node(oth->data);
			node = node->m_next;
			++m_length;
		}
		m_pTail = node;

	} else {
		m_pHead = nullptr;
		m_pTail = nullptr;
		m_length = 0;
	}
}

SLLString::~SLLString( ) {
	m_pHead = nullptr;
	m_pTail = nullptr;
}


SLLString& SLLString::operator=(const SLLString& other) {
	if( other.m_pHead ) {
		m_pHead = new Node(other.m_pHead->data);
		Node* oth = other.m_pHead;
		Node* node = m_pHead;
		m_length = 1;

		while( oth->m_next ) {
			oth = oth->m_next;

			node->m_next = new Node(oth->data);
			node = node->m_next;
			++m_length;
		}
		m_pTail = node;

	} else {
		m_pHead = nullptr;
		m_pTail = nullptr;
		m_length = 0;
	}
	return *this;
}
SLLString& SLLString::operator+=(const SLLString& other) {
	if( other.m_pHead ) {
		if( m_pHead )
			m_pTail->m_next = new Node(other.m_pHead->data);
		else
			m_pHead = m_pTail->m_next = new Node(other.m_pHead->data);

		Node* oth = other.m_pHead;
		Node* node = m_pTail->m_next;
		++m_length;

		while( oth->m_next ) {
			oth = oth->m_next;

			node->m_next = new Node(oth->data);
			node = node->m_next;
			++m_length;
		}
		m_pTail = node;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const SLLString& other) {
	Node* ptr = other.m_pHead;

	while( ptr ) {
		os << ptr->data;
		ptr = ptr->m_next;
	}

	return os;
}

// Get character at index n
char& SLLString::operator[](const int n) {
	if( n > m_length || n < 0 )
		throw std::out_of_range("Length out of range.");

	Node* cur = m_pHead;

	for( int i = 0; i < n; ++i )
		cur = cur->m_next;

	return cur->data;
}

// Get the length of this string
int SLLString::length( ) {
	return m_length;
}

// Find the index of the first occurrence of substring in the current string.
// Returns - 1 if not found
int SLLString::findSubstring(const std::string substring) {
	if( substring.length( ) > 0 ) {
		Node* ptr = m_pHead;
		int index = 0;
		while( ptr ) {
			if( ptr->data == substring[0] ) {
				if( substring.length( ) == 1 )
					return index;
				int substringIndex = 1;
				Node* cur = ptr->m_next;
				while( cur && substringIndex >= 0 && substringIndex < substring.length( ) ) {
					if( substring[substringIndex++] != cur->data )
						substringIndex = -1;
					cur = cur->m_next;
				}
				if( substringIndex == substring.length( ) )
					return index;
			}
			++index;
			ptr = ptr->m_next;
		}
	}

	return -1;
}

// Erase all occurrences of character c from the current string
void SLLString::erase(char c) {
	if( m_length > 0 ) {
		Node* prev = nullptr;
		Node* cur = m_pHead;

		while( cur ) {
			if( cur->data == c ) {
				--m_length;
				if( cur == m_pHead ) {
					m_pHead = cur->m_next;
					cur->m_next = nullptr;
				} else if( cur == m_pTail ) {
					m_pTail = prev;
					m_pTail->m_next = nullptr;
				} else {
					prev->m_next = cur->m_next;
				}
			}
			prev = cur;
			cur = cur->m_next;
		}
	}
}

#endif