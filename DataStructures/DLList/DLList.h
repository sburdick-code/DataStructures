#ifndef DLLIST_H
#define LLIST_H

#include <new>
#include "../Node/Node.h"

template <typename TYPE>
class DLList
{

	private:
		Node<TYPE>* front;
		Node<TYPE>* rear;

	public:
		DLList();
		~DLList();
		bool insert(const TYPE & dataIn);
		bool remove(TYPE & dataOut);
		bool retrieve(TYPE & dataOut) const;
		bool viewFront(TYPE & dataOut) const;
		bool viewRear(TYPE & dataOut) const;
		void display() const;
		int getNumValues() const;
		bool isEmpty() const;
		bool isFull() const;

};

template <typename TYPE>
DLList<TYPE>::DLList()
{
	front = nullptr;
	rear = nullptr;
}

template <typename TYPE>
DLList<TYPE>::~DLList()
{
	Node<TYPE>* pDelete;

	while (front)
	{
		pDelete = front;
		front = front->next;
		delete pDelete;
	}

	rear = nullptr;
}

template <typename TYPE>
bool DLList<TYPE>::insert(const TYPE& dataIn)
{
	bool success = false;
	Node<TYPE>* pBefore = nullptr;
	Node<TYPE>* pAfter = front;
	Node<TYPE>* pNew;

	while ((pAfter) && (pAfter->data < dataIn)
		pAfter = pAfter->next;

	if (pAfter)
		pBefore = pAfter->prev;
	else
		pBefore = rear;

	pNew = new (nothrow) Node<TYPE>(dataIn, pAfter, pBefore);

	if (pNew)
	{
		if (pBefore)
			pBefore->next = pnew;
		else
			front = pNew

		if (pAfter)
			pAfter->prev = pNew;
		else
			rear = pNew;

		success = true;
	}

	return success;
}

#endif