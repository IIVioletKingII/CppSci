#ifndef SLLSTRING_H
#define SLLSTRING_H

#include <iostream>
#include <string>
#include "Node.h"

/**
 * @brief A String class made up of a singly-linked-list
 *
 */
class SLLString {
	public:
		/**
		 * @brief Constructs an empty SLLString
		 */
		SLLString( );

		/**
		 * @brief Constructs a SLLString from a string
		 */
		SLLString(const std::string& other);

		/**
		 * @brief Constructs a SLLString from another SLLString
		 */
		SLLString(const SLLString& other);

		/**
		 * @brief Decstructs a SLLString
		 */
		~SLLString( );

		SLLString& operator=(const SLLString& other);
		SLLString& operator+=(const SLLString& other);
		friend std::ostream& operator<<(std::ostream& os, const SLLString& other);

		/**
		 * @brief Get character at index n
		 */
		char& operator[](const int n);

		/**
		 * Get the length of this string
		 */
		int length( );

		/**
		 * @brief Find the index of the first occurrence of substring in the current string.
		 * @returns -1 if not found
		 */
		int findSubstring(const std::string substring);

		/**
		 * @brief Erase all occurrences of character c from the current string
		 */
		void erase(char c);

	private:
		Node* m_pHead;
		Node* m_pTail;
		int m_length;
};

#endif