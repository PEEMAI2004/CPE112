// Kamin Jittapassorn 66070503409

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *array;
    int top;
    int max_size;
} Stack;		

// Function prototypes
Stack* createStack(int size);
bool push(Stack* stack, int value);
bool pop(Stack* stack);
bool show(Stack* stack);
bool isFull(Stack* stack);
bool isEmpty(Stack* stack);

int main() {
    int n;
    scanf("%d", &n);
    if (n <= 0) {
        printf("Please enter a positive number.");
        return 0;
    }
    // Create a stack
    Stack* stack = createStack(n);

    int c;
    while (true)
    {
        scanf("%d", &c);
        switch (c)
        {
        case 1: // Push
            int value;
            scanf("%d", &value);
            if (push(stack, value)) {
                break;
            }
            else { 
                return 0;
            }
            break;
        case 2: // Pop
            if (pop(stack)) {
                break;
            }
            else {
                return 0;
            }
            break;
        case 3: // Show
            show(stack);
            return 0;
        case 4: // Exit
            printf("Exiting...");
            return 0;
            break;
        
        default:
            printf("Invalid choice.");
            return 0;
        }
    }
    
}

// Function to create a stack of given n
Stack* createStack(int size) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->max_size = size;
    stack->top = -1;
    stack->array = (int*)malloc(stack->max_size * sizeof(int));
    return stack;
}

// Function to add an element to the stack
bool push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack Overflow.\n");
        return false;
    }
    stack->array[++stack->top] = value;
    return true;
}

// Function to remove an element from the stack
bool pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow.\n");
        return false;
    }
    // remove the top element
    stack->top--;
    return true;
}

// Function to show the top element of the stack
bool show(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return false;
    }
    // show all elements in the stack from top to bottom
    for (int i = stack->top; i >= 0; i--) {
        printf("%d\n", stack->array[i]);
    }

    return true;
}

// Function to check if the stack is full
bool isFull(Stack* stack) {
    return stack->top == stack->max_size - 1;
}

// Function to check if the stack is empty
bool isEmpty(Stack* stack) {
    return stack->top == -1;
}
