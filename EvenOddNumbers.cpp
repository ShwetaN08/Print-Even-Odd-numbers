#include "EvenOddNumbers.h"

void EvenOddNumbers::printEvenNumbers() {
	for (int i = 0;i <= maxNumber; i++) {
		unique_lock <mutex> lock(printMutex);	//
		while (input % 2 != 0) {		
			//wait until an even number comes
			lock.unlock();
			this_thread::yield();				//Meanwhile, allowing other threads to run
			lock.lock();
			//chrono::milliseconds(1000);
		}
		cout << "Thread 1:" << input << endl;
		input++;
	}
}
void EvenOddNumbers::printOddNumbers() {
	for (int i = 0;i <= maxNumber; i++) {
		unique_lock <mutex> lock(printMutex);
		while (input % 2 != 1) {
			//wait until an odd number comes
			lock.unlock();
			this_thread::yield();				//Meanwhile, allowing other threads to run
			lock.lock();
			//chrono::milliseconds(1000);
		}
		
		cout << "Thread 2:" << input << endl;
		input++;
	}
}

