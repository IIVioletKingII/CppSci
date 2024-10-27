#ifndef NODE_H
#define NODE_H

#include <string>

class Node {
	public:
		Node( ) {
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