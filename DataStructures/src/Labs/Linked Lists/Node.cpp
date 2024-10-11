template <class T>
class Node
{
	public:

		Node(T data)
		{
			m_data = data;
			m_next = 0;
		}

		T getData() { return m_data;  }
		void setData(T data) { m_data = data; }

		void setNext(Node<T>* next)
		{
			m_next = next;
		}

		Node<T>* getNext()
		{
			return m_next;
		}

	private:
		T m_data;
		Node<T>* m_next;
};