/*
 * This file is part of DataStructures.sln.
 * Developed for educational purposes.
 * This program is free software: you can redistribute it and/or modify it.
 *
 * This program is used to test the data structures created.
 *
 */

#include <iostream>
#include <new>
using namespace std;

#include "Stack/Stack.h"
#include "Queue/Queue.h"
#include "LList/OrderedList.h"
#include "LList/UnorderedList.h"
#include "DLList/DLList.h"
#include "LList/CircularList.h"
#include "HashTable/LPHashTable.h"
#include "HashTable/CHashTable.h"

#include "Algorithms/Bubblesort.h"
#include "Algorithms/InsertionSort.h"

void TestStack();
void TestQueue();
void TestOrderedList();
void TestUnorderedList();
void TestOrderedDoublyLinkedList();
void TestNewFunctions_UnorderedList();
void TestCircularList();
void TestLinearProbingHashTable();
void TestChainedHashTable();

void TestBubblesort();

int main()
{
	// TestStack();
	// TestQueue();
	// TestOrderedList();
	// TestUnorderedList();
	// TestOrderedDoublyLinkedList();
	// TestCircularList();
	//TestNewFunctions_UnorderedList();
	//TestLinearProbingHashTable
	//TestChainedHashTable();

	// TestBubblesort();
	const int LENGTH = 4;
	int myArray[LENGTH] = { 19, 5, 1, 12 };

	cout << "Before Insertion Sort:\t";
	for (int i = 0; i < LENGTH; i++)
		cout << myArray[i] << ", ";
	cout << endl;

	insertionSortArray(myArray, LENGTH);

	cout << "After Insertion Sort:\t";
	for (int i = 0; i < LENGTH; i++)
		cout << myArray[i] << ", ";
	cout << endl;

}

/////////////////////////////////////////////////////////////////////////
// DATA STRUCTURES
/////////////////////////////////////////////////////////////////////////

/**
 * Smoke test my Stack data structure.
 */
void TestStack()
{
	
	AStack <int> myStack;
	int dataOut;

	cout << "TESTING STACK" << endl << endl;
	cout << boolalpha;

	cout << "Push 1 \t";
	cout << myStack.push(1) << endl;

	cout << "Push 2 \t";
	cout << myStack.push(2) << endl;

	cout << "Push 5 \t";
	cout << myStack.push(5) << endl;

	cout << "Pull 5 \t";
	cout << myStack.pop(dataOut) << endl;
	cout << dataOut << endl << endl;

	cout << "Peek 2 \t";
	cout << myStack.peek(dataOut) << endl;
	cout << dataOut << endl << endl;

	cout << "Pop 2 \t";
	cout << myStack.pop(dataOut) << endl;
	cout << dataOut << endl << endl;

	cout << "NumValues: \t" << myStack.getNumValues() << endl;
	cout << "isFull:    \t" << myStack.isFull() << endl;
	cout << "isEmpty:   \t" << myStack.isEmpty() << endl;

	cout << endl << "EMPTYING STACK" << endl;
	myStack.pop(dataOut);

	cout << "NumValues: \t" << myStack.getNumValues() << endl;
	cout << "isEmpty:   \t" << myStack.isEmpty() << endl;
}

/**
 * Smoke test my Queue data structure.
 */
void TestQueue()
{
	Queue<int> myQueue;
	int dataOut;

	cout << "TESTING QUEUE" << endl << endl;
	cout << boolalpha;

	cout << "Enqueue: 1 \t";
	cout << myQueue.enqueue(1) << endl;

	cout << "Enqueue: 2 \t";
	cout << myQueue.enqueue(2) << endl;

	cout << "Enqueue: 3 \t";
	cout << myQueue.enqueue(3) << endl;

	cout << "Enqueue: 4 \t";
	cout << myQueue.enqueue(4) << endl;

	cout << "Enqueue: 5 \t";
	cout << myQueue.enqueue(5) << endl;

	cout << "Enqueue: 6 \t";
	cout << myQueue.enqueue(6) << endl;

	cout << "Enqueue: 7 \t";
	cout << myQueue.enqueue(7) << endl;

	cout << "Dequeue: \t";
	cout << myQueue.dequeue(dataOut) << endl;
	cout << dataOut << endl << endl;

	cout << "Dequeue: \t";
	cout << myQueue.dequeue(dataOut) << endl;
	cout << dataOut << endl << endl;

	cout << "viewFront: \t";
	cout << myQueue.viewFront(dataOut) << endl;
	cout << dataOut << endl << endl;

	cout << "viewRear: \t";
	cout << myQueue.viewRear(dataOut) << endl;
	cout << dataOut << endl << endl;

	cout << "getNumValues: \t";
	cout << myQueue.getNumValues() << endl << endl;

	cout << "isEmpty: \t";
	cout << myQueue.isEmpty() << endl << endl;

	cout << "isFull: \t";
	cout << myQueue.isFull() << endl << endl;

	cout << "EMPTYING QUEUE" << endl << endl;
	while (myQueue.dequeue(dataOut));

	cout << "Dequeue: \t";
	cout << myQueue.dequeue(dataOut) << endl << endl;

	cout << "viewFront: \t";
	cout << myQueue.viewFront(dataOut) << endl << endl;

	cout << "viewRear: \t";
	cout << myQueue.viewRear(dataOut) << endl << endl;

	cout << "getNumValues: \t";
	cout << myQueue.getNumValues() << endl << endl;

	cout << "isEmpty: \t";
	cout << myQueue.isEmpty() << endl << endl;

	cout << "isFull: \t";
	cout << myQueue.isFull() << endl << endl;
	
}

/**
 * Smoke test my ordered Linked List data structure.
 */
void TestOrderedList()
{

	OrderedList<int> myList;
	int dataOut;

	cout << "TESTING ORDERED LINKED LIST" << endl << endl;
	cout << boolalpha;

	cout << "Insert 2: \t";
	cout << myList.insert(2) << endl;

	cout << "Insert 4: \t";
	cout << myList.insert(4) << endl;

	cout << "Insert 7: \t";
	cout << myList.insert(7) << endl;

	cout << "Insert 1: \t";
	cout << myList.insert(1) << endl;

	cout << "Insert 3: \t";
	cout << myList.insert(3) << endl;

	cout << "Insert 10:\t";
	cout << myList.insert(10) << endl;

	myList.display();
	cout << endl;

	dataOut = 4;
	cout << "Remove 4: \t";
	cout << myList.remove(dataOut) << "\t";
	cout << dataOut << endl;

	dataOut = 1;
	cout << "Remove 1: \t";
	cout << myList.remove(dataOut) << "\t";
	cout << dataOut << endl;

	dataOut = 10;
	cout << "Remove 10:\t";
	cout << myList.remove(dataOut) << "\t";
	cout << dataOut << endl;

	dataOut = 50;
	cout << "Remove 50:\t";
	cout << myList.remove(dataOut) << endl;

	myList.display();
	cout << endl;

	dataOut = 2;
	cout << "Retrieve 2:\t";
	cout << myList.retrieve(dataOut) << "\t";
	cout << dataOut << endl;

	dataOut = 3;
	cout << "Retrieve 3:\t";
	cout << myList.retrieve(dataOut) << "\t";
	cout << dataOut << endl;

	dataOut = 7;
	cout << "Retrieve 7:\t";
	cout << myList.retrieve(dataOut) << "\t";
	cout << dataOut << endl;

	dataOut = 50;
	cout << "Retrieve 50:\t";
	cout << myList.retrieve(dataOut) << endl << endl;

	cout << "viewFront:\t";
	cout << myList.viewFront(dataOut) << "\t";
	cout << dataOut << endl;

	cout << "viewRear:\t";
	cout << myList.viewRear(dataOut) << "\t";
	cout << dataOut << endl;

	cout << "numValues:\t";
	cout << myList.getNumValues() << endl;

	cout << "isEmpty:\t";
	cout << myList.isEmpty() << endl;

	cout << "isFull: \t";
	cout << myList.isFull() << endl << endl;

	cout << "EMPTYING LIST" << endl << endl;
	myList.~OrderedList();

	dataOut = 50;
	cout << "Remove 50:\t";
	cout << myList.remove(dataOut) << endl;

	dataOut = 2;
	cout << "Retrieve 2:\t";
	cout << myList.remove(dataOut) << endl;

	cout << "viewFront:\t";
	cout << myList.viewFront(dataOut) << endl;

	cout << "viewRear:\t";
	cout << myList.viewRear(dataOut) << endl;

	cout << "numValues:\t";
	cout << myList.getNumValues() << endl;

	cout << "isEmpty:\t";
	cout << myList.isEmpty() << endl;

	cout << "isFull: \t";
	cout << myList.isFull() << endl << endl;

}

/**
 * Smoke test my unordered Linked List data structure.
 */
void TestUnorderedList()
{

	UnorderedList<int> myList;
	int dataOut;

	cout << "TESTING UNORDERED LINKED LIST" << endl << endl;
	cout << boolalpha;

	/*cout << "Insert 2: \t";
	cout << myList.insert(2) << endl;

	cout << "Insert 4: \t";
	cout << myList.insert(4) << endl;

	cout << "Insert 7: \t";
	cout << myList.insert(7) << endl;

	cout << "Insert 1: \t";
	cout << myList.insert(1) << endl;

	cout << "Insert 3: \t";
	cout << myList.insert(3) << endl;

	cout << "Insert 10:\t";
	cout << myList.insert(10) << endl;*/

	myList.display();
	cout << endl;

	dataOut = 4;
	cout << "Remove 4: \t";
	cout << myList.remove(dataOut) << "\t";
	cout << dataOut << endl;

	dataOut = 2;
	cout << "Remove 2: \t";
	cout << myList.remove(dataOut) << "\t";
	cout << dataOut << endl;

	dataOut = 10;
	cout << "Remove 10:\t";
	cout << myList.remove(dataOut) << "\t";
	cout << dataOut << endl;

	dataOut = 50;
	cout << "Remove 50:\t";
	cout << myList.remove(dataOut) << endl;

	myList.display();
	cout << endl;

	dataOut = 2;
	cout << "Retrieve 2:\t";
	cout << myList.retrieve(dataOut) << "\t";
	cout << dataOut << endl;

	dataOut = 3;
	cout << "Retrieve 3:\t";
	cout << myList.retrieve(dataOut) << "\t";
	cout << dataOut << endl;

	dataOut = 7;
	cout << "Retrieve 7:\t";
	cout << myList.retrieve(dataOut) << "\t";
	cout << dataOut << endl;

	dataOut = 50;
	cout << "Retrieve 50:\t";
	cout << myList.retrieve(dataOut) << endl << endl;

	cout << "viewFront:\t";
	cout << myList.viewFront(dataOut) << "\t";
	cout << dataOut << endl;

	cout << "viewRear:\t";
	cout << myList.viewRear(dataOut) << "\t";
	cout << dataOut << endl;

	cout << "numValues:\t";
	cout << myList.getNumValues() << endl;

	cout << "isEmpty:\t";
	cout << myList.isEmpty() << endl;

	cout << "isFull: \t";
	cout << myList.isFull() << endl << endl;

	cout << "EMPTYING LIST" << endl << endl;
	myList.~UnorderedList();

	dataOut = 50;
	cout << "Remove 50:\t";
	cout << myList.remove(dataOut) << endl;

	dataOut = 2;
	cout << "Retrieve 2:\t";
	cout << myList.remove(dataOut) << endl;

	cout << "viewFront:\t";
	cout << myList.viewFront(dataOut) << endl;

	cout << "viewRear:\t";
	cout << myList.viewRear(dataOut) << endl;

	cout << "numValues:\t";
	cout << myList.getNumValues() << endl;

	cout << "isEmpty:\t";
	cout << myList.isEmpty() << endl;

	cout << "isFull: \t";
	cout << myList.isFull() << endl << endl;

}

/**
 * Smoke test my ordered Doubly Linked List data structure.
 */
void TestOrderedDoublyLinkedList()
{
	/// <summary>
	/// A function to stress test my Unordered Linked List data structure
	/// </summary>

	DLList<int> myList;
	int dataOut;

	cout << "TESTING ORDERED DOUBLY LINKED LIST" << endl << endl;
	cout << boolalpha;

	cout << "Insert 2: \t";
	cout << myList.insert(2) << endl;

	cout << "Insert 4: \t";
	cout << myList.insert(4) << endl;

	cout << "Insert 7: \t";
	cout << myList.insert(7) << endl;

	cout << "Insert 1: \t";
	cout << myList.insert(1) << endl;

	cout << "Insert 3: \t";
	cout << myList.insert(3) << endl;

	cout << "Insert 10:\t";
	cout << myList.insert(10) << endl;

	myList.display();
	cout << endl;

	dataOut = 4;
	cout << "Remove 4: \t";
	cout << myList.remove(dataOut) << "\t";
	cout << dataOut << endl;

	dataOut = 2;
	cout << "Remove 2: \t";
	cout << myList.remove(dataOut) << "\t";
	cout << dataOut << endl;

	dataOut = 10;
	cout << "Remove 10:\t";
	cout << myList.remove(dataOut) << "\t";
	cout << dataOut << endl;

	dataOut = 50;
	cout << "Remove 50:\t";
	cout << myList.remove(dataOut) << endl;

	myList.display();
	cout << endl;

	dataOut = 2;
	cout << "Retrieve 2:\t";
	cout << myList.retrieve(dataOut) << "\t";
	cout << dataOut << endl;

	dataOut = 3;
	cout << "Retrieve 3:\t";
	cout << myList.retrieve(dataOut) << "\t";
	cout << dataOut << endl;

	dataOut = 7;
	cout << "Retrieve 7:\t";
	cout << myList.retrieve(dataOut) << "\t";
	cout << dataOut << endl;

	dataOut = 50;
	cout << "Retrieve 50:\t";
	cout << myList.retrieve(dataOut) << endl << endl;

	cout << "viewFront:\t";
	cout << myList.viewFront(dataOut) << "\t";
	cout << dataOut << endl;

	cout << "viewRear:\t";
	cout << myList.viewRear(dataOut) << "\t";
	cout << dataOut << endl;

	cout << "numValues:\t";
	cout << myList.getNumValues() << endl;

	cout << "isEmpty:\t";
	cout << myList.isEmpty() << endl;

	cout << "isFull: \t";
	cout << myList.isFull() << endl << endl;

	cout << "EMPTYING LIST" << endl << endl;
	myList.~DLList();

	dataOut = 50;
	cout << "Remove 50:\t";
	cout << myList.remove(dataOut) << endl;

	dataOut = 2;
	cout << "Retrieve 2:\t";
	cout << myList.remove(dataOut) << endl;

	cout << "viewFront:\t";
	cout << myList.viewFront(dataOut) << endl;

	cout << "viewRear:\t";
	cout << myList.viewRear(dataOut) << endl;

	cout << "numValues:\t";
	cout << myList.getNumValues() << endl;

	cout << "isEmpty:\t";
	cout << myList.isEmpty() << endl;

	cout << "isFull: \t";
	cout << myList.isFull() << endl << endl;

}

/**
 * Smoke test the extended functions added to my Unordered Linked List.
 */
void TestNewFunctions_UnorderedList()
{
	int dataOut;

	cout << "TESTING UNORDERED LINKED LIST - NEW FUNCTIONS" << endl << endl;
	cout << boolalpha;

	cout << "Initializing with UnorderedList(const int n)\t n = 3" << endl;
	UnorderedList<int> myList_01(3);
	myList_01.display();
	cout << endl;
	myList_01.~UnorderedList();

	cout << "Initializing with UnorderedList(const int n)\t n = 0" << endl;
	UnorderedList<int> myList_02(0);
	cout << "IsEmpty:\t";
	cout << myList_02.isEmpty() << endl << endl;

	cout << "Initializing with UnorderedList(const int n, const TYPE & initData)\t n = 7, initData = 10" << endl;
	UnorderedList<int> myList_03(7, 10);
	myList_03.display();
	cout << endl;

	cout << "Initializing with UnorderedList(TYPE* pFirst, TYPE* pLast)" << endl;
	cout << "Created an array: { 10, 20, 60, 40, 50 }\t pFirst = &10, pLast = &50" << endl;
	int sourceArray[] = { 10, 20, 60, 40, 50 };
	int* pFirst = &sourceArray[0];
	int* pLast = &sourceArray[4];
	UnorderedList<int> myList_04(pFirst, pLast);
	myList_04.display();
	cout << endl;


	cout << "pushFront 2: \t";
	cout << myList_01.pushFront(2) << endl;

	cout << "pushBack 4: \t";
	cout << myList_01.pushBack(4) << endl;

	cout << "pushBack 7: \t";
	cout << myList_01.pushBack(7) << endl;

	cout << "pushBack 1: \t";
	cout << myList_01.pushBack(1) << endl;

	myList_01.display();
	cout << endl;

	cout << "Insert 3 at [0]: \t";
	cout << myList_01.insert(0, 3) << endl;

	myList_01.display();
	cout << endl;

	cout << "Insert 10 at [4]:\t";
	cout << myList_01.insert(4, 10) << endl;

	myList_01.display();
	cout << endl;


	cout << "popFront: \t";
	cout << myList_01.popFront(dataOut) << endl;
	cout << dataOut << endl;

	cout << "popBack: \t";
	cout << myList_01.popBack(dataOut) << endl;
	cout << dataOut << endl;

	myList_01.display();
	cout << endl;

	cout << "popBack: \t";
	cout << myList_01.popBack(dataOut) << endl;
	cout << dataOut << endl;

	myList_01.display();
	cout << endl;

	int myArray[] = { 1, 2, 3 };
	UnorderedList<int> myList_05(&myArray[0], &myArray[2]);
	cout << "Initialized a new list:" << endl;
	myList_05.display();
	cout << endl;
	

	cout << "Appending into previous list: \t";
	cout << myList_01.merge(myList_05) << endl;
	myList_01.display();
	cout << endl;
}

/**
 * Smoke test my Circular Linked List data structure.
 */
void TestCircularList()
{
	cout << "TESTING CIRCULARLY LINKED LIST" << endl << endl;
	cout << boolalpha;

	CircularList<int> myList;
	int dataOut;

	cout << "pushFrnt 2: \t";
	cout << myList.pushFront(2) << endl;

	cout << "pushBack 4: \t";
	cout << myList.pushBack(4) << endl;

	cout << "pushBack 7: \t";
	cout << myList.pushBack(7) << endl;

	cout << "pushBack 1: \t";
	cout << myList.pushBack(1) << endl;

	myList.display();
	cout << endl;

	


	cout << "Insert 3 at [0]: \t";
	cout << myList.insert(0, 3) << endl;

	myList.display();
	cout << endl;

	cout << "Insert 10 at [4]:\t";
	cout << myList.insert(4, 10) << endl;

	myList.display();
	cout << endl;

	cout << "Insert 8 at [50]:\t";
	cout << myList.insert(50, 8) << endl;

	myList.display();
	cout << endl;

	cout << "NumValues:\t";
	cout << myList.getNumValues() << endl << endl;


	dataOut = 7;
	cout << "Remove 7:\t";
	cout << myList.remove(dataOut) << endl;

	dataOut = 8;
	cout << "Remove 8:\t";
	cout << myList.remove(dataOut) << endl;

	dataOut = 3;
	cout << "Remove 3:\t";
	cout << myList.remove(dataOut) << endl;

	dataOut = 50;
	cout << "Remove 50:\t";
	cout << myList.remove(dataOut) << endl;

	myList.display();
	cout << endl;

	cout << "NumValues:\t";
	cout << myList.getNumValues() << endl << endl;


	cout << "isEmpty:\t";
	cout << myList.isEmpty() << endl;

	cout << "isFull: \t";
	cout << myList.isFull() << endl << endl;


	cout << "Emptying Circular LList" << endl;
	myList.~CircularList();

	cout << "isEmpty:\t";
	cout << myList.isEmpty() << endl;

	cout << "isFull: \t";
	cout << myList.isFull() << endl << endl;

	

}

/**
 * Smoke test my Linear Probing Hash Table data structure.
 */
void TestLinearProbingHashTable()
{
	cout << "TESTING LINEAR PROBING HASH TABLE" << endl << endl;
	cout << boolalpha;

	int dataOut;
	LPHashTable<int> myHash(25);

	cout << "insert 1:\t" << myHash.insert(1) << endl;
	cout << "insert 3:\t" << myHash.insert(3) << endl;
	cout << "insert 10:\t" << myHash.insert(10) << endl;
	cout << "insert 24:\t";
	cout << myHash.insert(24) << endl;
	cout << "insert 25:\t";
	cout << myHash.insert(25) << endl;
	myHash.display();

	cout << "insert 35:\t";
	cout << myHash.insert(35) << endl;
	cout << "insert 26:\t";
	cout << myHash.insert(26) << endl;
	cout << "insert 50:\t";
	cout << myHash.insert(50) << endl;
	myHash.display();

	dataOut = 10;
	cout << "retrieve 10:\t";
	cout << myHash.retrieve(dataOut) << endl;

	dataOut = 35;
	cout << "retrieve 35:\t";
	cout << myHash.retrieve(dataOut) << endl;

	dataOut = 200;
	cout << "retrieve 200:\t";
	cout << myHash.retrieve(dataOut) << endl;

	myHash.display();

	dataOut = 10;
	cout << "remove 10:\t";
	cout << myHash.remove(dataOut) << endl;

	dataOut = 35;
	cout << "remove 35:\t";
	cout << myHash.remove(dataOut) << endl;

	dataOut = 200;
	cout << "remove 200:\t";
	cout << myHash.remove(dataOut) << endl;

	dataOut = 50;
	cout << "remove 50:\t";
	cout << myHash.remove(dataOut) << endl;

	myHash.display();

	cout << endl << "Initializing String Hash" << endl;
	CHashTable<string> strHash();
	string data;

	cout << "insert Adams, Joe:\t" << myHash.insert(int("A")) << endl;
	cout << "insert Biggs, Jen:\t" << myHash.insert(3) << endl;
	cout << "insert Ricco, Tom:\t" << myHash.insert(10) << endl;
	cout << "insert Jules, Ann:\t";
	cout << myHash.insert(24) << endl;
	cout << "insert 25:\t";
	cout << myHash.insert(25) << endl;
	myHash.display();




}

/**
 * Smoke test my Chained Hash Table data structure.
 */
void TestChainedHashTable()
{
	cout << "TESTING CHAINED HASH TABLE" << endl << endl;
	cout << boolalpha;

	int dataOut;
	CHashTable<int> myHash(25);

	cout << "insert 1:\t" << myHash.insert(1) << endl;
	cout << "insert 3:\t" << myHash.insert(3) << endl;
	cout << "insert 10:\t" << myHash.insert(10) << endl;
	cout << "insert 24:\t";
	cout << myHash.insert(24) << endl;
	cout << "insert 25:\t";
	cout << myHash.insert(25) << endl;
	myHash.display();

	cout << "insert 35:\t";
	cout << myHash.insert(35) << endl;
	cout << "insert 26:\t";
	cout << myHash.insert(26) << endl;
	cout << "insert 50:\t";
	cout << myHash.insert(50) << endl;
	myHash.display();

	dataOut = 10;
	cout << "retrieve 10:\t";
	cout << myHash.retrieve(dataOut) << endl;

	dataOut = 35;
	cout << "retrieve 35:\t";
	cout << myHash.retrieve(dataOut) << endl;

	dataOut = 200;
	cout << "retrieve 200:\t";
	cout << myHash.retrieve(dataOut) << endl;

	myHash.display();

	dataOut = 10;
	cout << "remove 10:\t";
	cout << myHash.remove(dataOut) << endl;

	dataOut = 35;
	cout << "remove 35:\t";
	cout << myHash.remove(dataOut) << endl;

	dataOut = 200;
	cout << "remove 200:\t";
	cout << myHash.remove(dataOut) << endl;

	dataOut = 50;
	cout << "remove 50:\t";
	cout << myHash.remove(dataOut) << endl;

	myHash.display();


	// String Hash Table
	cout << "Initializing string hash table:\n";
	string stringOut;
	CHashTable<string> stringHash(26);

	cout << "insert Adam:\t" << stringHash.insert("Adam") << endl;
	cout << "insert Ben:\t" << stringHash.insert("Ben") << endl;
	cout << "insert Jenny:\t" << stringHash.insert("Jenny") << endl;
	cout << "insert Rick:\t" << stringHash.insert("Rick") << endl;
	cout << "insert Zoe:\t" << stringHash.insert("Zoe") << endl;
	stringHash.display();

	cout << "insert Ann:\t" << stringHash.insert("Ann") << endl;
	cout << "insert Joe:\t" << stringHash.insert("Joe") << endl;
	cout << "insert Tom:\t" << stringHash.insert("Tom") << endl;
	stringHash.display();

	stringOut = "Adam";
	cout << "retrieve Adam:\t" << stringHash.retrieve(stringOut) << endl;
	stringOut = "Ann";
	cout << "retrieve Ann:\t" << stringHash.retrieve(stringOut) << endl;
	stringOut = "Will";
	cout << "retrieve Will:\t" << stringHash.retrieve(stringOut) << endl;
	stringOut = "Rick";
	cout << "retrieve Rick:\t" << stringHash.retrieve(stringOut) << endl;

	stringHash.display();

	stringOut = "Joe";
	cout << "remove Joe:   \t" << stringHash.remove(stringOut) << endl;
	stringOut = "Ann";
	cout << "remove Ann:   \t" << stringHash.remove(stringOut) << endl;
	stringOut = "Hugo";
	cout << "remove Hugo:   \t" << stringHash.remove(stringOut) << endl;
	stringOut = "Adam";
	cout << "remove Adam:   \t" << stringHash.remove(stringOut) << endl;

	stringHash.display();
}


/////////////////////////////////////////////////////////////////////////
// ALGORITHMS
/////////////////////////////////////////////////////////////////////////

/**
 * Test the functionality of my Bubble Sort Algorithm.
 */
void TestBubblesort()
{
	int length = 2;
	int myArray_00[] = { 3, 2, };

	cout << "Before Bubblesort:\n";
	for (int i = 0; i < length; i++)
		cout << myArray_00[i] << ", ";
	cout << endl;

	bubblesortArray(myArray_00, length);

	cout << "After Bubblesort:\n";
	for (int i = 0; i < length; i++)
		cout << myArray_00[i] << ", ";
	cout << endl << endl;


	length = 5;
	int myArray_01[] = { 3, 2, 9, 7, 4 };

	cout << "Before Bubblesort:\n";
	for (int i = 0; i < length; i++)
		cout << myArray_01[i] << ", ";
	cout << endl;

	bubblesortArray(myArray_01, length);

	cout << "After Bubblesort:\n";
	for (int i = 0; i < length; i++)
		cout << myArray_01[i] << ", ";
	cout << endl << endl;


	length = 6;
	double myArray_02[] = { 2.5, .7, 9.7, 6.5, 3.4, 1.8 };

	cout << "Before Bubblesort:\n";
	for (int i = 0; i < length; i++)
		cout << myArray_02[i] << ", ";
	cout << endl;

	bubblesortArray(myArray_02, length);

	cout << "After Bubblesort:\n";
	for (int i = 0; i < length; i++)
		cout << myArray_02[i] << ", ";
	cout << endl << endl;

	length = 1;
	double myArray_03[] = { 3.1 };

	cout << "Before Bubblesort:\n";
	for (int i = 0; i < length; i++)
		cout << myArray_03[i] << ", ";
	cout << endl;

	bubblesortArray(myArray_03, length);

	cout << "After Bubblesort:\n";
	for (int i = 0; i < length; i++)
		cout << myArray_03[i] << ", ";
	cout << endl << endl;


	length = 3;
	string myArray_04[] = { "Tom", "Joe", "Annie" };

	cout << "Before Bubblesort:\n";
	for (int i = 0; i < length; i++)
		cout << myArray_04[i] << ", ";
	cout << endl;

	bubblesortArray(myArray_04, length);

	cout << "After Bubblesort:\n";
	for (int i = 0; i < length; i++)
		cout << myArray_04[i] << ", ";
	cout << endl << endl;

}
