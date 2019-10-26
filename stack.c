#include"stack.h"

Stack* createStack(int capacity){
    Stack* stack = (Stack*)malloc(sizeof(Stack)); 
    stack->capacity = capacity; 
    stack->top = -1; 
    stack->task = (int*)malloc(stack->capacity * sizeof(int)); 
    stack->values = (int*)malloc(stack->capacity * sizeof(int)); 
    return stack; 
}

int isFull(Stack* stack){ 
    return stack->top == stack->capacity - 1; 
} 

int isEmpty(Stack* stack){ 
    return stack->top == -1; 
}

void push(Stack* stack, int t, int item){ 
    if (isFull(stack)){
        return;
    }
    int newTop = ++stack->top;

    stack->task[newTop] = t;
    stack->values[newTop] = item;

    printf("%d pushed to stack\n", item); 
}

int pop(Stack* stack){ 
    if (isEmpty(stack))
        return 0; 
    stack->top = stack->top - 1;
    return 1; 
} 