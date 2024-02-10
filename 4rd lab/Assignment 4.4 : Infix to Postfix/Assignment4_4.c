// Kamin Jittapassorn 66070503409

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 1000

char stack[SIZE];
int top = -1;

void push(char c) {
    if (top >= SIZE-1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = c;
}

char pop() {
    if (top < 0) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack[top--];
}

int precedence(char c) {
    switch(c) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}

void infixToPostfix(char* infix) {
    for (int i = 0; infix[i]; i++) {
        if (isalpha(infix[i])) {
            printf("%c", infix[i]);
        } else if (infix[i] == '(') {
            push(infix[i]);
        } else if (infix[i] == ')') {
            while (top != -1 && stack[top] != '(') {
                printf("%c", pop());
            }
            pop(); // remove '(' from stack
        } else {
            while (top != -1 && precedence(infix[i]) <= precedence(stack[top])) {
                printf("%c", pop());
            }
            push(infix[i]);
        }
    }
    while (top != -1) {
        printf("%c", pop());
    }
    printf("\n");
}

int main() {
    char infix[SIZE];
    fgets(infix, SIZE, stdin);
    infixToPostfix(infix);
    return 0;
}