// Kamin Jittapassorn 66070503409

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int data;
    struct Node *next; // pointer to the next node
    struct Node *prev; // pointer to the previous node
} Node;

void addElement(Node **head, Node **tail);
void deleteElement(Node **head, Node **tail);
void findNeighbourElement(Node **head);
void printList(Node **head, Node **tail);

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    char command[4];
    while (1)
    {
        scanf("%s", command);
        if (strcmp(command, "ADD") == 0) // Add a new element to the list
        {
            addElement(&head, &tail);
        }
        else if (strcmp(command, "DEL") == 0) // Delete the first element
        {
            deleteElement(&head, &tail);
        }
        else if (strcmp(command, "SCH") == 0) // Find the previous and next element of the given value
        {
            findNeighbourElement(&head);
        }
        else if (strcmp(command, "END") == 0) // Terminate the program
        {
            break;
        }
    }
    printList(&head, &tail);
}
// Function to add a new element to the list
void addElement(Node **head, Node **tail)
{
    int value;
    scanf("%d", &value);
    Node *newNode = (struct Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;  // Set the next pointer of the new node to NULL
    newNode->prev = *tail; // Set the previous pointer of the new node to the current tail node

    if (*head == NULL) // If the list is empty
    {
        *head = newNode; // Set the head pointer to the new node
    }
    else // If the list is not empty
    {
        (*tail)->next = newNode; // Set the next pointer of the current tail node to the new node
    }
    *tail = newNode; // Update the tail pointer to the new node
}
// Function to delete the first element that contain given number of the list
void deleteElement(Node **head, Node **tail)
{
    int value;
    scanf("%d", &value);
    Node *current = *head;
    while (current != NULL) // Loop through the list
    {
        if (current->data == value) // If the current node contains the given value
        {
            if (current->prev != NULL) // If the current node is not the first node
            {
                current->prev->next = current->next; // Set the next pointer of the previous node to the next node of the current node
            }
            else // If the current node is the first node
            {
                *head = current->next; // Set the head pointer to the next node of the current node
            }
            if (current->next != NULL) // If the current node is not the last node
            {
                current->next->prev = current->prev; // Set the previous pointer of the next node to the previous node of the current node
            }
            else // If the current node is the last node
            {
                *tail = current->prev; // Set the tail pointer to the previous node of the current node
            }
            free(current);
            return;
        }
        current = current->next;
    }
}

void findNeighbourElement(Node **head)
{
    if (*head == NULL || (*head)->next == NULL) // If the list is empty or contains only one element
    {
        printf("none\n");
        return;
    }
    int value;
    scanf("%d", &value);
    Node *current = *head;
    while (current != NULL) // Loop through the list
    {
        if (current->data == value) // If the current node contains the given value
        {
            if (current->prev != NULL) // If the current node is not the first node
            {
                printf("%d ", current->prev->data); // Print the previous node's data
            }
            else // If the current node is the first node
            {
                printf("NULL ");
            }
            if (current->next != NULL) // If the current node is not the last node
            {
                printf("%d\n", current->next->data); // Print the next node's data
            }
            else // If the current node is the last node
            {
                printf("NULL\n");
            }
            return;
        }
        current = current->next;
    }
    if (current == NULL) // If the given value is not found in the list
    {
        printf("none\n");
    }
}

void printList(Node **head, Node **tail)
{
    if (*head == NULL) // If the list is empty
    {
        printf("none\nnone\n");
        return;
    }
    Node *current = *head;
    while (current != NULL) // Loop through the list
    {
        printf("%d ", current->data); // Print the data of the current node
        current = current->next;      // Move to the next node
    }
    printf("\n");
    current = *tail; // Reset the current pointer to the head
    while (current != NULL) // Loop through the list
    {
        printf("%d ", current->data); // Print the data of the current node
        current = current->prev;      // Move to the previous node
    }
    printf("\n");
}