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
int LPHashTable<TYPE>::hashFunction(const int& data) const
{
	return (data % capacity);
}
#endif