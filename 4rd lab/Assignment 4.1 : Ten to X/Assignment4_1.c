// Kamin Jittapassorn 66070503409

#include <stdio.h>
#include <stdlib.h>

char stack[100];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

void convertToBaseX(int n, int x) {
    if (n < 0 || x < 2 || x > 36) {
        printf("invalid\n");
        return;
    }

    while (n > 0) {
        int remainder = n % x;
        char c;
        if (remainder < 10) {
            c = remainder + '0';
        } else {
            c = remainder - 10 + 'A';
        }
        push(c);
        n /= x;
    }

    while (top != -1) {
        printf("%c", pop());
    }
    printf("\n");
}

int main() {
    int n, x;
    scanf("%d", &n);
    scanf("%d", &x);
    convertToBaseX(n, x);
    return 0;
}