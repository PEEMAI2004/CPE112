#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char songName[100];
    char artist[100];
    int time;
    struct Node *next;
} Node;

void addSong(Node **head, Node **tail, char songName[], char artist[], int time);
void deQueue(Node **head, Node **tail);
void remainingTime(Node *head);

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    char command[4];
    // add, play, sum
    while (1)
    {
        scanf("%s", command);
        if (strcmp(command, "add") == 0)
        {
            char songName[100];
            char artist[100];
            int time;
            getchar(); // consume the newline character
            fgets(songName, sizeof(songName), stdin);
            songName[strcspn(songName, "\n")] = '\0'; // Remove newline character

            fgets(artist, sizeof(artist), stdin);
            artist[strcspn(artist, "\n")] = '\0'; // Remove newline character
            scanf("%d", &time);
            addSong(&head, &tail, songName, artist, time);
        }
        if (strcmp(command, "play") == 0)
        {
            deQueue(&head, &tail);
        }
        if (strcmp(command, "sum") == 0)
        {
            remainingTime(head);
            break;
        }
    }
}

void addSong(Node **head, Node **tail, char songName[], char artist[], int time)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->songName, songName);
    strcpy(newNode->artist, artist);
    newNode->time = time;
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

void deQueue(Node **head, Node **tail)
{
    if (*head == NULL)
    {
        printf("No songs in the playlist\n");
    }
    else
    {
        printf("Now playing: %s by %s\n", (*head)->songName, (*head)->artist);
        Node *temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

void remainingTime(Node *head)
{
    if (head == NULL)
    {
        printf("No songs in the playlist\n");
        return;
    }

    printf("Songs in the playlist:\n");
    Node *current = head;
    int sum = 0;
    while (current != NULL)
    {
        printf("%s by %s %dsec\n", current->songName, current->artist, current->time);
        sum += current->time;
        current = current->next;
    }
    printf("Remaining Time: %dsec\n", sum);
}
