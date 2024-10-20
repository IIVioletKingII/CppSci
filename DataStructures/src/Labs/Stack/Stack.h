//
// Created by gordon.gul on 10/17/2024.
//

#ifndef STACK_H
#define STACK_H

template <class T>
class Stack
{
    public:
        Stack();
        ~Stack();

        void push(T tempData);
        T pop();
        T peek() { return m_pTop->m_data; }

        bool isEmpty() { return m_pBottom == nullptr; }

    private:
        class Node
        {
            public:
                Node(T tempData);

                T        m_data;
                Node*    m_pPrevious;
                Node*    m_pNext;
        };

        Node*    m_pTop;     // Tail
        Node*    m_pBottom;  // Head
};

#include "Stack.tpp"

#endif // STACK_H