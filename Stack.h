#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include "DB_LL.h"


struct Stack 
{
    struct List myList;
    int top;
};

void initStack(struct Stack* stack);

void push(struct Stack *stack, int value);

int pop(struct Stack *stack);

int peek(struct Stack* stack);

int isEmpty(struct Stack* stack);

#endif
