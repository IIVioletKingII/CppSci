//
// Created by gordon.gul on 10/17/2024.
// Modfied by sam.depoule on 10/20/2024.
//

#ifndef STACK_H
#define STACK_H

/**
 * @brief ADT Stack implementation
 *
 * @tparam T
 */
template <class T>
class Stack {
	public:
		/**
		 * @brief Creates a new Stack
		 *
		 */
		Stack( );
		~Stack( );

		/**
		 * @brief adds `tempData` to the top of the stack
		 *
		 * @param tempData
		 */
		void push(T tempData);

		/**
		 * @brief Removes the item at the top of the stack
		 *
		 * @return T, the item at the top of the stack
		 */
		T pop( );

		/**
		 * @brief returns the item at the top of the stack
		 *
		 * @return T, item at the top of the stack
		 */
		T peek( ) { return m_pTop->m_data; }

		/**
		 * @brief determines if the stack is empty
		 *
		 * @return true if the stack is empty, else otherwise
		 */
		bool isEmpty( ) { return m_pBottom == nullptr; }

		/**
		 * @brief Prints the stack
		 */
		void print( ) {
			std::cout << "B [";
			Node* curPos = m_pBottom;

			while( curPos != nullptr ) {
				std::cout << curPos->m_data;
				if( curPos->m_pNext != nullptr )
					std::cout << " ";
				curPos = curPos->m_pNext;
			}
			std::cout << "] T" << std::endl;
		}

	private:
		class Node {
			public:
				Node(T tempData);

				T m_data;
				Node* m_pPrevious;
				Node* m_pNext;
		};

		Node* m_pTop;		 // Tail
		Node* m_pBottom; // Head
};

#include "Stack.tpp"

#endif // STACK_H