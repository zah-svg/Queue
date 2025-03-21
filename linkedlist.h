#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

// Struktur Node
typedef struct Node {
    int info;
    struct Node* next;
} Node;

// Struktur List
typedef struct LinkedList {
    Node* first;
} LinkedList;

boolean isEmpty(LinkedList *list);
void createList(LinkedList* list);
void printList(LinkedList list);
Node* createNode(int value);
void insertAtFirst(LinkedList* list, int newValue);
void insertAtLast(LinkedList* list, int newValue);
void insertBeforeBetween(LinkedList* list, int targetValue, int newValue);
void insertAfterBetween(LinkedList* list, int targetValue, int newValue);
void insertByValue(LinkedList* list, int oldValue, int newValue);
void deleteAtFirst(LinkedList* list);
void deleteAtLast(LinkedList* list);
void deleteBeforeBetween(LinkedList* list, int targetValue);
void deleteAfterBetween(LinkedList* list, int targetValue);
void deleteByValue(LinkedList* list, int targetValue);
void modifyAtFirst(LinkedList* list, int newValue);
void modifyAtLast(LinkedList* list, int newValue);
void modifyBeforeBetween(LinkedList* list, int targetValue, int newValue);
void modifyAfterBetween(LinkedList* list, int targetValue, int newValue);
void modifyByValue(LinkedList* list, int oldValue, int newValue);

#endif
