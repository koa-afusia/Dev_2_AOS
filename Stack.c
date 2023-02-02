#include <stdio.h>
#include <stdlib.h>
#include "DB_LL.h"

struct Stack {
struct List myList;
int top;
};


void push(struct Stack *stack, int value) {
//call pushback from DB_LL
pushBack(&stack->myList, value);
stack->top++;
}

int pop(struct Stack *stack) {
//stack empty? return -1
if (isEmpty(stack)) {
printf("Stack is empty\n");
return -1;
}

int value = stack->myList.head->data;
//call unlinkNode from DB_LL
unlinkNode(&stack->myList, value);
stack->top--;
return value;
}

//return value at top of stack
int peek(struct Stack* stack) {
//maybe delete this function because we already have isEmpty
if (isEmpty(stack)) {
return 0;
}
return stack->myList.head->data;
}

/*int isEmpty(struct Stack* stack) {
return stack->myList.head == NULL;
} */

int main() {
struct Stack stack;
stack.top = -1;

push(&stack, 1);
push(&stack, 2);
push(&stack, 3);

printf("%d\n", pop(&stack));
printf("%d\n", pop(&stack));
printf("%d\n", pop(&stack));

return 0;
}