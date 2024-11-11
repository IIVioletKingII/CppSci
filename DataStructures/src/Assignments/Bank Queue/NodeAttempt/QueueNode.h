/**
 * @file Queue.h
 */

#ifndef QUEUE_NODE_H
#define QUEUE_NODE_H

#include "QueueADT.h"

/**
 * @brief a company bank teller line (queue)
 *
 * @tparam T
 */
template <class T>
class QueueNode : public QueueADT<T> {
	public:
		Queue( );
		~Queue( );
		void enqueue(const T& input);
		T& dequeue( );
		T& peek( );
		void print( );
		bool isEmpty( );
		bool isFull( );

	private:
		class Node {
			public:
				Node(T* data) {
					m_data = data;
					m_next = nullptr;
				};
				T* m_data;
				Node* m_next;
		};
		int m_length;
		Node* m_front;
		Node* m_back;
};

#include "QueueNode.cpp"

#endif // QUEUE_NODE_H
