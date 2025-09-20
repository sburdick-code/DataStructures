/*
 * This file is part of DataStructures.sln.
 * Developed for educational purposes.
 * This program is free software: you can redistribute it and/or modify it.
 *
 * This program is used to create a Chained Hash Table, its data, and its 
 * member functions.
 * 
 */

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
		int hashFunction(const int& data) const;
		int hashFunction(const string& data) const;

};

/**
 * Initializes the Chained Hash Table.
 *
 * @param c The initialized capacity of the hash table.
 */
template <typename TYPE>
CHashTable<TYPE>::CHashTable(int c)
{
	capacity = c;
	table = new OrderedList<TYPE>[capacity];
}

/**
 * Destructor for the Chained Hash Table.
 */
template <typename TYPE>
CHashTable<TYPE>::~CHashTable()
{
	capacity = 0;
	delete[] table;
	table = nullptr;
}

/**
 * Inserts an item into the hash table.
 *
 * @param dataIn The data being inserted.
 * @return Returns true if successful, false if the data could not be inserted.
 */
template <typename TYPE>
bool CHashTable<TYPE>::insert(const TYPE& dataIn)
{
	bool success = false;
	int key = hashFunction(dataIn);

	if (table[key].insert(dataIn))
		success = true;
	
	return success;
}

/**
 * Removes specified data into the hash table.
 *
 * @param dataOut The data being removed.
 * @return Returns true if successful, false if the data could not be found.
 */
template <typename TYPE>
bool CHashTable<TYPE>::remove(TYPE& dataOut)
{
	bool success = false;
	int key = hashFunction(dataOut);

	if (table[key].remove(dataOut))
		success = true;

	return success;
}

/**
 * Finds specified data into the hash table, but does not remove it.
 *
 * @param dataOut The data searched for.
 * @return Returns true if successful, false if the data could not be found.
 */
template <typename TYPE>
bool CHashTable<TYPE>::retrieve(TYPE& dataOut) const
{
	bool success = false;
	int key = hashFunction(dataOut);

	if (table[key].retrieve(dataOut))
		success = true;

	return success;
}

/**
 * Nicely displayes the contents of the hash table in a human readable format.
 */
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

/**
 * Generate the hash key from the data if the data is an int.
 *
 * @param data The data being inserted that needs to be hashed.
 * @return The hash key, a.k.a. index of the data in the list.
 */
template <typename TYPE>
int CHashTable<TYPE>::hashFunction(const int& data) const
{
	return (data % capacity);
}

/**
 * Generate the hash key from the data if the data is a string.
 *
 * @param data The data being inserted that needs to be hashed.
 * @return The hash key, a.k.a. index of the data in the list.
 */
template <typename TYPE>
int CHashTable<TYPE>::hashFunction(const string& data) const
{
	// Subtracting the first char's hex by 97 to make 'a' = 0
	return ((tolower(data[0]) - 97) % capacity);
}

#endif