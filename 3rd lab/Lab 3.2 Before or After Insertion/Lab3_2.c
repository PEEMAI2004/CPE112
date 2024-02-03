// Kamin Jittapassorn 66070503409

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void insertAfter(struct Node *prevNode, int newData);
void insertBefore(struct Node **headRef, struct Node *nextNode, int newData);
void printList(struct Node *node);
void freeList(struct Node *node);

int main()
{
    // get the number of elements in the list
    int n;
    scanf("%d", &n);

    struct Node *head = NULL;
    struct Node *tail = NULL;

    // get the elements of the list
    for (int i = 0; i < n; i++)
    {
        int data;
        scanf("%d", &data); // get the data of the current node

        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); // create a new node
        newNode->data = data;                                              // set the data of the new node
        newNode->next = NULL;                                              // set the next of the new node to NULL

        if (head == NULL) // if the list is empty
        {
            head = newNode; // set the head to the new node
            tail = newNode; // set the tail to the new node
        }
        else
        {
            tail->next = newNode; // set the next of the tail to the new node
            tail = newNode;       // set the tail to the new node
        }
    }

    char command;
    while (scanf(" %c", &command) == 1) // while there are commands
    {
        if (command == 'A') // if the command is 'A'
        {
            int afterData, newData;               // get the data of the node after which the new node will be inserted and the data of the new node
            scanf("%d %d", &afterData, &newData); // get the data of the node after which the new node will be inserted and the data of the new node

            struct Node *currentNode = head; // set the current node to the head
            while (currentNode != NULL)      // while the current node is not NULL
            {
                if (currentNode->data == afterData) // if the data of the current node is equal to the data of the node after which the new node will be inserted
                {
                    insertAfter(currentNode, newData); // insert the new node after the current node
                    break;
                }
                currentNode = currentNode->next; // set the current node to the next node
            }
        }
        else if (command == 'B') // if the command is 'B'
        {
            int beforeData, newData;
            scanf("%d %d", &beforeData, &newData); // get the data of the node before which the new node will be inserted and the data of the new node

            struct Node *currentNode = head; // set the current node to the head
            struct Node *prevNode = NULL;    // set the previous node to NULL
            while (currentNode != NULL)      // while the current node is not NULL
            {
                if (currentNode->data == beforeData) // if the data of the current node is equal to the data of the node before which the new node will be inserted
                {
                    insertBefore(&head, currentNode, newData); // insert the new node before the current node
                    break;
                }
                prevNode = currentNode;          // set the previous node to the current node
                currentNode = currentNode->next; // set the current node to the next node
            }
        }
        else if (command == 'E') // if the command is 'E'
        {
            break; // break the loop
        }
    }

    printList(head); // print the list
    freeList(head);  // free the list
    return 0;
}
// Function to insert a new node after a given node
void insertAfter(struct Node *prevNode, int newData)
{
    if (prevNode == NULL) // if the previous node is NULL
    {
        return; // return
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); // create a new node
    newNode->data = newData;                                           // set the data of the new node
    newNode->next = prevNode->next;                                    // set the next of the new node to the next of the previous node
    prevNode->next = newNode;                                          // set the next of the previous node to the new node
}
// Function to insert a new node before a given node
void insertBefore(struct Node **headRef, struct Node *nextNode, int newData)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); // create a new node
    newNode->data = newData;                                           // set the data of the new node
    newNode->next = nextNode;                                          // set the next of the new node to the next node

    if (*headRef == nextNode) // if the next node is the head
    {
        *headRef = newNode; // set the head to the new node
    }
    else // if the next node is not the head
    {
        struct Node *currentNode = *headRef;  // set the current node to the head
        while (currentNode->next != nextNode) // while the next of the current node is not the next node
        {
            currentNode = currentNode->next; // set the current node to the next node
        }
        currentNode->next = newNode; // set the next of the current node to the new node
    }
}
// Function to print the list
void printList(struct Node *node)
{
    while (node != NULL) // while the node is not NULL
    {
        printf("%d ", node->data); // print the data of the node
        node = node->next;         // set the node to the next node
    }
}
// Function to free the list
void freeList(struct Node *node)
{
    struct Node *tmp;    // create a temporary node
    while (node != NULL) // while the node is not NULL
    {
        tmp = node;        // set the temporary node to the node
        node = node->next; // set the node to the next node
        free(tmp);         // free the temporary node
    }
}
