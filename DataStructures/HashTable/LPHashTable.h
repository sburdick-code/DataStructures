/*
 * This file is part of DataStructures.sln.
 * Developed for educational purposes.
 * This program is free software: you can redistribute it and/or modify it.
 *
 * This program is used to create a Linear Probing Hash Table, its data, 
 * and its member functions.
 *
 */

#ifndef LPHASHTABLE_H
#define LPHASHTABLE_H

#include <new>

template <typename TYPE>
class LPHashTable
{
	private:
		TYPE* table;
		int capacity;

	public:
		LPHashTable(int c = 25);
		~LPHashTable();
		bool insert(const TYPE& dataIn);
		bool remove(TYPE& dataOut);
		bool retrieve(TYPE& dataOut) const;
		void display();

	private:
		int hashFunction(const int& data) const;
};

/**
 * Initializes the Linear Probing Hash Table.
 *
 * @param c The initialized capacity of the hash table.
 */
template <typename TYPE>
LPHashTable<TYPE>::LPHashTable(int c)
{
	capacity = c;
	table = new TYPE[capacity];
}

/**
 * Destructor for the Linear Probing Hash Table.
 */
template <typename TYPE>
LPHashTable<TYPE>::~LPHashTable()
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
bool LPHashTable<TYPE>::insert(const TYPE& dataIn)
{
	bool success = false;
	int key = hashFunction(dataIn);
	int index = key;
	
	do {
		if (table[index] < 0)
		{
			table[index] = dataIn;
			success = true;
		}
		else
		{
			index = (index + 1) % capacity;
		}
			
	} while (!success && index != key);

	return success;
}

/**
 * Removes specified data into the hash table.
 *
 * @param dataOut The data being removed.
 * @return Returns true if successful, false if the data could not be found.
 */
template <typename TYPE>
bool LPHashTable<TYPE>::remove(TYPE& dataOut)
{
	bool success = false;
	int key = hashFunction(dataOut);
	int index = key;

	do {
		if (table[index] == dataOut)
		{
			dataOut = table[index];
			table[index] = -1;
			success = true;
		}
		else
		{
			index = (index + 1) % capacity;
		}
	} while (!success && index != key);

	return success;
}

/**
 * Finds specified data into the hash table, but does not remove it.
 *
 * @param dataOut The data searched for.
 * @return Returns true if successful, false if the data could not be found.
 */
template <typename TYPE>
bool LPHashTable<TYPE>::retrieve(TYPE& dataOut) const
{
	bool success = false;
	int key = hashFunction(dataOut);
	int index = key;

	do {
		if (table[index] == dataOut)
		{
			dataOut = table[index];
			success = true;
		}
		else
		{
			index = (index + 1) % capacity;
		}
	} while (!success && index != key);

	return success;
}

/**
 * Nicely displayes the contents of the hash table in a human readable format.
 */
template <typename TYPE>
void LPHashTable<TYPE>::display()
{
	for (int i = 0; i < capacity; i++)
	{
		cout << "[" << i << "] " << table[i] << ", ";
	}

	cout << endl << endl;
}

/**
 * Generate the hash key from the data if the data is an int.
 *
 * @param data The data being inserted that needs to be hashed.
 * @return The hash key, a.k.a. index of the data in the list.
 */
template <typename TYPE>
int LPHashTable<TYPE>::hashFunction(const int& data) const
{
	return (data % capacity);
}
#endif