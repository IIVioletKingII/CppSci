#ifndef NODE_H
#define NODE_H

#include <string>

class Node {
	public:
		Node( ) {
			// data = NULL;
			m_next = nullptr;
		};
		Node(char tempData) {
			data = tempData;
			m_next = nullptr;
		};
		char data;
		Node* m_next;
};

#endif