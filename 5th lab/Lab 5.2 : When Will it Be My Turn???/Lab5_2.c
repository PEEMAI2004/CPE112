// Kamin Jittapassorn 66070503409

#include <stdio.h>

typedef struct
{
    int size;
    int items[10];
    int front, rear;
} Queue;

void initQueue(Queue *q)
{
    q->front = -1;
    q->rear = -1;
}

int isFull(Queue *q)
{
    if ((q->front == 0 && q->rear == q->size - 1) || (q->front == q->rear + 1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(Queue *q)
{
    if (q->front == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void insertq(Queue *q, int value)
{
    if (isFull(q))
    {
        printf("Queue is full!!\n");
        return;
    }
    if (q->front == -1)
    {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % q->size;
    q->items[q->rear] = value;
    return;
}

int dequeue(Queue *q)
{
    int value;
    if (isEmpty(q))
    {
        printf("Queue is empty!!\n");
        return -1;
    }
    value = q->items[q->front];
    if (q->front == q->rear)
    { // Incase last element
        q->front = -1;
        q->rear = -1;
    }
    else
    {
        q->front = (q->front + 1) % q->size;
    }
    return value;
}

void show(Queue q)
{
    if (isEmpty(&q))
    {
        printf("Queue is empty!!\n");
        return;
    }

    printf("Front: %d\nItems: ", q.front);

    int i = q.front;
    do
    {
        printf("%d ", q.items[i]);
        i = (i + 1) % q.size;
    } while (i != (q.rear + 1) % q.size);

    printf("\nRear: %d\n", q.rear);
}

int main()
{
    Queue q;
    initQueue(&q);
    scanf("%d", &q.size);
    char choice;
    int val;
    while (1)
    {
        scanf("%c", &choice);
        if (choice == 'I')
        {
            scanf("%d", &val);
            insertq(&q, val);
        }
        else if (choice == 'D')
        {
            int status = dequeue(&q);
            if (status != -1)
                printf("%d\n", status);
        }
        else if (choice == 'S')
        {
            show(q);
        }
        else if (choice == 'E')
            break;
    }
    return 0;
}
