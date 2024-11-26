/**
 * @file Hash.h
 */

#ifndef HASH_H
#define HASH_H
#include <string>

template <class Type>
class Hash {
	private:
		class Node {
			public:
				Node(std::string key, Type value);
				Node(Node& otherNode);
				~Node( );
				std::string m_key;
				Type m_value;
				Node* m_pNext;
		};

	public:
		Hash( );
		void insert(std::string key, Type value);
		std::string search(std::string key);

	private:
		float getLoadFactor( );
		void rehashing( );
		int hashFunction(std::string key);

		int m_numberOfElements;
		int m_capacity;
		Node** m_pArray;
};

#include "Hash.cpp"

#endif // HASH_H