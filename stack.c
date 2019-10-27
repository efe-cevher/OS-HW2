#include<stdio.h>
#include<stdlib.h>

#include"stack.h"

/* Initialize stack */
Stack* createStack(int capacity){
    Stack* stack = (Stack*)malloc(sizeof(Stack)); 
    stack->capacity = capacity; 
    stack->top = -1; 
    stack->task = (int*)malloc(stack->capacity * sizeof(int)); 
    stack->values = (int*)malloc(stack->capacity * sizeof(int)); 
    return stack; 
}

int isFull(Stack* stack){ 
    return stack->top == stack->capacity - 1; // returns 0 if it is false, else it is true
} 

int isEmpty(Stack* stack){ 
    return stack->top == -1; // returns 0 if it is false, else it is true
}

void push(Stack* stack, int t, int item){
    /* Check if stack is full before push */
    if (isFull(stack)){
        printf("Stack is full, cannot push");
        return;
    }
    int newTop = ++stack->top; // increment top
    
    /* Add new task and value */
    stack->task[newTop] = t; 
    stack->values[newTop] = item;
}

int pop(Stack* stack){ 
    /* Check stack is empty before pop*/
    if (isEmpty(stack)){
        return 0;
    }
    stack->top--; // decrement top
    return 1; 
}