#include "src/macro.h"
#include <mqueue.h>

int main(int argc, char **argv){
    char client_queue_name [64];    //queue name
    mqd_t qd_server, qd_client;     //queue descriptors

    // create the client queue for receiving messages from server
    sprintf (client_queue_name, "/client-%d", getpid ());

    struct mq_attr attr;
    attr.mq_flags = 0;
    attr.mq_maxmsg = MAX_MESSAGES;
    attr.mq_msgsize = MAX_MSG_SIZE;
    attr.mq_curmsgs = 0;

    if((qd_client = mq_open (client_queue_name, O_RDONLY | O_CREAT, QUEUE_PERMISSIONS, &attr)) == -1) {
        perror ("client: mq_open (client)");
        exit (1);
    }

    if((qd_server = mq_open (SERVER_QUEUE_NAME, O_WRONLY)) == -1) {
        perror ("client: mq_open (server)");
        exit (1);
    }

    char in_buffer [MSG_BUFFER_SIZE];

    while (1) {
        // send message to server
        if(mq_send (qd_server, client_queue_name, strlen (client_queue_name), 0) == -1) {
            perror ("client: not able to send message to server");
            continue;
        }

        // receive response from server
        if(mq_receive (qd_client, in_buffer, MSG_BUFFER_SIZE, NULL) == -1) {
            perror ("client: mq_receive");
            exit (1);
        }

        // display token received from server
        printf ("%s ", in_buffer);
    }


    if(mq_close (qd_client) == -1) {
        perror ("client: mq_close");
        exit (1);
    }

    if(mq_unlink (client_queue_name) == -1) {
        perror ("client: mq_unlink");
        exit (1);
    }

    printf ("client: bye\n");
    exit (0);
}