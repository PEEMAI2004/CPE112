// Kamin Jittapassorn 66070503409

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void inputElements(int n, Node **head, Node **tail);
void removeLeftNode(Node **head);
void removeRightNode(Node **head);
void removeNodewithValue(Node **head, int value);
void printList(Node *head);

int main()
{
    int n;
    // Get number of nodes
    scanf("%d", &n);
    // Initialize head and tail
    Node *head = NULL;
    Node *tail = NULL;

    // Get elements
    inputElements(n, &head, &tail);

    char command;
    while (1)
    { // Loop until break
        // Get command
        scanf(" %c", &command);
        if (command == 'F')
        {
            removeLeftNode(&head);
        }
        else if (command == 'L')
        {
            removeRightNode(&head);
        }
        else if (command == 'N')
        {
            int value;
            scanf("%d", &value); // Get value to remove
            removeNodewithValue(&head, value);
        }
        else
        {
            break;
        }
    }

    // Print list
    printList(head);

    return 0;
}

void inputElements(int n, Node **head, Node **tail)
{
    // Loop to get all elements
    for (int i = 0; i < n; i++)
    {
        int value;
        scanf("%d", &value);
        // create new node
        Node *newNode = (struct Node *)malloc(sizeof(Node));
        newNode->data = value; // set data
        newNode->next = NULL;  // set next to NULL

        if (*head == NULL)
        {                    // If head is NULL, set head and tail to newNode
            *head = newNode; // set head to newNode
            *tail = newNode; // set tail to newNode
        }
        else
        { // If head is not NULL, set tail->next to newNode and set tail to newNode
            (*tail)->next = newNode;
            *tail = newNode;
        }
    }
}

void printList(Node *head)
{
    Node *current = head; // Set current to head
    if (current == NULL)
    { // If head is NULL, print none
        printf("none\n");
        return;
    }
    while (current != NULL)
    { // Loop through linked list and print data of each node if not null
        printf("%d ", current->data);
        current = current->next; // Move to next node
    }

    printf("\n");
}
// Function to remove left node
void removeLeftNode(Node **head)
{
    if (*head == NULL)
    {           // If head is NULL, do nothing
        return; // No elements left, do nothing
    }
    Node *temp = *head;    // Set temp to head
    *head = (*head)->next; // Set head to next node
    free(temp);            // Free temp
}
// Function to remove right node
void removeRightNode(Node **head)
{
    if (*head == NULL)
    { // If head is NULL, do nothing
        return;
    }
    Node *current = *head; // Set current to head
    if (current->next == NULL)
    {                  // If next of current is NULL
        *head = NULL;  // Only one element left, set head to NULL
        free(current); // Free current
        return;
    }
    while (current->next->next != NULL)
    {                            // Loop until next of next of current is NULL
        current = current->next; // Set current to next of current
    }
    Node *temp = current->next; // Set temp to next of current
    current->next = NULL;       // Set next of current to NULL
    free(temp);                 // Free temp
}
// Function to remove node with value
void removeNodewithValue(Node **head, int value)
{
    Node *current = *head; // Set current to head
    Node *prev = NULL;     // Set prev to NULL
    while (current != NULL)
    { // Loop until current is NULL
        if (current->data == value)
        { // If data of current is equal to value
            if (prev == NULL)
            {                          // If prev is NULL
                *head = current->next; // Set head to next of current
            }
            else
            {                               // If prev is not NULL
                prev->next = current->next; // Set next of prev to next of current
            }
            free(current); // Free current
            return;
        }
        prev = current;          // Set prev to current
        current = current->next; // Set current to next of current
    }
}
