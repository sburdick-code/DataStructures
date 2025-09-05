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

	while ((pAfter) && (pAfter->data < dataIn))
		pAfter = pAfter->next;


	if (pAfter)
		pBefore = pAfter->prev;
	else
		pBefore = rear;

	pNew = new (nothrow) Node<TYPE>(dataIn, pAfter, pBefore);

	if (pNew)
	{
		if (pBefore)
			pBefore->next = pNew;
		else
			front = pNew;

		if (pAfter)
			pAfter->prev = pNew;
		else
			rear = pNew;

		success = true;
	}

	return success;
}

template <typename TYPE>
bool DLList<TYPE>::remove(TYPE& dataOut)
{
	bool success = false;
	Node<TYPE>* pDelete = front;

	while (pDelete && pDelete->data < dataOut)
		pDelete = pDelete->next;


	if (pDelete && pDelete->data == dataOut)
	{
		if (pDelete->prev)
			(pDelete->prev)->next = pDelete->next;
		else
			front = pDelete->next;

		if (pDelete->next)
			(pDelete->next)->prev = pDelete->prev;
		else
			rear = pDelete->prev;

		dataOut = pDelete->data;
		delete pDelete;
		success = true;
	}

	return success;
}

template <typename TYPE>
bool DLList<TYPE>::retrieve(TYPE& dataOut) const
{
	bool success = false;
	Node<TYPE>* pTemp = front;

	while (pTemp && pTemp->data < dataOut)
		pTemp = pTemp->next;

	if (pTemp && pTemp->data == dataOut)
	{
		dataOut = pTemp->data;
		success = true;
	}

	return success;
}

template <typename TYPE>
bool DLList<TYPE>::viewFront(TYPE& dataOut) const
{
	bool success = false;

	if (front)
	{
		dataOut = front->data;
		success = true;
	}

	return success;
}

template <typename TYPE>
bool DLList<TYPE>::viewRear(TYPE& dataOut) const
{
	bool success = false;

	if (rear)
	{
		dataOut = rear->data;
		success = true;
	}

	return success;
}

template <typename TYPE>
void DLList<TYPE>::display() const
{
	Node<TYPE>* pTemp = front;

	while (pTemp)
	{
		cout << pTemp->data << ", ";
		pTemp = pTemp->next;
	}

	cout << endl;
}

template <typename TYPE>
int DLList<TYPE>::getNumValues() const
{
	int numValues = 0;
	Node<TYPE>* pTemp = front;

	while (pTemp)
	{
		numValues++;
		pTemp = pTemp->next;
	}

	return numValues;
}

template <typename TYPE>
bool DLList<TYPE>::isEmpty() const
{
	return (!front);
}

template <typename TYPE>
bool DLList<TYPE>::isFull() const
{
	bool full = true;
	Node<TYPE>* pTemp;
	pTemp = new (nothrow) Node<TYPE>;

	if (pTemp)
	{
		full = false;
		delete pTemp;
	}

	return full;
}

#endif