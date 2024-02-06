// Kamin Jittapassorn 66070503409

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct ListNode
{
    int val;
    struct ListNode *next;
} ListNode;

void inputList(ListNode **head, ListNode **tail);
void printList(ListNode *head);
void reverseList(ListNode **head);

int main()
{
    ListNode *head = NULL;
    ListNode *tail = NULL;

    inputList(&head, &tail);
    // printList(head);
    while (getchar() != '\n')
        ; // free keyborad buffer
    reverseList(&head);
    printList(head);
    return 0;
}

void inputList(ListNode **head, ListNode **tail)
{
    int flag = 1;
    do
    {
        char command[4];
        scanf(" %s", &command);

        if (isdigit(command[0])) // check if the command is a number
        {
            // turn the command into an integer
            int value = atoi(command);
            // printf("%d\n", value);
            // create a new node
            ListNode *newNode = (struct ListNode *)malloc(sizeof(ListNode));
            newNode->val = value;
            newNode->next = NULL;
            // add the new node to the list
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
        else
        {
            flag = 0;
        }
    } while (flag);
    // printf("End of input\n");
}

void printList(ListNode *head)
{
    ListNode *current = head;
    while (current != NULL)
    {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
}

void reverseList(ListNode **head)
{
    int start, end;
    scanf("%d %d", &start, &end);
    
    // create a new dummy node to be the head of the list
    ListNode *dummy = (struct ListNode *)malloc(sizeof(ListNode));
    dummy->next = *head;
    *head = dummy;

    // printf("start: %d, end: %d\n", start, end);
    ListNode *current = *head;
    ListNode *temp = NULL;
    ListNode *prev = NULL; // Add a pointer to keep track of the previous node

    // Seek to the start position
    for (int i = 0; i < start; i++)
    {
        prev = current;
        current = current->next;
    }

    // Reverse the list from start to end
    for (int i = start; i < end; i++)
    {
        temp = current->next;
        current->next = temp->next;
        temp->next = prev->next; // Update the next pointer of the previous node
        prev->next = temp;       // Update the next pointer of the previous node to the current node
    }

    // remove the dummy node
    *head = (*head)->next;
    free(dummy);
}