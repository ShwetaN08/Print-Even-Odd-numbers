#include "EvenOddNumbers.h"

int main() {
	EvenOddNumbers object1(10);													// creating an object of class EvenOddNumbers
	thread printEvenNoThread(&EvenOddNumbers ::printEvenNumbers, &object1);		//calling member functions
	thread printOddNoThread(&EvenOddNumbers::printOddNumbers, &object1);

	printEvenNoThread.join();
	printOddNoThread.join();

	return 0;
}
