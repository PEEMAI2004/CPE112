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

int main() {
    int n;
    // Get number of nodes
    scanf ("%d", &n);

    Node *head = NULL;
    Node *tail = NULL;

    // Get elements
    inputElements(n, &head, &tail);

    char command;
    while (1) {
        scanf(" %c", &command);
        if (command == 'F') {
            removeLeftNode(&head);
        } else if (command == 'L') {
            removeRightNode(&head);
        } else if (command == 'N') {
            int value;
            scanf ("%d", &value);
            removeNodewithValue(&head, value);
        } else {
            break;
        }
    }


    // Print list
    printList(head);
    

    return 0;
}

void inputElements(int n, Node **head, Node **tail) {
    // Loop to get all elements
    for (int i = 0; i < n; i++) {
        int value;
        scanf ("%d", &value);
        // create new node
        Node *newNode = (struct Node *)malloc(sizeof(Node));
        newNode->data = value;
        newNode->next = NULL;

        if (*head == NULL) {
            *head = newNode;
            *tail = newNode;
        } else {
            (*tail)->next = newNode;
            *tail = newNode;
        }
    }
}

void printList(Node *head) {
    Node *current = head;
    if (current == NULL) {
        printf("none\n");
        return;
    }
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

void removeLeftNode(Node **head) {
    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void removeRightNode(Node **head) {
    Node *current = *head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    Node *temp = current->next;
    current->next = NULL;
    free(temp);
}

void removeNodewithValue(Node **head, int value) {
    Node *current = *head;
    Node *prev = NULL;
    while (current != NULL) {
        if (current->data == value) {
            if (prev == NULL) {
                *head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}
