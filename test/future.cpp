#include <iostream>
#include <future>
#include <chrono>

using namespace std;

long factorial(future<unsigned> &f){
    unsigned t = f.get();   //exception broken promise
    long ft = 1;
    for(unsigned i=1; i<=t; i++)
        ft*=i;
    return ft;
}

int main (){
    unsigned t = 5;
    long ft;

    promise<unsigned> p;    
    future<unsigned> f = p.get_future();

    future<long> fut = async(launch::async,factorial,ref(f)); 
    p.set_value(t);
    //p.set_exception(make_exception_ptr(runtime_error("Broken Promise")));

    ft = fut.get();

    cout << t << "! = " << ft << endl;
  return 0;
}