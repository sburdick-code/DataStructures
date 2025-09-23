/*
 * This file is part of DataStructures.sln.
 * Developed for educational purposes.
 * This program is free software: you can redistribute it and/or modify it.
 *
 * This program is used to create a Circular Linked List, its data, and its
 * member functions.
 *
 */

#ifndef CIRCULARLIST_H
#define CIRCULARLIST_H

#include "../Node/Node.h"

template <typename TYPE>
class CircularList
{
private:
	Node<TYPE>* front;

public:
	CircularList();
	~CircularList();
	bool pushFront(const TYPE& dataIn);
	bool pushBack(const TYPE& dataIn);
	bool insert(const int pos, const TYPE& dataIn);
	bool remove(TYPE& dataOut);
	bool retrieve(TYPE& dataOut) const;
	void display() const;
	int getNumValues() const;
	bool isEmpty() const;
	bool isFull() const;
	
};

/**
 * Initializes the Circular Linked List.
 */
template <typename TYPE>
CircularList<TYPE>::CircularList()
{
	Node<TYPE>* pHeadNode;
	pHeadNode = new (nothrow) Node<TYPE>;

	if (pHeadNode)
	{
		front = pHeadNode;
		pHeadNode->next = pHeadNode;
	}
}

/**
 * Destructor for the Ciircular Linked List.
 */
template <typename TYPE>
CircularList<TYPE>::~CircularList()
{
	Node<TYPE>* pDelete = front->next;
	front->next = nullptr;
	front = pDelete;

	while (front)
	{
		pDelete = front;
		front = front->next;
		delete pDelete;
	}
}

/**
 * Inserts an item into the first element of the Linked List.
 *
 * @param dataIn The data being inserted.
 * @return Returns true if successful, false if the data could not be inserted.
 */
template <typename TYPE>
bool CircularList<TYPE>::pushFront(const TYPE& dataIn)
{
	bool success = false;
	Node<TYPE>* pAfter = front->next;
	Node<TYPE>* pNew;

	pNew = new (nothrow) Node<TYPE>(dataIn, pAfter);

	if (pNew)
	{
		front->next = pNew;
		front->data++;
		success = true;
	}

	return success;
}

/**
 * Inserts data into the last element of the Linked List.
 *
 * @param dataIn The data being inserted.
 * @return Returns true if successful, false if the data could not be inserted.
 */
template <typename TYPE>
bool CircularList<TYPE>::pushBack(const TYPE& dataIn)
{
	bool success = false;
	Node<TYPE>* pBefore = front;
	Node<TYPE>* pNew;

	do {
		pBefore = pBefore->next;
	} while (pBefore->next != front);

	pNew = new (nothrow) Node<TYPE>(dataIn, front);

	if (pNew)
	{
		pBefore->next = pNew;
		front->data++;
		success = true;
	}

	return success;
	
}

/**
 * Inserts data into the Linked List.
 *
 * @param dataIn The data being inserted.
 * @return Returns true if successful, false if the data could not be inserted.
 */
template <typename TYPE>
bool CircularList<TYPE>::insert(const int pos, const TYPE& dataIn)
{
	bool success = false;
	Node<TYPE>* pBefore = front;
	Node<TYPE>* pNew;

	for (int i = 0; ((i < pos) && (pBefore->next != front)); i++)
	{
		pBefore = pBefore->next;
	}

	pNew = new (nothrow) Node<TYPE>(dataIn, pBefore->next);

	if (pNew)
	{
		pBefore->next = pNew;
		front->data++;
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
bool CircularList<TYPE>::remove(TYPE& dataOut)
{
	bool success = false;
	Node<TYPE>* pBefore;
	Node<TYPE>* pDelete = front;

	do {
		pBefore = pDelete;
		pDelete = pDelete->next;
	} while ((pDelete->data != dataOut) && (pDelete != front));

	if (pDelete->data == dataOut)
	{
		pBefore->next = pDelete->next;
		delete pDelete;
		front->data--;
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
bool CircularList<TYPE>::retrieve(TYPE& dataOut) const
{
	bool success = false;
	Node<TYPE>* pTemp = front;

	do {
		pTemp = pTemp->next;
	} while ((pTemp->data != dataOut) && (pTemp != front));

	if (pTemp->data == dataOut)
	{
		dataOut = pTemp;
		success = true;
	}

	return success;
}

/**
 * Nicely prints out the contents of the linked list in a human readable format.
 */
template <typename TYPE>
void CircularList<TYPE>::display() const
{
	Node<TYPE>* pTemp = front->next;

	while (pTemp != front)
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
int CircularList<TYPE>::getNumValues() const
{
	return (int(front->data));
}

/**
* Determines if the linked list has elements or not.
*
* @return Returns true if empty
*/
template <typename TYPE>
bool CircularList<TYPE>::isEmpty() const
{
	bool empty = true;
	if (front)
	{
		if (front->next != front)
			empty = false;
	}

	return (empty);
}

/**
* Determines if the linked list can store another value.
*
* @return Returns true if no more space to store an element.
*/
template <typename TYPE>
bool CircularList<TYPE>::isFull() const
{
	bool full = true;
	Node<TYPE>* pTemp;
	pTemp = new (nothrow) Node<TYPE>;

	if (pTemp)
	{
		delete pTemp;
		full = false;
	}

	return full;
}



#endif