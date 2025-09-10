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

template <typename TYPE>
int CircularList<TYPE>::getNumValues() const
{
	return (int(front->data));
}

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