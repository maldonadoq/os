#include <iostream>
#include <atomic>
#include <thread>
#include <vector>

using namespace std;

atomic<bool> ready (false);
atomic_flag winner = ATOMIC_FLAG_INIT;

void counter(int id) {
	while (!ready)	
		this_thread::yield();					// wait for the ready signal
	for(volatile int i=0; i<1000000; i++);

	if(!winner.test_and_set())
		cout << "thread #" << id << " won!" << endl;
}

int main (){
	thread th[10];
	cout << "Count to 1 million" << endl;

	for (int i=0; i<10; i++) 
		th[i] = thread(counter,i);

	ready = true;

	for (int i=0; i<10; i++) 
		th[i].join();

	return 0;
}