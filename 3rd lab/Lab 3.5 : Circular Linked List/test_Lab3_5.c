#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next; // pointer to the next node
} Node;

void insertElement(Node **head, Node **tail);
void deleteElement(Node **head, Node **tail);
void printList(Node **head);

int main()
{
    Node *head = NULL; // Pointer to the head node
    Node *tail = NULL; // Pointer to the tail node
    char command;
    
    // Test 1: Insert and delete an element
    printf("Test 1:\n");
    insertElement(&head, &tail);
    deleteElement(&head, &tail);
    printList(&head);
    
    // Test 2: Terminate the program with an empty list
    printf("Test 2:\n");
    char command2 = 'E';
    while (1)
    {
        command = command2;
        if (command == 'E')// Terminate the program
        {
            break;
        }
    }
    printList(&head);
}

void printList(Node **head)
{
    // In case of empty list
    if (*head == NULL)
    {
        printf("Empty\n");
        return;
    }
    Node *current = *head;
    if (*head != NULL)
    {
        do
        {
            printf("%d ", current->data);
            current = current->next;
        } while (current != *head);
    }
    printf("\n");
}

void insertElement(Node **head, Node **tail)
{
    int value;
    printf("Enter a value to insert: ");
    scanf(" %d", &value); // Add a space before %d to consume any leading whitespace characters
    Node *newNode = (Node *)malloc(sizeof(Node)); // Allocate memory for the new node
    newNode->data = value;                        // Set the data of the new node
    if (*head == NULL)                            // If the list is empty
    {
        *head = newNode;       // Set the new node as the head node
        *tail = newNode;       // Set the new node as the tail node
        newNode->next = *head; // Set the next pointer of the new node to the head node
    }
    else // If the list is not empty
    {
        newNode->next = *head;   // Set the next pointer of the new node to the head node
        (*tail)->next = newNode; // Set the next pointer of the tail node to the new node
        *tail = newNode;         // Set the new node as the tail node
    }
}

void deleteElement(Node **head, Node **tail)
{
    int value;
    printf("Enter a value to delete: ");
    scanf("%d", &value);
    Node *current = *head;
    Node *prev = *tail;
    if (*head != NULL)
    {
        do
        {
            if (current->data == value) // If the current node has the same data as the given value
            {
                if (current == *head) // If the current node is the head node
                {
                    *head = current->next; // Set the head node to the next node of the current node
                    (*tail)->next = *head; // Set the next pointer of the tail node to the head node
                }
                else if (current == *tail) // If the current node is the tail node
                {
                    *tail = prev;          // Set the tail node to the previous node of the current node
                    (*tail)->next = *head; // Set the next pointer of the tail node to the head node
                }
                else // If the current node is neither the head node nor the tail node
                {
                    prev->next = current->next; // Set the next pointer of the previous node to the next node of the current node
                }
                free(current); // Free the memory of the current node
                break;
            }
            prev = current;          // Set the previous node to the current node
            current = current->next; // Set the current node to the next node
        } while (current != *head);
    }
    if (*head == NULL) // If no elements left after deletion
    {
        *tail = NULL; // Set tail to NULL
    }
}