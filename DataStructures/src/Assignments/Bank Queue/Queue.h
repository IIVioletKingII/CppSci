/**
 * @file Queue.h
 */

#ifndef QUEUE_H
#define QUEUE_H

#include "QueueADT.h"

/**
 * @brief a company bank teller line (queue) of max length 100
 *
 * @tparam T
 */
template <class T>
class Queue : public QueueADT<T> {
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
		void setSize(int newLength);
		int m_length;
		int m_front;
		int m_back;
		T* m_array;
};

#include "Queue.cpp"

#endif // QUEUE_H
