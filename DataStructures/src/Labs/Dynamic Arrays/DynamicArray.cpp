#include <iostream>

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

		void add(T data) {
			try {
				if( m_firstEmptyElement < m_size ) {
					m_data[m_firstEmptyElement] = data;
					m_firstEmptyElement++;
				} else {
					throw m_firstEmptyElement;
				}
			} catch( int m_firstEmptyElement ) {
				std::cout << "Index " << m_firstEmptyElement << " is out of bounds." << std::endl;
			}
		}

		void removeByElement(int index) {
		}

		T getByElement(int index) {
			try {
				if( index < m_size ) {
					return m_data[index];
				} else {
					throw index;
				}
			} catch( int index ) {
				std::cout << "Index " << index << " is out of bounds." << std::endl;
			}
		}

		void increaseArraySize( ) {
		}

		void decreaseArraySize( ) {
		}

	private:
		T* m_data;
		int m_size;
		int m_firstEmptyElement;
};