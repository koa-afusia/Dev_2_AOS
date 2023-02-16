# C Data Structures
[![standard-readme compliant](https://img.shields.io/badge/readme%20style-standard-brightgreen.svg?style=flat-square)](https://github.com/RichardLitt/standard-readme)

Creates two basic data structures: Doubly Linked List and Stack written in C language

## Table of Contents
- [Structures](#structures)
- [Functions](#functions)
     - [Doubly Linked List](##doublylinkedlist)
     - [Stack](##stack)
- [Usage](#usage)
- [Maintainers](#maintainers)
- [Contributing](#contributing)

## Stuctures
```
% structs node in the linked list
struct Node 
{
    int data;
    struct Node* prev;
    struct Node* next;
};

% structs entire linked list
struct List 
{
    struct Node* head;
    struct Node* tail;
    int count;
};
```

## Functions
We essentially have a few functions that helps us modify the doubly linked list in different ways. We have functions that allow us to insert nodes before or after a target, destroy the list, find specific nodes within the list, and sorting the list by value. There are a few other functions we have created as well. As far as the stack goes, we also have a few functions that allows us to push and pop values on or off the stack and we are able to return a value from the stack. And of course, we have a function that allows us to check if the doubly linked list/stack is empty or not.

### - Doubly Linked List
```    
        //initializes an empty list
        void initList(struct List* list);

        //deletes a list
        void deleteList(struct List* list);

        //adds a new node to end of list
        void pushBack(struct List* list, int value);

        //dump contents of list
        void dumpList(const struct List* list);

        //finds node with given value
        struct Node* findNode(const struct List* list, int value);

        //adds a new node before target node
        void insertBefore(struct List* list, struct Node* target, int value);

        //adds a new node after target node
        void insertAfter(struct List* list, struct Node* target, int value);

        //unlink node with given value from list
        void unlinkNode(struct List* list, int value);

        //sorts list in ascending order
        void sortList(struct List* list);

```

### - Stack
```
//initializes the stack 
void initStack(struct Stack* stack);

//pushes a value onto the stack
void push(struct Stack *stack, int value);

//pops a value off of the stack
int pop(struct Stack *stack);

//return value at the top of the stack
int peek(struct Stack* stack);

//checks if the stack is empty
int isEmpty(struct Stack* stack);
```

## Usage
In order to run the program, you can open the files in visual studio code and run it through the C language compiler extension within visual studio code. Run the doublylinkedlist file and the stack file in VSC C language compiler in order to get the result.


## Maintainers
[@Ridgew120](https://github.com/Ridgew120)
[@hteston](https://github.com/hteston)
[@koa-afusia](https://github.com/koa-afusia)

## Contributing
These files were written for our C Data Structures project for the Advanced Operating Systems class

