#include "src/macro.h"
#include <sys/ipc.h>
#include <sys/shm.h>

int main(int argc, char const *argv[]){
    int shmid;
    key_t key;
    char *shm;

    key = 5678;

    if ((shmid = shmget(key, SHMSZ, 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    if ((shm = (char*)shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    while(1){
        if(*shm!='*'){
            cout << (int)*shm << " ";
            *shm = '*';
        }        
    }    

    exit(0);
}