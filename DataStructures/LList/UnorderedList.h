/*
 * This file is part of DataStructures.sln.
 * Developed for educational purposes.
 * This program is free software: you can redistribute it and/or modify it.
 *
 * This program is used to create an Ubnordered Linked List, its data, and its
 * member functions.
 *
 */

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
		bool pushFront(const TYPE & dataIn);
		bool pushBack(const TYPE & dataIn);
		bool insert(const int pos, const TYPE & dataIn);
		bool popFront(TYPE & dataOut);
		bool popBack(TYPE & dataOut);
		bool remove(TYPE & dataOut);
		bool retrieve(TYPE & dataOut) const;
		bool viewFront(TYPE & dataOut) const;
		bool viewRear(TYPE & dataOut) const;
		void display() const;
		int getNumValues() const;
		bool isEmpty() const;
		bool isFull() const;
		bool merge(UnorderedList & mergeList);
};

/**
 * Initializes the Unordered Linked List.
 */
template <typename TYPE>
UnorderedList<TYPE>::UnorderedList()
{
	front = nullptr;
}

/**
 * Construct a list to contain n elements (set to 0)
 * 
 * @param n The number of elments to initialize into the list.
 */
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

/**
* Construct a list to contain n copies of initData.
* 
* @param n The number of elments to initialize into the list.
* @param initData The data to be added to the linked list n times.
*/
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

/**
* Construct a list to contain copies of elements in memory locations pFirst up to pLast.
* 
* @param pFirst The first memory location.
* @param pLast The last memory location.
*/
template <typename TYPE>
UnorderedList<TYPE>::UnorderedList(TYPE* pFirst, TYPE* pLast)
{
	Node<TYPE>* pNew;
	Node<TYPE>* pBefore = nullptr;

	for (TYPE* p = pFirst; p <= pLast; ++p)
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

/**
 * Destructor for the Unordered Linked List.
 */
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

/**
 * Inserts data as the first element into the Linked List.
 *
 * @param dataIn The data being inserted.
 * @return Returns true if successful, false if the data could not be inserted.
 */
template <typename TYPE>
bool UnorderedList<TYPE>::pushFront(const TYPE& dataIn)
{
	bool success = false;
	Node<TYPE>* pNew;
	pNew = new (nothrow) Node<TYPE>(dataIn, front);

	if (pNew)
	{
		front = pNew;
		success = true;
	}

	return success;
}

/**
 * Inserts data as the last element into the Linked List.
 *
 * @param dataIn The data being inserted.
 * @return Returns true if successful, false if the data could not be inserted.
 */
template <typename TYPE>
bool UnorderedList<TYPE>::pushBack(const TYPE& dataIn)
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

/**
 * Inserts data into the Linked List in the specified position.
 *
 * @param pos The index location of the data to be inserted. If out of range, insert at the end.
 * @param dataIn The data being inserted.
 * @return Returns true if successful, false if the data could not be inserted.
 */
template <typename TYPE>
bool UnorderedList<TYPE>::insert(const int pos, const TYPE& dataIn)
{
	bool success = false;
	Node<TYPE>* pBefore = nullptr;
	Node<TYPE>* pAfter = front;
	Node<TYPE>* pNew;

	for (int i = 0; i < pos && pAfter; i++)
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

/**
 * Removes the first item from the Linked List.
 *
 * @param dataOut The data being removed.
 * @return Returns true if successful, false if the data could not be inserted.
 */
template <typename TYPE>
bool UnorderedList<TYPE>::popFront(TYPE& dataOut)
{
	bool success = false;
	Node<TYPE>* pDelete = front;
	
	if (pDelete)
	{
		dataOut = front->data;
		front = front->next;
		delete pDelete;
		success = true;
	}

	return success;
}

/**
 * Removes the last item from the Linked List.
 *
 * @param dataOut The data being removed.
 * @return Returns true if successful, false if the data could not be inserted.
 */
template <typename TYPE>
bool UnorderedList<TYPE>::popBack(TYPE& dataOut)
{
	bool success = false;
	Node<TYPE>* pBefore = nullptr;
	Node<TYPE>* pDelete = front;

	while (pDelete && pDelete->next)
	{
		pBefore = pDelete;
		pDelete = pDelete->next;
	}

	if (pDelete)
	{
		dataOut = pDelete->data;

		if (pBefore)
			pBefore->next = nullptr;
		else
			front = nullptr;

		delete pDelete;
		success = true;
	}

	return success;
}

/**
 * Removes the specified data from the Linked List.
 *
 * @param dataOut The data being removed.
 * @return Returns true if successful, false if the data could not be inserted.
 */
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

/**
 * Finds specified data into the linked list, but does not remove it.
 *
 * @param dataOut The data searched for.
 * @return Returns true if successful, false if the data could not be found.
 */
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

/**
 * Finds front element of the linked list, but does not remove it.
 *
 * @param dataOut The data searched for.
 * @return Returns true if successful, false if the data could not be found.
 */
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

/**
 * Finds last element of the linked list, but does not remove it.
 *
 * @param dataOut The data searched for.
 * @return Returns true if successful, false if the data could not be found.
 */
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

/**
 * Nicely prints out the contents of the linked list in a human readable format.
 */
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

/**
* Returns the number of elements in the linked list.
*
* @return Returns number of elements
*/
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

/**
* Determines if the linked list has elements or not.
*
* @return Returns true if empty
*/
template <typename TYPE>
bool UnorderedList<TYPE>::isEmpty() const
{
	return (!front);
}

/**
* Determines if the linked list can store another value.
*
* @return Returns true if no more space to store an element.
*/
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

/**
* Merge another unordered linked list into this one.
* 
* @return Returns true if the merge was successful
*/
template <typename TYPE>
bool UnorderedList<TYPE>::merge(UnorderedList& mergeList)
{
	bool success = false;
	int numElements = mergeList.getNumValues();
	Node<TYPE>* pTemp = front;
	Node<TYPE>* pNew;
	TYPE data;

	while (pTemp && pTemp->next)
	{
		pTemp = pTemp->next;
	}

	for (int i = 0; i < numElements; i++)
	{
		if (mergeList.popFront(data))
		{
			pNew = new (nothrow) Node<TYPE>(data);

			if (pNew)
			{
				if (pTemp)
					pTemp->next = pNew;
				else
					front = pNew;

				pTemp = pNew;
				success = true;
			}
			else
				success = false;  // TODO: may be good to add a way to save the mergeList, this way if an error occurs it isn't destructive to the data.
		}
	}

	return success;
}

#endif