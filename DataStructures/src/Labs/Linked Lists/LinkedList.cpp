#include "Node.cpp"

template <class T>
class LinkedList {
	public:
		LinkedList( ) {
			m_head = 0;
			m_tail = 0;
			m_size = 0;
		}

		~LinkedList( ) {
			delete m_head;
		}

		void add(T data) {
			Node<T>* newNode = new Node<T>(data);

			if( m_head == 0 ) {
				m_head = m_tail = newNode;
				m_size++;
			} else {
				m_tail->setNext(newNode);
				m_tail = m_tail->getNext( );
				m_size++;
			}
		}

		Node<T>* findNodeByIndex(int index) {
			Node<T>* currentNode = m_head;

			for( int i = 0; i < index; ++i ) {
				if( currentNode->getNext( ) != 0 ) {
					currentNode = currentNode->getNext( );
				}
			}

			return currentNode;
		}

		/**
		 * @brief finds and returns the node with data equal to value, 0 otherwise
		 *
		 * @param value of the node to find
		 * @return Node<T>* node with data equal to value
		 */
		Node<T>* findNodeByValue(T value) {
			Node<T>* currentNode = m_head;

			for( int i = 0; i < m_size; ++i ) {
				if( currentNode->getNext( ) != 0 ) {
					currentNode = currentNode->getNext( );
				}
			}
			do {
				if( currentNode.getData( ) == value )
					return currentNode;
				currentNode = currentNode->getNext( );

			} while( currentNode != 0 );

			return 0;
		}

		/**
		 * @brief Get the item at index
		 *
		 * @param index
		 * @return T
		 */
		T getByIndex(int index) {
			return findNodeByIndex(index)->getData( );
		}

		void deleteByIndex(int index) {
			Node<T>* precedingNode = findNodeByIndex(index - 1);

			if( index == m_size ) {
				precedingNode->setNext(0);
				m_tail = precedingNode;
			} else if( index > 0 ) {
				precedingNode->setNext(precedingNode->getNext( )->getNext( ));
			} else {
				m_head = m_head->getNext( );
			}

			m_size--;
		}

		/**
		 * @brief removes value if in list
		 *
		 * @param value
		 */
		void deleteByValue(T value) {
			Node<T>* currentNode = m_head;

			do {
				if( currentNode.getData( ) == value ) {
					if( currentNode == m_head )
						m_head = 0;
					else if( currentNode->getNext( )->getNext( ) = 0 )
				}
				currentNode = currentNode->getNext( );

			} while( currentNode != 0 );
		}

		/**
		 * @brief Get the size of the list
		 *
		 * @return the number (int) of objects in the list
		 */
		int getSize( ) {
			return m_size;
		}

	private:
		Node<T>* m_head;
		Node<T>* m_tail;

		int m_size;
};