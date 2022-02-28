#include <cstdio>
#include <cstring>
#include <cctype>
#include "calculator.h"

// A stack for int only
// Default constructor for MyStack
MyStack::MyStack() {
	myStack = new int[2];
	capacity = 2;
	size = 0;
}

// add destructor
MyStack::~MyStack() {
	clear();
}

// To add a token onto the dynamic array "stack"
void MyStack::push(int x) {
	// check if stack at max capacity
	if (capacity == size) {
		// reallocate bigger (by 2) array after copying current contents
		int* temp = new int[capacity + 2];
		for (int i = 0; i < size; i++) {
			temp[i] = myStack[i];
		}
		delete[] myStack;
		myStack = temp;
		// delete[] temp;
		capacity += 2;
	}
	// add int x
	myStack[size] = x;
	size++;
}

// Returns the current top of myStack while also "popping" it off
int MyStack::top() {
	// check if there's nothing to return
	if (isEmpty()) {
		return -1;
	}
	int top = myStack[size - 1];
	return top;
}

void MyStack::pop() {
	// check if nothing is "poppable"
	if (isEmpty()) {
		return;
	}
	size--;
}

// Returns T/F to answer if myStack is "empty"
bool MyStack::isEmpty() {
	if (size == 0) {
		return true;
	}
	return false;
}

// completely cleaning up all the private data members
void MyStack::clear() {
	delete[] myStack;
	myStack = nullptr;
	size = 0;
	capacity = 0;
}