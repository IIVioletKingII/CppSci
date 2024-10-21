/**
 * @file SLLString.cpp
 * @author Sam DePoule
 */

#ifndef SLLSTRING_CPP
#define SLLSTRING_CPP

#include "SLLString.h"
#include <iostream>
#include <string>

SLLString::SLLString( ) {
	m_pHead = nullptr;
	m_pTail = nullptr;
}

SLLString::SLLString(const std::string& other) {
	m_pHead = new Node(other[0]);
	Node* node = m_pHead;

	for( int i = 1; i < other.length( ); ++i ) {
		node->m_next = new Node(other[i]);
		node = node->m_next;
	}
	m_pTail = node;
}

SLLString::SLLString(const SLLString& other) {
	if( other.m_pHead ) {
		m_pHead = new Node(other.m_pHead->data);
		Node* oth = other.m_pHead;
		Node* node = m_pHead;

		while( oth.next ) {
			oth = oth->m_next;

			node->m_next = new Node(oth->data);
			node = node->m_next;
		}
		m_pTail = node;

	} else {
		m_pHead = nullptr;
		m_pTail = nullptr;
	}
}

SLLString::~SLLString( ) {
}


SLLString& SLLString::operator=(const SLLString& other) {
	return *this;
}
SLLString& SLLString::operator+=(const SLLString& other) {
	return *this;
}

std::ostream& operator<<(std::ostream& os, const SLLString& other) {
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
	return -1;
}

// Find the index of the first occurrence of substring in the current string.
// Returns - 1 if not found
int SLLString::findSubstring(const std::string substring) {
	return -1;
}

// Erase all occurrences of character c from the current string
void SLLString::erase(char c) {
}

#endif