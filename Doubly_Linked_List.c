#include <stdio.h>
#include <stdlib.h>
#include "DB_LL.h"

//initialize empyt list
void initList(struct List* list) 
{
    list->head = NULL;
    list->tail = NULL;
    list-> count = 0;
}

//delete a list
void deleteList(struct List* list) 
{
    struct Node* current = list->head;
    while (current != NULL) {
        struct Node* next = current->next;
        free(current);
        current = next;
    }
    initList(list);
}

//add a new node to end of list
void pushBack(struct List* list, void* value) 
{
    //allocate memory for new node
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = list->tail;
    newNode->next = NULL;
    //if list is not empty, set the next pointer of the last node to the new node
    if (list->tail != NULL) {
        list->tail->next = newNode;
    }
    //set the tail pointer to the new node
    list->tail = newNode;
    //if list is empty, set the head pointer to the new node
    if (list->head == NULL) {
        list->head = newNode;
    }
    list->count++;
}

//dump contents of list
void dumpList(const struct List* list) 
{
    //start at the head of the list
    struct Node* current = list->head;
    //loop through the list
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

//add a new node to beginning of list
struct Node* findNode(const struct List* list, void* value) 
{
    struct Node* current = list->head;
    while (current != NULL) {
        if (current->data == value) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

//add a new node to beginning of list
void insertBefore(struct List* list, struct Node* target, void* value) 
{
    struct Node* newNode = malloc(sizeof(struct Node));
    //set data to value
    newNode->data = value;
        newNode->prev = target->prev;
    newNode->next = target;
    //if the target node is not the head, set the next pointer of the previous node to the new node, otherwise set the head pointer to the new node
    if (target->prev != NULL) {
        target->prev->next = newNode;
    } else { 
        list->head = newNode;
    }
    //set prev pointer of target node to new node
    target->prev = newNode;
    list->count++;
}

//add a new node to end of list
void insertAfter(struct List* list, struct Node* target, void* value) 
{
    struct Node* newNode = malloc(sizeof(struct Node));
    //set data to value
    newNode->data = value;
    newNode->prev = target;
    newNode->next = target->next;
    //opposite logic of insertBefore
    if (target->next != NULL) {
        target->next->prev = newNode;
    } else { 
        list->tail = newNode;
    }
    target->next = newNode;
}

//unlink node with given value from list
void unlinkNode(struct List* list, void* value) 
{
    //start at the head of the list
    struct Node* current = list->head;
    while (current != NULL) {
        if (current->data == value) {
            //if the current node is not the head, set the next pointer of the previous node to the next node
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                list->head = current->next;
            }
            //if the current node is not the tail, set the previous pointer of the next node to the previous node
            if (current->next != NULL) {
                current->next->prev = current->prev;
            } else {
                list->tail = current->prev;
            }
            //int saveData = current->data; add this when we get void* data
            //free the memory used by the current node
            free(current);
            list->count--;
            return;
            //return savedData;
        }
        current = current->next;
    }
}

//sort list in ascending order
void sortList(struct List* list) {
    int swapped;
    struct Node* current;
    struct Node* last = NULL;
    //check if list is empty
    do {
        swapped = 0;
        current = list->head;
        //loop through list
        while (current->next != last) {
            //swap adjacent nodes if they are out of order
            if (current->data > current->next->data) {
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = 1;
            }
            //move to next node
            current = current->next;
        }
        last = current;
        //repeat until no swaps are made
    } while (swapped);
}
