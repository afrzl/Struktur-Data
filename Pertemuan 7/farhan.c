#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

const int MAX = 20;

typedef struct node
{
    int value;
    struct node *prev;
    struct node *next;
} *queue;

void initialize(queue *rear, queue *front)
{
}

queue createNode(int num)
{
    queue newNode;
    newNode = (queue)malloc(sizeof(struct node));
    newNode->value = num;
    newNode->prev = NULL;
    newNode->next = NULL;
    return (newNode);
}

int size(queue rear)
{
    int count = 0;
    queue cursor;
    cursor = rear;
    while (cursor != NULL)
    {
        count += 1;
        cursor = cursor->prev;
    }
    return count;
}

bool isFull(queue rear)
{
    return (size(rear) > MAX);
}

bool isEmpty(queue front)
{
    return front == NULL;
}

void enqueue(queue *rear, queue *front, int num)
{
    if (isFull(*rear))
        printf("Antrian Penuh\n");
    else
    {
        queue temp = createNode(num);
        temp->prev = *rear;
        if (*rear == NULL)
        {
            *rear = temp;
        }
        else
        {
            (*rear)->next = temp;
        }

        if (*front == NULL)
            *front = *rear;
    }
}

queue dequeue(queue front)
{
    if (isEmpty(front))
        return NULL;
    else
    {
        queue temp = front;
        front = front->next;
        temp->next = NULL;
        front->prev = NULL;
        free(temp);
        return front;
    }
}

int main()
{
    queue front = NULL, rear = NULL;

    printf("halo");
    int i = 0;
    while (i < 10)
    {
        printf("%d", i);
        enqueue(&rear, &front, i);
        printf("%d %d", rear->value, front->value);
        i++;
    }

    printf("  Kata terbalik: ");
    while (!isEmpty(front))
    {
        printf("%d", front->value);
        front = dequeue(front);
    }
}