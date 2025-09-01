#include <iostream>
#include <new>

using namespace std;

#include "Stack/Stack.h"
#include "Queue/Queue.h"

void TestStack();
void TestQueue();

int main()
{
	// TestStack();
	TestQueue();
}

void TestStack()
{
	/// <summary>
	/// A function to stress test my Stack Data Structure
	/// </summary>
	
	AStack <int> myStack;

	int dataOut;

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
