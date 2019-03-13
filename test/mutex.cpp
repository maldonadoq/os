#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex mtx;

void print_car(unsigned n, char c) {
  mtx.lock();

  for (unsigned i=0; i<n; ++i)
    cout << c;
  cout << endl;

  mtx.unlock();
}

int main (){
    unsigned i, t = 10, w = 5;
    char car[t] = {'a','b','c','d','e','f','g','h','i','j'};
    thread th[t];

    for(i=0; i<t; i++)
        th[i] = thread(print_car,w*(i+1),car[i]);

    for(i=0; i<t; i++)
        th[i].join();

  return 0;
}