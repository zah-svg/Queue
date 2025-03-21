#ifndef QUEUE_H
#define QUEUE_H
#include "linkedlist.h"
#include "boolean.h"
#define MAX_LOKET 3 

typedef struct {
    LinkedList list;  
    Node *head;
    Node *tail;
    int Number;  // untuk menyimpan nomor antrian terakhir
} Queue;

void initializeQueue(Queue* q);
boolean isQueueEmpty(Queue* q);
void enqueue(Queue* q);
void dequeue(Queue* q, int *value);
void printQueue(Queue* q);

#endif

