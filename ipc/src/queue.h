#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdlib.h>
#include <stdio.h>
 
struct mnode{
    int m_data;
    struct mnode *m_next;
};
 
 
struct mqueue{
    struct mnode *m_first, *m_last;
};
 

struct mnode* new_node(int _data){
    struct mnode *temp = (struct mnode*)malloc(sizeof(struct mnode));
    temp->m_data = _data;
    temp->m_next = NULL;
    return temp; 
}

struct mqueue *new_queue(){
    struct mqueue *q = (struct mqueue*)malloc(sizeof(struct mqueue));
    q->m_first = q->m_last = NULL;
    return q;
}
 

void push(struct mqueue *q, int _data){
    struct mnode *temp = new_node(_data);

    if (q->m_last == NULL){
       q->m_first = q->m_last = temp;
       return;
    }
 
    q->m_last->m_next = temp;
    q->m_last = temp;
}
 
struct mnode *pop(struct mqueue *q){
    if (q->m_first == NULL)
       return NULL;
 
    struct mnode *temp = q->m_first;
    q->m_first = q->m_first->m_next;
 
    if (q->m_first == NULL)
       q->m_last = NULL;
    return temp;
}

#endif