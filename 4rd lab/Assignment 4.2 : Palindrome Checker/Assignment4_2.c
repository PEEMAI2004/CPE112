// Kamin Jittapassorn 66070503409

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *array;
    int top;
    int max_size;
} Stack;

void isPalindrome(char *str);
Stack* createStack(int size);
bool push(Stack* stack, char value);
bool pop(Stack* stack);
bool isFull(Stack* stack);
bool isEmpty(Stack* stack);

int main() {
    char str[100];
    scanf("%s", str);
    isPalindrome(str);
    return 0;
}

void isPalindrome(char *str) {
    int n = 0;
    while (str[n] != '\0') {
        n++;
    }
    Stack* stack = createStack(n);
    for (int i = 0; i < n; i++) {
        push(stack, str[i]);
    }
    for (int i = 0; i < n; i++) {
        if (str[i] != stack->array[stack->top]) {
            printf("no\n");
            return;
        }
        pop(stack);
    }
    printf("yes\n");
}

Stack* createStack(int size) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->array = (int*)malloc(size * sizeof(int));
    stack->top = -1;
    stack->max_size = size;
    return stack;
}

bool push(Stack* stack, char value) {
    if (isFull(stack)) {
        printf("Stack is full\n");
        return false;
    }
    stack->array[++stack->top] = value;
    return true;
}

bool pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return false;
    }
    stack->top--;
    return true;
}

bool isFull(Stack* stack) {
    return stack->top == stack->max_size - 1;
}

bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

