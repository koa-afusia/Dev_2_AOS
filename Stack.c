#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#include "DB_LL.h"

void initStack(struct Stack* stack) 
{
    stack->myList.head = NULL;
    stack->myList.tail = NULL;
    stack->top = -1;
}

void push(struct Stack *stack, void* value) 
{
    //call pushback from DB_LL.h
    pushBack(&stack->myList, value);
    stack->top++;
}
//void* -> memory manager 
int pop(struct Stack *stack) 
{
    //stack empty? return -1
    if (isEmpty(stack)) 
    {
        printf("Stack is empty\n");
        return -1; //error message, needed
    }

    void* value = stack->myList.tail->data;
    //call unlinkNode from DB_LL.h
    unlinkNode(&stack->myList, value);
    stack->top--;
    return value;
}

//return value at top of stack
int peek(struct Stack* stack) 
{
    //maybe delete this function because we already have isEmpty
    if (isEmpty(stack)) 
    {
        return 0;
    }
    return stack->myList.head->data;
}

int isEmpty(struct Stack* stack) 
{
    return stack->myList.head == NULL;
}
