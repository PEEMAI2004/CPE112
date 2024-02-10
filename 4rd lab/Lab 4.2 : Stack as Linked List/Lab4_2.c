// Kamin Jittapassorn 66070503409

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next; // pointer to the next node
} Node;

void push(Node **head, int value);
void pop(Node **head);
void top(Node *head);
void empty(Node *head);

int main()
{
    Node *head = NULL;          // Pointer to the head node
    while (1)
    {
        char c = getchar();
        if (c == 'p')
        {
            int value;
            scanf("%d", &value);
            push(&head, value);
        }
        else if (c == 'o')
        {
            pop(&head);
        }
        else if (c == 't')
        {
            top(head);
        }
        else if (c == 'e')
        {
            empty(head);
        } else if (c == 'q')
        {
            break;
        }
        // Clear the input buffer
        while (getchar() != '\n');
    }
}

// Function to add a new node to the list
void push(Node **head, int value)
{
    // Create a new node
    Node *newNode = (struct Node *)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;

    // Add the new node to the list
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        // Seek to find the last node
        Node *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to remove the last node from the list
void pop(Node **head)
{
    if (*head == NULL)
    {
        printf("empty\n");
        return;
    }
    else if ((*head)->next == NULL)
    {
        // Only one node in the list
        Node *temp = *head;
        printf("%d\n", temp->value);
        free(temp);
        *head = NULL;
        return;
    }
    else
    {
        // Seek to find the second last node
        Node *current = *head;
        while (current->next->next != NULL)
        {
            current = current->next;
        }
        // Print the value of the last node
        Node *temp = current->next;
        printf("%d\n", temp->value);
        // Remove the last node
        free(temp);
        current->next = NULL;
    }
}

// Function to print the last node of the list
void top(Node *head)
{
    if (head == NULL)
    {
        printf("empty\n");
        return;
    }
    // Seek to find to node
    Node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    printf("%d\n", current->value);
}

// Function to check if the list is empty
void empty(Node *head)
{
    if (head == NULL)
    {
        printf("1\n");
    }
    else
    {
        printf("0\n");
    }
}
