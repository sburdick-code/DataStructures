#ifndef UNORDEREDLIST_H
#define UNORDEREDLIST_H

#include <new>
#include "../Node/Node.h"

template <typename TYPE>
class UnorderedList
{
	private:
		Node<TYPE>* front;

	public:
		// Constructors
		UnorderedList();
		UnorderedList(const int n);  // Construct a list to contain n elements (set to 0)
		UnorderedList(const int n, const TYPE & initData);  // Construct a list to contain n copies of initData
		UnorderedList(TYPE* pFirst, TYPE* pLast);  // Construct a list to contain copies of elements in memory locations pFirst up to pLast

		// Destructor
		~UnorderedList();

		// Class Methods
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
UnorderedList<TYPE>::UnorderedList()
{
	front = nullptr;
}

template <typename TYPE>
UnorderedList<TYPE>::UnorderedList(const int n)
{
	int initData = 0;
	Node<TYPE>* pAfter = nullptr;
	Node<TYPE>* pNew;

	for (int i = 0; i < n; i++)
	{
		pNew = new (nothrow) Node<TYPE>(initData, pAfter);

		if (pNew)
			pAfter = pNew;
	}

	front = pAfter;
}

template <typename TYPE>
UnorderedList<TYPE>::UnorderedList(const int n, const TYPE& initData)
{
	Node<TYPE>* pAfter = nullptr;
	Node<TYPE>* pNew;

	for (int i = 0; i < n; i++)
	{
		pNew = new (nothrow) Node<TYPE>(initData, pAfter);

		if (pNew)
			pAfter = pNew;
	}

	front = pAfter;
}

template <typename TYPE>
UnorderedList<TYPE>::UnorderedList(TYPE* pFirst, TYPE* pLast)
{
	Node<TYPE>* pNew;
	Node<TYPE>* pBefore = nullptr;

	for (TYPE* p = pFirst; p != pLast; ++p)
	{
		pNew = new (nothrow) Node<TYPE>(*p);

		if (pNew)
		{
			if (pBefore)
				pBefore->next = pNew;
			else
				front = pNew;

			pBefore = pNew;
		}
	}
}

template <typename TYPE>
UnorderedList<TYPE>::~UnorderedList()
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
bool UnorderedList<TYPE>::insert(const TYPE& dataIn)
{
	bool success = false;
	Node<TYPE>* pAfter = front;
	Node<TYPE>* pNew;

	while ( (pAfter) && (pAfter->next) )
	{
		pAfter = pAfter->next;
	}

	pNew = new (nothrow) Node<TYPE>(dataIn);

	if (pNew)
	{
		if (!front)
			front = pNew;
		else
			pAfter->next = pNew;

		success = true;
	}

	return success;
}

template <typename TYPE>
bool UnorderedList<TYPE>::remove(TYPE& dataOut)
{
	bool success = false;
	Node<TYPE>* pBefore = nullptr;
	Node<TYPE>* pAfter = front;

	while ( (pAfter) && (pAfter->data != dataOut) )
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
bool UnorderedList<TYPE>::retrieve(TYPE& dataOut) const
{
	bool success = false;
	Node<TYPE>* pTemp = front;

	while ( (pTemp) && (pTemp->data != dataOut) )
	{
		pTemp = pTemp->next;
	}

	if ( (pTemp) && (pTemp->data == dataOut) )
	{
		dataOut = pTemp->data;
		success = true;
	}

	return success;
}

template <typename TYPE>
bool UnorderedList<TYPE>::viewFront(TYPE& dataOut) const
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
bool UnorderedList<TYPE>::viewRear(TYPE& dataOut) const
{
	bool success = false;
	Node<TYPE>* pTemp = front;

	while ( (pTemp) && (pTemp->next) )
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
void UnorderedList<TYPE>::display() const
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
int UnorderedList<TYPE>::getNumValues() const
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
bool UnorderedList<TYPE>::isEmpty() const
{
	return (!front);
}

template <typename TYPE>
bool UnorderedList<TYPE>::isFull() const
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