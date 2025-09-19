#ifndef CHASHTABLE_H
#define CHASHTABLE_H

#include <new>
#include "../LList/OrderedList.h"

template <typename TYPE>
class CHashTable
{
private:
	OrderedList<TYPE>* table;
	int capacity;
	
public:
	CHashTable(int c = 25);
	~CHashTable();
	bool insert(const TYPE& dataIn);
	bool remove(TYPE& dataOut);
	bool retrieve(TYPE& dataOut) const;
	void display();

private:
	int hashFunction(const TYPE& data) const;

};

template <typename TYPE>
CHashTable<TYPE>::CHashTable(int c)
{
	capacity = c;
	table = new OrderedList<TYPE>[capacity];
}

template <typename TYPE>
CHashTable<TYPE>::~CHashTable()
{
	capacity = 0;
	delete[] table;
	table = nullptr;
}

template <typename TYPE>
bool CHashTable<TYPE>::insert(const TYPE& dataIn)
{
	bool success = false;
	int key = hashFunction(dataIn);

	if (table[key].insert(dataIn))
		success = true;
	
	return success;
}

template <typename TYPE>
bool CHashTable<TYPE>::remove(TYPE& dataOut)
{
	bool success = false;
	int key = hashFunction(dataOut);

	if (table[key].remove(dataOut))
		success = true;

	return success;
}

template <typename TYPE>
bool CHashTable<TYPE>::retrieve(TYPE& dataOut) const
{
	bool success = false;
	int key = hashFunction(dataOut);

	if (table[key].retrieve(dataOut))
		success = true;

	return success;
}

template <typename TYPE>
void CHashTable<TYPE>::display()
{
	for (int i = 0; i < capacity; i++)
	{
		cout << "[" << i << "]";
		table[i].display();
	}
	cout << endl;
}

template <typename TYPE>
int CHashTable<TYPE>::hashFunction(const TYPE& data) const
{
	return (data % capacity);
}

#endif