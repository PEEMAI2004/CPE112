// Kamin Jittapassorn 66070503409

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void HeadInsert(int data, Node **head, Node **tail) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
    if (*tail == NULL) {
        *tail = newNode;
    }
}

void TailInsert(int data, Node **head, Node **tail) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (*tail != NULL) {
        (*tail)->next = newNode;
    }
    *tail = newNode;
    if (*head == NULL) {
        *head = newNode;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int option;
    scanf("%d", &option);

    Node *head = NULL;
    Node *tail = NULL;

    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        if (option == 1) {
            HeadInsert(data, &head, &tail);
        } else {
            TailInsert(data, &head, &tail);
        }
    }

    // print linked list
    Node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}