#include <stdio.h>
#include <thread>
#include <semaphore.h>
#include <unistd.h>
 
sem_t mutex;

using namespace std;

void thr(int t){
    //wait
    sem_wait(&mutex);
    printf("Entered..%d\n",t);
 
    //critical section
    //sleep(1);
    for(int i=0; i<5000; i++);
     
    //signal
    printf("Just Exiting...%d\n\n",t);
    sem_post(&mutex);
}
 
 
int main(){
    sem_init(&mutex, 0, 1);

    int t = 100;
    thread h[t];

    for(int i=0; i<t; i++)
        h[i] = thread(&thr,i);

    for(int i=0; i<t; i++)
        h[i].join();

    sem_destroy(&mutex);
    return 0;
}