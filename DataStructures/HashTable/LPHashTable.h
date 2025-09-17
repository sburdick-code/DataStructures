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
		bool insert(const TYPE& key);
		bool remove(TYPE& key);
		bool retrieve(const TYPE& key) const;
		void display();

	private:
		int hashFunction(const int key) const;
};

template <typename TYPE>
LPHashTable<TYPE>::LPHashTable(int c)
{
	capacity = c;
	table = new TYPE[capacity];
}

template <typename TYPE>
LPHashTable<TYPE>::~LPHashTable()
{
	capacity = 0;
	delete[] table;
	table = nullptr;
}

template <typename TYPE>
bool LPHashTable<TYPE>::insert(const TYPE& key)
{
	bool success = false;
	int initIndex = hashFunction(key);
	int index = initIndex;
	
	do {
		if (table[index] < 0)
		{
			table[index] = key;
			success = true;
		}
		else
		{
			index = (index + 1) % capacity;
		}
			
	} while (!success && index != initIndex);

	return success;
}

template <typename TYPE>
bool LPHashTable<TYPE>::remove(TYPE& key)
{
	bool success = false;
	int initIndex = hashFunction(key);
	int index = initIndex;

	do {
		if (table[index] == key)
		{
			key = table[index];
			table[index] = -1;
			success = true;
		}
		else
		{
			index = (index + 1) % capacity;
		}
	} while (!success && index != initIndex);

	return success;
}

template <typename TYPE>
bool LPHashTable<TYPE>::retrieve(const TYPE& key) const
{
	bool success = false;
	int initIndex = hashFunction(key);
	int index = initIndex;

	do {
		if (table[index] == key)
		{
			success = true;
		}
		else
		{
			index = (index + 1) % capacity;
		}
	} while (!success && index != initIndex);

	return success;
}

template <typename TYPE>
void LPHashTable<TYPE>::display()
{
	for (int i = 0; i < capacity; i++)
	{
		cout << "[" << i << "] " << table[i] << ", ";
	}

	cout << endl << endl;
}

template <typename TYPE>
int LPHashTable<TYPE>::hashFunction(const int key) const
{
	return (key % capacity);
}
#endif