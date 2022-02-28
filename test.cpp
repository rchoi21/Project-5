#include <cstdio>
#include <cstring>
#include <cctype>
#include "calculator.h"

int main() {
	// testing stack.cpp
	MyStack s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.push(6);
	s.push(7);
	s.push(8);
	s.push(9);

	if (!s.isEmpty()) {
		printf("I think push works?\n");
	}

	// printf("%d\n", s.top());
	// s.pop(); // pops 9
	// printf("%d\n", s.top());
	// s.pop();
	// printf("%d\n", s.top());
	// s.pop();
	// printf("%d\n", s.top());
	// s.pop();
	// printf("%d\n", s.top());
	// s.pop();
	// printf("%d\n", s.top());
	// s.pop();
	// printf("%d\n", s.top());
	// s.pop();
	// printf("%d\n", s.top());
	// s.pop();
	// printf("%d\n", s.top());
	// s.pop(); // pops 1
	s.clear();

	if (s.isEmpty()) {
		printf("I think clear works\n");
	}


	return 0;
}