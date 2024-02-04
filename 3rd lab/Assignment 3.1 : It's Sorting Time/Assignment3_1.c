// Kamin Jittapassorn 66070503409

#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node to store ID and score
typedef struct Node
{
    int id;
    int score;
    struct Node *next; // pointer to the next node
} Node;

void sortByID(Node **head);
void sortByScore(Node **head);
void printList(Node *head);
void inputList(Node **head, Node **tail);

int main()
{
    Node *head = NULL; // Pointer to the head node
    Node *tail = NULL; // Pointer to the tail node

    inputList(&head, &tail);

    int mode;
    scanf("%d", &mode); // Input the mode
    if (mode == 0)
    {
        sortByID(&head);
    }
    else if (mode == 1)
    {
        sortByScore(&head);
    }
    printList(head);
}

// Function to sort a list of nodes by ID from smaller to larger
void sortByID(Node **head)
{
    Node *current = *head; // Set the current node to the head node
    Node *temp = NULL;     // Set the temporary node to NULL
    int id, score;
    while (current != NULL) // Loop to sort the list
    {
        temp = current->next; // Set the temporary node to the next node of the current node
        while (temp != NULL)  // Loop to compare the current node with the temporary node
        {
            if (current->id > temp->id) // If the ID of the current node is greater than the ID of the temporary node
            {
                id = current->id;
                score = current->score;
                current->id = temp->id;
                current->score = temp->score;
                temp->id = id;
                temp->score = score;
            }
            temp = temp->next;
        }
        current = current->next;
    }
}

// Function to sort a list of nodes by score from smaller to larger
void sortByScore(Node **head)
{
    Node *current = *head; // Set the current node to the head node
    Node *temp = NULL;     // Set the temporary node to NULL
    int id, score;
    while (current != NULL) // Loop to sort the list
    {
        temp = current->next; // Set the temporary node to the next node of the current node
        while (temp != NULL)  // Loop to compare the current node with the temporary node
        {
            if (current->score > temp->score) // If the score of the current node is less than the score of the temporary node
            {
                id = current->id;
                score = current->score;
                current->id = temp->id;
                current->score = temp->score;
                temp->id = id;
                temp->score = score;
            }
            temp = temp->next;
        }
        current = current->next;
    }
}

// Function to print a list of nodes
void printList(Node *head)
{
    Node *current = head;   // Set the current node to the head node
    while (current != NULL) // Loop to print all nodes
    {
        printf("%d ",current->score); // Print the ID and score of the current node
        current = current->next;                        // Move to the next node
    }
    printf("\n");
}

// Function to input a list of nodes
void inputList(Node **head, Node **tail)
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) // Loop to input n nodes
    {
        Node *newNode = (Node *)malloc(sizeof(Node));  // Allocate memory for the new node
        scanf("%d %d", &newNode->id, &newNode->score); // Input the ID and score of the new node
        newNode->next = NULL;                          // Set the next pointer of the new node to NULL
        if (*head == NULL)                             // If the list is empty
        {
            *head = newNode; // Set the new node as the head node
            *tail = newNode; // Set the new node as the tail node
        }
        else // If the list is not empty
        {
            (*tail)->next = newNode; // Set the next pointer of the tail node to the new node
            *tail = newNode;         // Set the new node as the tail node
        }
    }
}