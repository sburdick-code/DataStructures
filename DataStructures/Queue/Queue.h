#ifndef QUEUE_H
#define QUEUE_H

#include <new>
#include "../Node/Node.h"

template <typename TYPE>
class Queue
{

private:
	Node<TYPE>* front;
	Node<TYPE>* rear;
	int numValues;

public:
	Queue();
	~Queue();
	bool enqueue(const TYPE & dataIn);
	bool dequeue(TYPE & dataOut);
	bool viewFront(TYPE & dataOut) const;
	bool viewRear(TYPE & dataOut) const;
	int getNumValues();
	bool isFull();
	bool isEmpty();

};

template <typename TYPE>
Queue<TYPE>::Queue()
{
	front = nullptr;
	rear = nullptr;
	numValues = 0;
}

template<typename TYPE>
Queue<TYPE>::~Queue()
{
	Node<TYPE>* pDelete;

	while (front)
	{
		pDelete = front;
		front = front->next;
		delete pDelete;
	}

	front = nullptr;
	numValues = 0;
}

template <typename TYPE>
bool Queue<TYPE>::enqueue(const TYPE& dataIn)
{
	bool success = false;
	Node<TYPE>* pNew;

	pNew = new (nothrow) Node<TYPE>(dataIn);

	if (pNew)
	{
		if (front)
			rear->next = pNew;
		else
			front = pNew;
			
		rear = pNew;
		numValues++;
		success = true;
	}
	

	return success;
}

template <typename TYPE>
bool Queue<TYPE>::dequeue(TYPE& dataOut)
{
	bool success = false;
	Node<TYPE>* pDelete = front;

	if (front)
	{
		dataOut = front->data;
		front = front->next;
		delete pDelete;
		numValues--;
		success = true;

		if (!front)
			rear = nullptr;
	}

	return success;
}

template <typename TYPE>
bool Queue<TYPE>::viewFront(TYPE& dataOut) const
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
bool Queue<TYPE>::viewRear(TYPE& dataOut) const
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
int Queue<TYPE>::getNumValues()
{
	return numValues;
}

template <typename TYPE>
bool Queue<TYPE>::isFull()
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

template <typename TYPE>
bool Queue<TYPE>::isEmpty()
{
	return (numValues <= 0);
}

#endif