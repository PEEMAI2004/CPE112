#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;  
    struct Node *next;
} Node;

void inputList(Node **head, Node **tail, int value);
void deleteFirstNode(Node **head, Node **tail);
void printList(Node *head);

int main() {
    Node *head = NULL;
    Node *tail = NULL;

    int command;
    int value;
    while (1) {
        scanf("%d", &command);
        if (command == 0) {
            break;
        }
        if (command == 1) {
            scanf("%d", &value);
            inputList(&head, &tail, value);
            printf("Node with value %d is added\n", value);
        }
        if (command == 2) {
            deleteFirstNode(&head, &tail);
            printf("First node is deleted\n");
        }
        if (command == 3) {
            printf("List: ");
            printList(head);
        }
    }
}

void inputList(Node **head, Node **tail, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    if (*head == NULL)
    {
        *head = newNode;
        *tail = newNode;
    }
    else
    {
        (*tail)->next = newNode;
        *tail = newNode;
    }
}

void deleteFirstNode(Node **head, Node **tail)
{
    if (*head == NULL)
    {
        return;
    }
    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
    if (*head == NULL)
    {
        *tail = NULL;
    }
}

void printList(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}
