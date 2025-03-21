#include "queue.h"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

// Inisialisasi Queue kosong
void initializeQueue(Queue* q) {
    createList(&q->list);
    q->head = NULL;
    q->tail = NULL;
    q->Number = 0;
}

// Cek apakah Queue kosong
boolean isQueueEmpty(Queue* q) {
    return (q->head == NULL);
}

// Enqueue
void enqueue(Queue* q) {
    q->Number++; 
    insertAtLast(&q->list, q->Number);
    
    if (q->head == NULL) {
        q->head = q->list.first;
    }
    
    q->tail = q->list.first;
    while (q->tail->next != NULL) {
        q->tail = q->tail->next;
    }
}

// Dequeue 
void dequeue(Queue* q, int *value) {
    if (isQueueEmpty(q)) {
        printf("Antrian kosong!\n");
        *value = -1; 
    } else {
        *value = q->head->info;
        deleteAtFirst(&q->list);
        q->head = q->list.first;  

        if (q->head == NULL) {
            q->tail = NULL;
        }
    }
}

// Cetak isi Queue
void printQueue(Queue* q) {
    printList(q->list);
}

