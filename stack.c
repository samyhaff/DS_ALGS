# include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define STACK_LENGTH 5

typedef struct {
    int array[STACK_LENGTH];
    int top;
} stack;

int push(stack *stack, int value) {
    if (stack->top >= STACK_LENGTH-1) return false;
    stack->top++;
    stack->array[stack->top] = value;
    return true;
}

int pop(stack *stack) {
    if (stack->top == -1) return INT_MIN;
    return stack->array[stack->top--];
}

int main() {
    stack mystack = {.array = {}, .top = -1};
    push(&mystack, 1);
    push(&mystack, 2);

    int top = pop(&mystack);
    printf("top = %d\n", top);
}
