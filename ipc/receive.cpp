#include "src/macro.h"
#include <errno.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <mqueue.h>
#include <thread>

#define SHMSZ     27

#include "src/queue.h"

static int num, tnum;
struct mqueue *qnumber;
struct mnode *qnode;

void read_fifo(){
	// fifo
	int fd;
	char s[1];

	while(true){
		mknod(FIFO_NAME, S_IFIFO | 0666, 0);
		fd = open(FIFO_NAME, O_RDONLY);

		read(fd,s,sizeof(s));
		tnum = s[0]-'0';	
		close(fd);	
		push(qnumber,tnum);	
	}
	unlink(FIFO_NAME);
}

void write_data(){

	char c;
    int shmid;
    key_t key;
    char *shm, *sm;

    key = 5678;

	//mqs
	mqd_t qd_server, qd_client;		//queue descriptors
	struct mq_attr attr;

    attr.mq_flags = 0;
    attr.mq_maxmsg = MAX_MESSAGES;
    attr.mq_msgsize = MAX_MSG_SIZE;
    attr.mq_curmsgs = 0;    

    if ((qd_server = mq_open (SERVER_QUEUE_NAME, O_RDONLY | O_CREAT, QUEUE_PERMISSIONS, &attr)) == -1) {
        perror("server: mq_open (server)");
        exit (1);
    }

    char in_buffer [MSG_BUFFER_SIZE];
    char out_buffer [MSG_BUFFER_SIZE];

	while(true){
		qnode = pop(qnumber);

		if(qnode!=NULL){
			num = qnode->m_data;			
			if(num%2 == 0){
				cout << "+";
				//create
				if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0) {
			        perror("shmget");
			        exit(1);
		    	}

			    if ((shm = (char*)shmat(shmid, NULL, 0)) == (char *) -1) {
			        perror("shmat");
			        exit(1);
			    }

			    sm = shm;
			    *sm++ = num;
			    sm = NULL;
			}
			else cout << "-";
		}
	}	
}

int main(int argc, char const *argv[]){
	qnumber = new_queue();
	unsigned t = 2;
	
	thread r(read_fifo);
	thread w(write_data);

	r.join();	w.join();

	return 0;	
}