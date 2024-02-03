// Kamin Jittapassorn 66070503409

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void HeadInsert(int data, Node **head, Node **tail);
void TailInsert(int data, Node **head, Node **tail);

int main()
{
    int n, option;
    // get number of elements
    scanf("%d", &n);
    if (n <= 0)
    {
        printf("Invalid\n");
        return 0;
    }
    // get option
    scanf("%d", &option);
    if (option != 1 && option != 2)
    {
        printf("Invalid\n");
        return 0;
    }

    // initialize head and tail
    Node *head = NULL; // pointer to head of linked list (initialize to null)
    Node *tail = NULL; // pointer to tail of linked list (initialize to null)

    // get data and insert to linked list
    for (int i = 0; i < n; i++)
    {
        int data;
        scanf("%d", &data);
        if (option == 1) // if option is 1, insert to head
        {
            HeadInsert(data, &head, &tail);
        }
        else // if option is 2, insert to tail
        {
            TailInsert(data, &head, &tail);
        }
    }

    // print linked list
    Node *current = head;
    while (current != NULL) // loop through linked list and print data of each node if not null
    {
        printf("%d ", current->data); // print data
        current = current->next;      // move to next node
    }
    printf("\n");
}

// HeadInsert function
void HeadInsert(int data, Node **head, Node **tail)
{
    Node *newNode = (Node *)malloc(sizeof(Node)); // allocate memory for new node
    newNode->data = data;                         // set data
    newNode->next = *head;                        // set next to current head
    *head = newNode;                              // set head to new node
    if (*tail == NULL) // if tail is null, set tail to new node
    { 
        *tail = newNode;
    }
}

// TailInsert function
void TailInsert(int data, Node **head, Node **tail)
{
    Node *newNode = (Node *)malloc(sizeof(Node)); // allocate memory for new node
    newNode->data = data;                         // set data
    newNode->next = NULL;                         // set next to null
    if (*tail != NULL)
    { // if tail is not null, set tail's next to new node
        (*tail)->next = newNode;
    }
    *tail = newNode;   // set tail to new node
    if (*head == NULL) // if head is null, set head to new node
    {
        *head = newNode;
    }
}
