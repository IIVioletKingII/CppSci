#include <iostream>
#include <string>

template <class T>
class DynamicArray {
	public:
		DynamicArray(int size)
				: m_data(new T[size]) {
			m_size = size;
			m_firstEmptyElement = 0;
		}
		~DynamicArray( ) {
			delete[] m_data;
		}

		/**
		 * @brief adds a new item to the array
		 *
		 * @param data
		 */
		void add(T data) {
			try {
				if( m_firstEmptyElement < m_size ) {
					m_data[m_firstEmptyElement++] = data;
				} else {
					increaseArraySize( );
					add(data);
					// throw m_firstEmptyElement;
				}
			} catch( int m_firstEmptyElement ) {
				// std::cout << "Index " << m_firstEmptyElement << " is out of bounds." << std::endl;
			}
		}

		/**
		 * @brief Returns the size of the used portion of the array
		 *
		 * @return int
		 */
		int size( ) {
			return m_firstEmptyElement;
		}

		/**
		 * @brief throws out_of_range exception if index is greater than the size() of the array
		 *
		 * @param index to remove from array
		 */
		void removeByElement(int index) {
			if( index < m_firstEmptyElement ) {
				for( int i = index + 1; i < m_firstEmptyElement; ++i )
					m_data[i - 1] = m_data[i];

				--m_firstEmptyElement;

				if( m_firstEmptyElement < m_size - (2 * m_sizeChange) )
					decreaseArraySize( );

			} else {
				throw std::out_of_range("Index " + std::to_string(index) + " is out of bounds.");
			}
		}

		/**
		 * @brief returns the nth index item of the array
		 *
		 * @param index
		 * @return nth element of type T
		 */
		T getByElement(int index) {
			if( index < m_firstEmptyElement )
				return m_data[index];

			throw std::out_of_range("Index " + std::to_string(index) + " is out of bounds.");
		}

		/**
		 * @brief increases the virtual size of the array for new items
		 *
		 */
		void increaseArraySize( ) {
			T* largerArray(new T[m_size + m_sizeChange]);
			for( int i = 0; i < m_size; i++ ) {
				largerArray[i] = m_data[i];
			}
			delete[] m_data;
			m_data = largerArray;
			largerArray = NULL;
			m_size += m_sizeChange;
		}

		/**
		 * @brief reduces the virtual size of the array to save memory
		 *
		 */
		void decreaseArraySize( ) {
			T* smallerArray(new T[m_size - m_sizeChange]);
			for( int i = 0; i < m_size; i++ ) {
				smallerArray[i] = m_data[i];
			}
			delete[] m_data;
			m_data = smallerArray;
			smallerArray = NULL;
			m_size -= m_sizeChange;
		}

	private:
		T* m_data;
		int m_size;
		int m_sizeChange = 5;
		int m_firstEmptyElement;
};

/*
When you increased the size of the array,
how much did you increase it by and why did you choose to increase it by that amount?

* I increase the size of the array when space is needed by 5 as to not take up too much memory.
* If I were expanding the class further I'd give more options to change the increase size or add multiple items.

When you decreased the size of the array,
how much did you decrease it by and why did you choose to decrease it by that amount?

* I decrease the size of the array by 5 when there are more than 10 unused elements of the array to leave a buffer of 5.


*/