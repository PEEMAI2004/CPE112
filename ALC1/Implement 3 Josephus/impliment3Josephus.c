#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

int josephus(int n, int k);
void push(Node **head, Node **tail, int value);
void pop(Node **head, Node **tail);
void printList(Node *head);

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        push(&head, &tail, i);
    }
    int survivor = josephus(n, k);
    printf("%d\n", survivor);
}

int josephus(int n, int k) {
    if (n > 1) {
        return (josephus(n-1, k) + k - 1) % n + 1;
    } else {
        return 1;
    }
}

void push(Node **head, Node **tail, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
        *tail = newNode;
    } else {
        (*tail)->next = newNode;
        *tail = newNode;
    }
    (*tail)->next = *head; // Connect tail to head to make the list circular
}

void pop(Node **head, Node **tail) {
    if (*head == NULL) {
        return;
    }
    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
    (*tail)->next = *head; // Update tail to point to the new head
}

void josephusPop(Node **head, Node **tail, int k) {
    
}

void printList(Node *head) {
    Node *current = head;
    do {
        printf("%d ", current->value);
        current = current->next;
    } while (current != head); // Traverse until we reach the head again
    printf("\n");
}