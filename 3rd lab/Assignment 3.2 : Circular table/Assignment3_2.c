// Kamin Jittapassorn 66070503409

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next; // pointer to the next node
} Node;

void addElement(Node **head, Node **tail, int n);
void deleteElement(Node **head, int steps);
void printList(Node *head);

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    int n, steps;
    scanf("%d %d", &n, &steps);
    addElement(&head, &tail, n);
    // printList(head);
    deleteElement(&tail, steps);
    // printList(head);
}

void addElement(Node **head, Node **tail, int n)
{
    for (int i = 0; i < n; i++)
    {
        Node *newNode = (struct Node *)malloc(sizeof(Node));
        // User input
        int value;
        scanf("%d", &value);
        newNode->data = value;
        newNode->next = NULL;

        if (*head == NULL)
        {
            *head = newNode;
        }
        else
        {
            (*tail)->next = newNode;
        }
        *tail = newNode;
    }

    // Make the list circular
    (*tail)->next = *head;
}

// Function to print a list of nodes
void printList(Node *head)
{
    Node *current = head; // Set the current node to the head node
    do                    // Loop to print the list
    {
        printf("%d ", current->data); // Print the data of the current node
        current = current->next;      // Move to the next node
    } while (current != head);        // Loop until the current node is the head node
    printf("\n");
}

void deleteElement(Node **head, int steps)
{
    Node *current = *head;
    Node *temp = NULL;

    // Loop until only one element remains
    while (current->next != current)
    {
        // Traverse to the node before the one to be deleted
        for (int i = 0; i < steps - 1; i++)
        {
            current = current->next;
        }

        // Save the node to be deleted
        temp = current->next;

        // Update pointers to skip the node to be deleted
        current->next = temp->next;

        // If the head is the node to be deleted, update the head
        if (temp == *head)
        {
            *head = temp->next;
        }

        // Free the memory of the deleted node
        free(temp);
        // printList(*head);
    }
    printf("%d\n", current->data);
}
