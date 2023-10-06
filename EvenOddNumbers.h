#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <condition_variable>

using namespace std;

class EvenOddNumbers {
public:
	mutex printMutex;								//Declared a mutex
	int input = 0;									//Shared resource 
	int maxNumber;
	condition_variable cv;
	EvenOddNumbers(int n) {
		cout << "EvenOddNumbers class created" << endl;
		maxNumber =n;
	}
	void printEvenNumbers();
	void printOddNumbers();
};