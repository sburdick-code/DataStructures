#ifndef ORDEREDLIST_H
#define ORDEREDLIST_H

#include <new>
#include "../Node/Node.h"

template <typename TYPE>
class OrderedList
{

	private:
		Node<TYPE>* front;

	public:
		OrderedList();
		~OrderedList();
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
OrderedList<TYPE>::OrderedList()
{
	front = nullptr;
}

template <typename TYPE>
OrderedList<TYPE>::~OrderedList()
{
	Node<TYPE>* pDelete;

	while (front)
	{
		pDelete = front;
		front = front->next;
		delete pDelete;
	}
}

template <typename TYPE>
bool OrderedList<TYPE>::insert(const TYPE& dataIn)
{
	bool success = false;
	Node<TYPE>* pBefore = nullptr;
	Node<TYPE>* pAfter = front;
	Node<TYPE>* pNew;

	while ( (pAfter) && (pAfter->data < dataIn) )
	{
		pBefore = pAfter;
		pAfter = pAfter->next;
	}

	pNew = new (nothrow) Node<TYPE>(dataIn, pAfter);

	if (pNew)
	{
		if (pBefore)
			pBefore->next = pNew;
		else
			front = pNew;

		success = true;
	}

	return success;
}

template <typename TYPE>
bool OrderedList<TYPE>::remove(TYPE& dataOut)
{
	bool success = false;
	Node<TYPE>* pBefore = nullptr;
	Node<TYPE>* pAfter = front;
	
	while ((pAfter) && (pAfter->data < dataOut))
	{
		pBefore = pAfter;
		pAfter = pAfter->next;
	}

	if ( (pAfter) && (pAfter->data == dataOut) )
	{
		dataOut = pAfter->data;

		if (pBefore)
			pBefore->next = pAfter->next;
		else
			front = pAfter->next;

		
		delete pAfter;
		success = true;
	}

	return success;
}

template <typename TYPE>
bool OrderedList<TYPE>::retrieve(TYPE& dataOut) const
{
	bool success = false;
	Node<TYPE>* pTemp = front;

	while ((pTemp) && (pTemp->data < dataOut))
	{
		pTemp = pTemp->next;
	}

	if ((pTemp) && (pTemp->data == dataOut))
	{
		dataOut = pTemp -> data;
		success = true;
	}

	return success;
}

template <typename TYPE>
bool OrderedList<TYPE>::viewFront(TYPE& dataOut) const
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
bool OrderedList<TYPE>::viewRear(TYPE& dataOut) const
{
	bool success = false;
	Node<TYPE>* pTemp = front;

	while ((pTemp) && (pTemp->next))
	{
		pTemp = pTemp->next;
	}

	if (pTemp)
	{
		dataOut = pTemp->data;
		success = true;
	}
	return success;
}

template <typename TYPE>
void OrderedList<TYPE>::display() const
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
int OrderedList<TYPE>::getNumValues() const
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
bool OrderedList<TYPE>::isEmpty() const
{
	return (!front);
}

template <typename TYPE>
bool OrderedList<TYPE>::isFull() const
{
	bool full = true;
	Node<TYPE>* pNew;

	pNew = new (nothrow) Node<TYPE>;

	if (pNew)
	{
		delete pNew;
		full = false;
	}

	return full;
}

#endif