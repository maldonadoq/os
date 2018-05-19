#ifndef _VALUES_H_
#define _VALUES_H_

//shmp.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>

//shmc.c - mqc.c
#include <sys/types.h>
#include <mqueue.h>
#include <string.h>

#define SERVER_QUEUE_NAME   "/sp-server"
#define QUEUE_PERMISSIONS 0660
#define MAX_MESSAGES 10
#define MAX_MSG_SIZE 256
#define MSG_BUFFER_SIZE MAX_MSG_SIZE+20

#endif