#include <iostream>
#include <new>

using namespace std;

#include "Stack/Stack.h"
#include "Queue/Queue.h"
#include "LList/OrderedList.h"
#include "LList/UnorderedList.h"
#include "DLList/DLList.h"
#include "Algorithms/Bubblesort.h"

void TestStack();
void TestQueue();
void TestOrderedList();
void TestUnorderedList();
void TestOrderedDoublyLinkedList();
void TestNewFunctions_UnorderedList();

void TestBubblesort();

int main()
{
	// TestStack();
	// TestQueue();
	// TestOrderedList();
	// TestUnorderedList();
	// TestOrderedDoublyLinkedList();

	TestNewFunctions_UnorderedList();
	
	// TestBubblesort();
}

void TestStack()
{
	/// <summary>
	/// A function to stress test my Stack Data Structure
	/// </summary>
	
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

void TestQueue()
{
	/// <summary>
	/// A function to stress test my queue data structure
	/// </summary>
	
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

void TestOrderedList()
{
	/// <summary>
	/// A function to stress test my ordered Linked List data structure
	/// </summary>

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

void TestUnorderedList()
{
	/// <summary>
	/// A function to stress test my Unordered Linked List data structure
	/// </summary>

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
	int myArray_01[] = { 3, 2, 9, 7, 4};

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
	string myArray_04[] = { "Tom", "Joe", "Annie"};

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