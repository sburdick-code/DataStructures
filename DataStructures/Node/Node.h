#ifndef NODE_H
#define NODE_H

template <typename TYPE>
struct Node
{
	TYPE data;
	Node<TYPE>* next;
	Node<TYPE>* prev;

	Node();
	Node(const TYPE& d, Node<TYPE>* n = nullptr, Node<TYPE>* p = nullptr);
};

template <typename TYPE>
Node<TYPE>::Node()
{
	data = 0;
	next = nullptr;
}

template <typename TYPE>
Node<TYPE>::Node(const TYPE & d, Node<TYPE>* n, Node<TYPE>* p)
{
	data = d;
	next = n;
	prev = p;
}

#endif