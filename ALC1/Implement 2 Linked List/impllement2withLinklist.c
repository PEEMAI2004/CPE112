#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    char table[4];
    char order[128];
    int price;
    struct Node *next;
} Node;

void addOrder(Node **head, Node **tail);
void deOrder(Node **head, Node **tail);
void skipOrder(Node **head, Node **tail);
void printOrders(Node *head);

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    int command;
    int value;
    printf("0: Exit\n1: Add Order\n2: Delete Order\n3: Skip current order\n4: Print Orders\n");
    while (1)
    {
        scanf("%d", &command);
        if (command == 0)
        {
            printf("Do you want to exit, all quene will be gone (y/n)\n");
            if (getchar() == 'y')
            {
                break;
            }
        }
        else if (command == 1)
        {
            addOrder(&head, &tail);
        }
        else if (command == 2)
        {
            deOrder(&head, &tail);
        }
        else if (command == 4)
        {
            printOrders(head);
        }
        else if (command == 3)
        {
            skipOrder(&head, &tail);
        }
        else
        {
            printf("Invalid command\n");
        }
    }
}

void addOrder(Node **head, Node **tail)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    //printf("Enter table: ");
    scanf("%s", newNode->table);
    //printf("Enter the Dish: ");
    scanf("%s", newNode->order);
    //printf("Enter the price in THB: ");
    scanf("%d", &newNode->price);
    newNode->next = NULL;
    if (*head == NULL)
    {
        *head = newNode;
        *tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        (*tail)->next = newNode;
        *tail = newNode;
        newNode->next = *head;
    }
    printf("Order added\n");
}

void deOrder(Node **head, Node **tail)
{
    if (*head == NULL)
    {
        printf("No order\n");
    }
    // if it is the last order
    else if ((*head)->next == *head && (*tail)->next == *tail)
    {
        Node *temp = *head;
        printf("Table %s: %s is deleted\n", temp->table, temp->order);
        *head = NULL;
        *tail = NULL;
        free(temp);
    }
    else // if it is not the last order
    {
        Node *temp = *head;
        *head = (*head)->next;
        (*tail)->next = *head;
        printf("Table %s: %s was served\n", temp->table, temp->order);
        free(temp);
    }
}

void skipOrder(Node **head, Node **tail)
{
    if (*head == NULL)
    {
        printf("No order\n");
    }
    else if ((*head)->next == *head && (*tail)->next == *tail)
    
    {
        printf("This is the last order, cannot be skip\n");
    }
    else
    {
        // shift the head to the next order
        Node *temp = *head;
        *head = (*head)->next;
        *tail = temp;
        printf("Order %s:%s skipped\n", temp->table, temp->order);
    }
}

void printOrders(Node *head)
{
    Node *current = head;
    if (current == NULL)
    {
        printf("No order\n");
    }
    int i = 1;
    do
    {
        printf("%d- Table %s: %s: ฿%d\n", i, current->table, current->order, current->price);
        current = current->next;
        i++;
    } while (current != head);
}
