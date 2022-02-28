
Project5: token.o myStack.o proj5Base.o
	g++ -o Project5 token.o myStack.o proj5Base.o

token.o: token.cpp calculator.h
	g++ -c token.cpp

myStack.o: myStack.cpp calculator.h
	g++ -c myStack.cpp

proj5Base.o: proj5Base.cpp calculator.h
	g++ -c proj5Base.cpp

run:
	./Project5

clean:
	rm token.o myStack.o proj5Base.o Project5

build_test: myStack.o test.o
	g++ -o build_test myStack.o test.o

test.o: test.cpp calculator.h
	g++ -c test.cpp

run_test:
	./build_test

valgrind:
	valgrind ./build_test