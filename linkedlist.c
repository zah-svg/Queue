#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

boolean isEmpty(LinkedList *list){
    return (list->first == NULL);
}

// Fungsi untuk membuat list kosong
void createList(LinkedList* list) {
    list->first = NULL;
}

// Fungsi untuk mencetak seluruh elemen list
void printList(LinkedList list) {
    Node* temp = list.first;
    printf("List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->info);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Fungsi untuk membuat node baru
Node* createNode(int value){
	Node *newNode = (Node*)malloc(sizeof(Node));
	if (newNode){
		newNode->info = value;
		newNode->next = NULL;
	}
	return newNode;
}

// Insert di awal list
void insertAtFirst(LinkedList* list, int newValue) {
    Node* newNode = createNode(newValue);
    newNode->next = list->first;
    list->first = newNode;
}

// Insert di akhir list
void insertAtLast(LinkedList* list, int newValue) {
    Node* newNode = createNode(newValue);
    if (list->first == NULL) {
        list->first = newNode;
        return;
    }
    Node* temp = list->first;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Insert sebelum node tertentu
void insertBeforeBetween(LinkedList* list, int targetValue, int newValue) {
    if (list->first == NULL || list->first->info == targetValue) {
        insertAtFirst(list, newValue);
        return;
    }
    Node* temp = list->first;
    while (temp->next != NULL && temp->next->info != targetValue) {
        temp = temp->next;
    }
    if (temp->next != NULL) {
        Node* newNode = createNode(newValue);
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Insert setelah node tertentu
void insertAfterBetween(LinkedList* list, int targetValue, int newValue) {
    Node* temp = list->first;
    while (temp != NULL && temp->info != targetValue) {
        temp = temp->next;
    }
    if (temp != NULL) {
        Node* newNode = createNode(newValue);
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Insert berdasarkan nilai tertentu
void insertByValue(LinkedList* list, int oldValue, int newValue) {
    insertAfterBetween(list, oldValue, newValue);
}

// Delete node pertama
void deleteAtFirst(LinkedList* list) {
    if (list->first == NULL) return;
    Node* temp = list->first;
    list->first = list->first->next;
    free(temp);
}

// Delete node terakhir
void deleteAtLast(LinkedList* list) {
    if (list->first == NULL) return;
    if (list->first->next == NULL) {
        free(list->first);
        list->first = NULL;
        return;
    }
    Node* temp = list->first;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

// Delete sebelum node tertentu
void deleteBeforeBetween(LinkedList* list, int targetValue) {
    if (list->first == NULL || list->first->info == targetValue) return;
    if (list->first->next != NULL && list->first->next->info == targetValue) {
        deleteAtFirst(list);
        return;
    }
    Node* temp = list->first;
    while (temp->next->next != NULL && temp->next->next->info != targetValue) {
        temp = temp->next;
    }
    if (temp->next->next != NULL) {
        Node* deleteNode = temp->next;
        temp->next = temp->next->next;
        free(deleteNode);
    }
}

// Delete setelah node tertentu
void deleteAfterBetween(LinkedList* list, int targetValue) {
    Node* temp = list->first;
    while (temp != NULL && temp->info != targetValue) {
        temp = temp->next;
    }
    if (temp != NULL && temp->next != NULL) {
        Node* deleteNode = temp->next;
        temp->next = temp->next->next;
        free(deleteNode);
    }
}

// Delete berdasarkan nilai tertentu
void deleteByValue(LinkedList* list, int targetValue) {
    if (list->first == NULL) return;
    if (list->first->info == targetValue) {
        deleteAtFirst(list);
        return;
    }
    Node* temp = list->first;
    while (temp->next != NULL && temp->next->info != targetValue) {
        temp = temp->next;
    }
    if (temp->next != NULL) {
        Node* deleteNode = temp->next;
        temp->next = temp->next->next;
        free(deleteNode);
    }
}

// Modify node pertama
void modifyAtFirst (LinkedList* list, int newValue){
	if (list->first != NULL){
		list->first->info = newValue;
	}
}

void modifyAtLast(LinkedList* list, int newValue) {
    if (list->first == NULL) return;
    Node* temp = list->first;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->info = newValue;
}

// Modify sebelum node tertentu
void modifyBeforeBetween(LinkedList* list, int targetValue, int newValue) {
    if (list->first == NULL || list->first->info == targetValue) return;
    Node* temp = list->first;
    Node* prev = NULL;
    while (temp->next != NULL && temp->next->info != targetValue) {
        prev = temp;
        temp = temp->next;
    }
    if (prev != NULL) {
        prev->info = newValue;
    }
}

// Modify setelah node tertentu
void modifyAfterBetween(LinkedList* list, int targetValue, int newValue) {
    Node* temp = list->first;
    while (temp != NULL && temp->info != targetValue) {
        temp = temp->next;
    }
    if (temp != NULL && temp->next != NULL) {
        temp->next->info = newValue;
    }
}


// Modify berdasarkan nilai tertentu
void modifyByValue(LinkedList* list, int oldValue, int newValue) {
    Node* temp = list->first;
    while (temp != NULL) {
        if (temp->info == oldValue) {
            temp->info = newValue;
        }
        temp = temp->next;
    }
}

