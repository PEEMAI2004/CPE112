// Kamin Jittapassorn 66070503409

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    char *array;
    int top;
    int max_size;
} Stack;

void isBalanced(char *str);
Stack* createStack(int size);
bool push(Stack* stack, char value);
bool pop(Stack* stack);
bool isFull(Stack* stack);
bool isEmpty(Stack* stack);
bool isMatchingPair(char opening, char closing);

int main() {
    char str[1000];
    scanf("%s", str);
    isBalanced(str);
    return 0;
}

void isBalanced(char *str) {
    int n = 0;
    while (str[n] != '\0') {
        n++;
    }
    Stack* stack = createStack(n);
    for (int i = 0; i < n; i++) {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            push(stack, str[i]);
        } else if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
            if (isEmpty(stack) || !isMatchingPair(stack->array[stack->top], str[i])) {
                printf("The string is not balanced\n");
                return;
            }
            pop(stack);
        }
    }
    if (isEmpty(stack)) {
        printf("The string is balanced\n");
    } else {
        printf("The string is not balanced\n");
    }
}

Stack* createStack(int size) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->array = (char*)malloc(size * sizeof(char));
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

bool isMatchingPair(char opening, char closing) {
    if (opening == '(' && closing == ')') {
        return true;
    } else if (opening == '{' && closing == '}') {
        return true;
    } else if (opening == '[' && closing == ']') {
        return true;
    }
    return false;
}
