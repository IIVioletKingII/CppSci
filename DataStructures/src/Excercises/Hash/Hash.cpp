/**
 * @file Hash.cpp
 */

#ifndef HASH_CPP
#define HASH_CPP

#include "Hash.h"

template <class Type>
Hash<Type>::Node::Node(std::string key, Type value) {
}

template <class Type>
Hash<Type>::Node::Node(Node& otherNode) {
}

template <class Type>
Hash<Type>::Node::~Node( ) {
}


template <class Type>
Hash<Type>::Hash( ) {
}

template <class Type>
void Hash<Type>::insert(std::string key, Type value) {
}

template <class Type>
std::string Hash<Type>::search(std::string key) {
	return "";
}


template <class Type>
float Hash<Type>::getLoadFactor( ) {
	return -1;
}

template <class Type>
void Hash<Type>::rehashing( ) {
}

template <class Type>
int Hash<Type>::hashFunction(std::string key) {
	return -1;
}


#endif // HASH_CPP