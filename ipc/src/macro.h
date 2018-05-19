#ifndef _MACRO_H_
#define _MACRO_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <fcntl.h>

#include <condition_variable>
#include <mutex>

using namespace std;

// mq
#define SERVER_QUEUE_NAME   "/server"
#define QUEUE_PERMISSIONS 0660
#define MAX_MESSAGES 10
#define MAX_MSG_SIZE 256
#define MSG_BUFFER_SIZE MAX_MSG_SIZE + 10

//fifo
#define FIFO_NAME "data"

//shm
#define SHMSZ     27

static int ns = 10000;		//number signals

static mutex mtx;
static condition_variable cv;
static unique_lock<mutex> lck(mtx);

#endif