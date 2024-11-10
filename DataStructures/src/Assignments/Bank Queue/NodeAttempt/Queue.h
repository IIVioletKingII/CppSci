/**
 * @file Queue.h
 */

#ifndef QUEUE_H
#define QUEUE_H

#include "QueueADT.h"

/**
 * @brief a company bank teller line (queue)
 *
 * @tparam T
 */
template <class T>
class Queue : public QueueADT<T> {
	public:
		void enqueue(const T& input);
		T& dequeue( );
		T& peek( );
		void print( );
		bool isEmpty( );
		bool isFull( );

	private:
		~Queue( );
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

#include "Queue.cpp"

#endif // QUEUE_H
