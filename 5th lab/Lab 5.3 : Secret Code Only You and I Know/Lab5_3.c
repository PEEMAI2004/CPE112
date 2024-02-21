// Kamin Jittapassorn 66070503409

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node
{
    char data;
    int priority;
    struct Node *next;
} Node;

typedef struct PriorityQueue
{
    Node *front;
    Node *rear;
} PriorityQueue;

void initPriorityQueue(PriorityQueue *pq)
{
    pq->front = NULL;
    pq->rear = NULL;
}

void enqueue(PriorityQueue *pq, char data, int priority)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;

    if (pq->front == NULL)
    {
        pq->front = pq->rear = newNode;
    }
    else
    {
        if (priority > pq->front->priority)
        {
            newNode->next = pq->front;
            pq->front = newNode;
        }
        else if (priority < pq->rear->priority)
        {
            pq->rear->next = newNode;
            pq->rear = newNode;
        }
        else
        {
            Node *temp = pq->front;
            while (temp->next != NULL && temp->next->priority >= priority)
            {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

void dequeue(PriorityQueue *pq)
{
    if (pq->front == NULL)
    {
        return;
    }
    Node *temp = pq->front;
    pq->front = pq->front->next;
    if (pq->front == NULL)
    {
        pq->rear = NULL;
    }
    free(temp);
}

void transformString(char *str)
{
    PriorityQueue q3, q2, q;
    initPriorityQueue(&q3);
    initPriorityQueue(&q2);
    initPriorityQueue(&q);

    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        char ch = str[i];
        int priority;
        if (isalpha(ch))
        {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
                ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
            {
                priority = 3; // Vowels
            }
            else
            {
                priority = 1; // Consonants
            }
        }
        else if (isspace(ch))
        {
            priority = 2; // Whitespace
        }
        else
        {
            priority = 2; // Other characters
        }

        if (priority == 1)
            enqueue(&q, ch, priority);
        else if (priority == 2)
            enqueue(&q2, ch, priority);
        else
            enqueue(&q3, ch, priority);
    }

    while (q3.front != NULL)
    {
        printf("%c", q3.front->data);
        dequeue(&q3);
    }
    while (q2.front != NULL)
    {
        printf("%c", q2.front->data);
        dequeue(&q2);
    }
    while (q.front != NULL)
    {
        printf("%c", q.front->data);
        dequeue(&q);
    }
    printf("\n");
}

int main()
{
    char str[1000];
    fgets(str, sizeof(str), stdin);
    if (str[strlen(str) - 1] == '\n')
    {
        str[strlen(str) - 1] = '\0';
    }
    transformString(str);
    return 0;
}