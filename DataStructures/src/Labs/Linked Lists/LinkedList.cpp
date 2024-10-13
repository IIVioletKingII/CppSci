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

		/**
		 * @brief adds a new node at the end of the list with the passed in data
		 *
		 * @param data
		 */
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

		/**
		 * @brief returns the node object at the nth index
		 *
		 * @param index
		 * @return Node<T>*
		 */
		Node<T>* findNodeByIndex(int index) {
			Node<T>* currentNode = m_head;

			if( index == m_size )
				return m_tail;

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
				if( currentNode->getData( ) == value ) {
					return currentNode;
				}
				if( currentNode->getNext( ) != 0 ) {
					currentNode = currentNode->getNext( );
				}
			}

			return 0;
		}

		/**
		 * @brief Get the item at the nth index
		 *
		 * @param index
		 * @return T
		 */
		T getByIndex(int index) {
			return findNodeByIndex(index)->getData( );
		}

		/**
		 * @brief deletes the nth index of the list
		 *
		 * @param index
		 */
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
		 * @brief removes all occurences of value in list
		 *
		 * @param value
		 */
		void deleteByValue(T value) {
			if( m_size > 0 ) {
				Node<T>* previousNode = m_head;
				if( m_head->getData( ) == value ) {
					m_head = m_head->getNext( );
					m_size--;
				}
				while( previousNode->getNext( ) != 0 ) {
					if( previousNode->getNext( )->getData( ) == value ) {
						if( previousNode->getNext( ) == m_tail ) {
							previousNode->setNext(0);
							m_tail = previousNode;
						} else if( previousNode->getNext( ) == m_head ) {
							m_head = previousNode->getNext( )->getNext( );
						} else {
							previousNode->setNext(previousNode->getNext( )->getNext( ));
						}
						m_size--;
					} else
						previousNode = previousNode->getNext( );
				}
			}
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