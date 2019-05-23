btree:main.o queue.o binaryTree.o stack.o
	g++ -o btree  main.o queue.o binaryTree.o stack.o
main.o:binaryTree.cpp main.cpp
	g++ -c -o main.o main.cpp 
queue.o:queue.h linkQueue.cpp
	g++ -c -o queue.o linkQueue.cpp
stack.o:stack.h linkStack.cpp
	g++ -c -o stack.o linkStack.cpp
binaryTree.o:binaryTree.h binaryTree.cpp stack.h linkStack.cpp binaryTree.cpp main.cpp
	g++ -c -o binaryTree.o binaryTree.cpp