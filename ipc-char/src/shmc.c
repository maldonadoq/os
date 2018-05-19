#include "values.h"

int main(int argc, char const *argv[]){
	const char *name = "os";		//name share
	const int SIZE = 4096;			//size memory
	mqd_t qd_server, qd_client;		//queue descriptors

	int shm_fd;
	void *ptr;
	int i;

	//open the shared memory segment
	shm_fd = shm_open(name, O_RDONLY, 0666);
	if (shm_fd == -1) {
		printf("shared memory failed\n");
		exit(-1);
	}

	//now map the shared memory segment in the address space of the process
	ptr = mmap(0,SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);
	if (ptr == MAP_FAILED) {
		printf("map failed\n");
		exit(-1);
	}

	//now read from the shared memory region -> mqs
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

    while(1){
	    if (mq_receive (qd_server, in_buffer, MSG_BUFFER_SIZE, NULL) == -1) {
	        perror ("server: mq_receive");
	        exit (1);
	    }

		printf ("server: message received.\n");
		printf ("client: %s\n",in_buffer);    

		if ((qd_client = mq_open (in_buffer, O_WRONLY)) == 1) {
	        perror ("server: not able to open client queue");
	        continue;
	    }

	    sprintf (out_buffer, "%s", (char*)ptr);

	    if (mq_send(qd_client, out_buffer, strlen(out_buffer), 0) == -1) {
	        perror ("server: not able to send message to client");
	        continue;
	    }

	    printf("server: response sent to client.\n\n");
	}
    //mqs

	//remove the shared memory segment
	if (shm_unlink(name) == -1) {
		printf("error removing %s\n",name);
		exit(-1);
	}
	return 0;
}