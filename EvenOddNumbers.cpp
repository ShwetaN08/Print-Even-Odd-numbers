#include "EvenOddNumbers.h"
bool isEven = true;
void EvenOddNumbers::printEvenNumbers() {
	while (input < maxNumber) {
		unique_lock <mutex> lock(printMutex);
		if (!isEven) {
			//cout << "even" << endl;
			cv.wait(lock);	//current thread is blocked until the condition variable is notified
		}
		this_thread::sleep_for(chrono::seconds(1));
		cout << "Thread 1:" << input << endl;
		input++;
		isEven = false;
		cv.notify_all();
	}
}

void EvenOddNumbers::printOddNumbers() {
	while (input < maxNumber) {
		unique_lock <mutex> lock(printMutex);
		if (isEven) {
			//cout << "odd" << endl;
			cv.wait(lock);	//current thread is blocked until the condition variable is notified
		}
		this_thread::sleep_for(chrono::seconds(1));
		cout << "Thread 2:" << input << endl;
		input++;
		isEven = true;
		cv.notify_all();
	}
}


