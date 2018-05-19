#include <iostream>       // std::cout
#include <thread>         // std::thread, std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds

void pause_thread(int n){
	std::cout << "Thread with ID: " << n << "\n";
}

int main(){
	std::cout << "Spawning and detaching 3 threads...\n";
	for(int x=1; x<30 ; x++){
		std::thread (pause_thread,x).detach();
	}
	std::cout << "End of threads \n";

	return 0;
}
