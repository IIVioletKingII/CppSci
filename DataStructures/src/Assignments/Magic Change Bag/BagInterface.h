/**
 * @file BagInterface.h
 */

#ifndef BAGINTERFACE_H
#define BAGINTERFACE_H

#include <iostream>

using namespace std;
/**
 * @brief interface: a bag that contain 20 some-type T items
 *
 * @tparam T
 */
template <class T>
class BagInterface {
	public:
		/**
		 * @brief Destroys the Bag
		 *
		 */
		virtual ~BagInterface( ) {}

		/**
		 * @brief Inserts an item into the bag
		 *
		 * @returns True if the operation is successful (if the bag has space for the item), else otherwise
		 */
		virtual bool insert(const T& item) = 0;

		/**
		 * @brief removes the fitst occurence of item from the bag
		 *
		 * @returns True if the operation is successful (the item was found in and removed from the bag), else otherwise
		 */
		virtual bool remove(const T& item) = 0;

		/**
		 * @brief looks for the item in the bag
		 *
		 * @returns True if the item is found, else otherwise
		 */
		virtual bool query(const T& item) = 0;

		/**
		 * @brief counts the number of `item` in the bag
		 *
		 * @returns The number of `item` in the bag
		 */
		virtual int itemCount(const T& item) = 0;

		/**
		 * @brief Empties the bag
		 *
		 */
		virtual void empty( ) = 0;

		/**
		 * @brief counts the number of items in the bag
		 *
		 * @returns The number of items in the bag
		 */
		virtual int size( ) = 0;

		/**
		 * @brief checks if the bag is empty
		 *
		 * @returns True if the bag is empty, else otherwise
		 */
		virtual bool isEmpty( ) = 0;

		/**
		 * @brief checks if the bag is full
		 *
		 * @returns True if the bag is full, else otherwise
		 */
		virtual bool isFull( ) = 0;

		/**
		 * @brief prints the contents of the bag
		 *
		 */
		virtual void print( ) = 0;

		const int capacity = 20;
};
#endif // BAGINTERFACE_H
