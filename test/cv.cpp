#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <condition_variable>

using namespace std;

mutex mtx;
condition_variable cv;
bool ready = true;

void _thread(){
    unique_lock<mutex> lck(mtx);
    cv.wait(lck);
    //while(ready);
    cout << "End Thread " << endl;
}

int main (){
    thread th(_thread);
    this_thread::sleep_for(chrono::seconds(60));
    
    cv.notify_all();
    //ready = false;

    th.join();
    return 0;
}