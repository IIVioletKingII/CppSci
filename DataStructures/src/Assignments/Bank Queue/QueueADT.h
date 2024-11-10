// Abstract class that cannot be instantiated
// Template queue class with associated methods
#ifndef QUEUEADT_H
#define QUEUEADT_H
#include <iostream>

using namespace std;

template <class T>
class QueueADT {
	public:
		/**
		 * @brief Add to queue from the back
		 */
		virtual void enqueue(const T&) = 0;
		/**
		 * @brief Remove from queue from the front
		 */
		virtual T& dequeue( ) = 0;
		/**
		 * @brief Returns the value of the front element
		 */
		virtual T& peek( ) = 0;
		/**
		 * @brief Prints out the entire queue
		 */
		virtual void print( ) = 0;
		/**
		 * @brief Check if queue is empty
		 */
		virtual bool isEmpty( ) = 0;
		/**
		 * @brief Check if queue is full
		 */
		virtual bool isFull( ) = 0;
};

#endif