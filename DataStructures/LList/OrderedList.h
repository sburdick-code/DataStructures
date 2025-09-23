/*
 * This file is part of DataStructures.sln.
 * Developed for educational purposes.
 * This program is free software: you can redistribute it and/or modify it.
 *
 * This program is used to create an Ordered Linked List, its data, and its
 * member functions.
 *
 */

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

/**
 * Initializes the Ordered Linked List.
 */
template <typename TYPE>
OrderedList<TYPE>::OrderedList()
{
	front = nullptr;
}

/**
 * Destructor for the Doubly Linked List.
 */
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

/**
 * Inserts an item into the Linked List.
 *
 * @param dataIn The data being inserted.
 * @return Returns true if successful, false if the data could not be inserted.
 */
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

/**
 * Removes an item from the Linked List.
 *
 * @param dataOut The data being removed.
 * @return Returns true if successful, false if the data could not be inserted.
 */
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

/**
 * Finds specified data into the linked list, but does not remove it.
 *
 * @param dataOut The data searched for.
 * @return Returns true if successful, false if the data could not be found.
 */
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

/**
 * Finds the first element of the linked list, but does not remove it.
 *
 * @param dataOut The data searched for.
 * @return Returns true if successful, false if the data could not be found.
 */
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

/**
 * Finds the last element of the linked list, but does not remove it.
 *
 * @param dataOut The data searched for.
 * @return Returns true if successful, false if the data could not be found.
 */
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

/**
 * Nicely prints out the contents of the list in a human readable format.
 */
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

/**
* Returns the number of elements in the linked list.
*
* @return Returns number of elements
*/
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

/**
* Determines if the linked list has elements in it.
*
* @return Returns true if empty
*/
template <typename TYPE>
bool OrderedList<TYPE>::isEmpty() const
{
	return (!front);
}

/**
* Determines if the linked list can store another value.
*
* @return Returns true if no more space to store an element.
*/
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