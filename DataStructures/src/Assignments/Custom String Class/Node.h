#ifndef NODE_H
#define NODE_H

/**
 * @brief a singly linked node containing a character
 *
 */
class Node {
	public:
		/**
		 * @brief Construct a null Node
		 */
		Node( ) {
			m_next = nullptr;
		};
		/**
		 * @brief Construct a Node with data
		 */
		Node(char tempData) {
			data = tempData;
			m_next = nullptr;
		};
		char data;
		Node* m_next;
};

#endif