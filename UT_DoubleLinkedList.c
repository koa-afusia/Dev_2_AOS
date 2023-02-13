#include <stdio.h>
#include <stdlib.h>
#include "DB_LL.h"
#include <assert.h>

void test_initList() {
struct List list;
initList(&list);
assert(list.head == NULL);
assert(list.tail == NULL);
assert(list.count == 0);
}

void test_deleteList() {
struct List list;
initList(&list);
pushBack(&list, 10);
pushBack(&list, 20);
pushBack(&list, 30);
deleteList(&list);
assert(list.head == NULL);
assert(list.tail == NULL);
assert(list.count == 0);
}

void test_pushBack() {
struct List list;
initList(&list);
pushBack(&list, 10);
pushBack(&list, 20);
pushBack(&list, 30);
assert(list.count == 3);
assert(list.head->data == 10);
assert(list.tail->data == 30);
assert(list.head->next->data == 20);
assert(list.tail->prev->data == 20);
}

void test_findNode() {
struct List list;
initList(&list);
pushBack(&list, 10);
pushBack(&list, 20);
pushBack(&list, 30);
struct Node* node = findNode(&list, 20);
assert(node->data == 20);
node = findNode(&list, 40);
assert(node == NULL);
}

void test_insertBefore() {
struct List list;
initList(&list);
pushBack(&list, 10);
pushBack(&list, 20);
pushBack(&list, 30);
struct Node* node = findNode(&list, 20);
insertBefore(&list, node, 15);
assert(list.count == 4);
assert(list.head->next->data == 15);
}

void test_insertAfter() {
struct List list;
initList(&list);
pushBack(&list, 10);
pushBack(&list, 20);
pushBack(&list, 30);
struct Node* node = findNode(&list, 20);
insertAfter(&list, node, 25);
assert(list.count == 4);
assert(list.head->next->next->data == 25);
}

void test_unlinkNode() {
struct List list;
initList(&list);
pushBack(&list, 10);
pushBack(&list, 20);
pushBack(&list, 30);
unlinkNode(&list, 20);
assert(list.count == 2);
assert(list.head->next->data == 30);
}

int main() {
test_initList();
test_deleteList();
test_pushBack();
test_findNode();
test_insertBefore();
test_insertAfter();
test_unlinkNode();
return 0;
}



