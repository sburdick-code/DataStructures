#ifndef STACK_H
#define STACK_H

#include <new>;

template <typename TYPE>
class AStack
{

	private:
		TYPE* stack;
		int top;
		int capacity;

	public:
		AStack(int c = 100);
		~AStack();
		bool push(const TYPE& dataIn);
		bool pop(TYPE& dataOut);
		bool peek(TYPE& dataOut) const;
		int getNumValues() const;
		bool isFull() const;
		bool isEmpty() const;

};

template <typename TYPE>
AStack<TYPE>::AStack(int c)
{
	capacity = c;
	stack = new TYPE[capacity];
	top = -1;
}

template <typename TYPE>
AStack<TYPE>::~AStack()
{
	capacity = 0;
	top = -1;
	delete[] stack;
	stack = nullptr;
}

template <typename TYPE>
bool AStack<TYPE>::push(const TYPE& dataIn)
{
	bool success = false;

	if (top + 1 < capacity)
	{
		top++;
		stack[top] = dataIn;
		success = true;
	}

	return success;
}

template <typename TYPE>
bool AStack<TYPE>::pop(TYPE& dataOut)
{
	bool success = false;

	if (top >= 0)
	{
		dataOut = stack[top];
		top--;
		success = true;
	}
	
	return success;
}

template <typename TYPE>
bool AStack<TYPE>::peek(TYPE& dataOut) const
{

	bool success = false;

	if (top > -1)
	{
		dataOut = stack[top];
		success = true;
	}

	return success;

}

template <typename TYPE>
int AStack<TYPE>::getNumValues() const
{
	return (top + 1);
}

template <typename TYPE>
bool AStack<TYPE>::isFull() const
{
	return (top + 1 >= capacity);
}

template <typename TYPE>
bool AStack<TYPE>::isEmpty() const
{
	return (top == -1);
}

#endif