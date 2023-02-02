#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

//node in linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

//entire linked list
struct List {
    struct Node* head;
    struct Node* tail;
    int count;
};

//initialize empyt list
void initList(struct List* list);

//delete a list
void deleteList(struct List* list);

//add a new node to end of list
void pushBack(struct List* list, int value);

//dump contents of list
void dumpList(const struct List* list);

//find node with given value
struct Node* findNode(const struct List* list, int value);

//add a new node before target node
void insertBefore(struct List* list, struct Node* target, int value);

//add a new node after target node
void insertAfter(struct List* list, struct Node* target, int value);

//unlink node with given value from list
void unlinkNode(struct List* list, int value);

//sort list in ascending order
void sortList(struct List* list);

#endif
