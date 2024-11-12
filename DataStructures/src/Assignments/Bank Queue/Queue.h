/**
 * @file Queue.h
 * @author Sam DePoule
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
		Queue(const Queue& queue);
		~Queue( );
		void enqueue(const T& input);
		T& dequeue( );
		T& peek( );
		void print( );
		bool isEmpty( );
		bool isFull( );

	private:
		/**
		 * @brief Shifts the items of the array to index 0
		 */
		void shiftQueue( );
		/**
		 * @brief Set the size of the array and moves the items of the array to index 0
		 *
		 * @param newLength
		 */
		void setSize(int newLength);
		int m_length;
		int m_front;
		int m_back;
		T* m_array;
};

#include "Queue.cpp"

#endif // QUEUE_H
