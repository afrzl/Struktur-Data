#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_SIZE 8

typedef struct
{
    int data[MAX_SIZE];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q)
{
    q->front = -1;
    q->rear = -1;
}

bool isQueueEmpty(Queue *q)
{
    return q->front == -1;
}

bool isQueueFull(Queue *q)
{
    return (q->rear + 1) % MAX_SIZE == q->front;
}

void enqueue(Queue *q, int value)
{
    if (isQueueFull(q))
    {
        printf("Queue is full\n");
        return;
    }
    if (isQueueEmpty(q))
    {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->data[q->rear] = value;
}

int dequeue(Queue *q)
{
    if (isQueueEmpty(q))
    {
        printf("Queue is empty\n");
        return -1;
    }
    int value = q->data[q->front];
    if (q->front == q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }
    else
    {
        q->front = (q->front + 1) % MAX_SIZE;
    }
    return value;
}

void add_edge(int adj[][MAX_SIZE], int src, int dest)
{
    adj[src][dest] = 1;
    adj[dest][src] = 1;
}

bool BFS(int adj[][MAX_SIZE], int src, int dest, int v, int pred[], int dist[])
{
    bool visited[MAX_SIZE];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
        dist[i] = __INT_MAX__;
        pred[i] = -1;
    }
    visited[src] = true;
    dist[src] = 0;
    Queue q;
    initQueue(&q);
    enqueue(&q, src);
    while (!isQueueEmpty(&q))
    {
        int u = dequeue(&q);
        for (int i = 0; i < v; i++)
        {
            if (adj[u][i] == 1 && !visited[i])
            {
                visited[i] = true;
                dist[i] = dist[u] + 1;
                pred[i] = u;
                enqueue(&q, i);
                if (i == dest)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

void printShortestDistance(int adj[][MAX_SIZE], int s, int dest, int v)
{
    int pred[MAX_SIZE], dist[MAX_SIZE];
    if (!BFS(adj, s, dest, v, pred, dist))
    {
        printf("Given source and destination are not connected\n");
        return;
    }
    int path[MAX_SIZE];
    int crawl = dest;
    int count = 0;
    path[count++] = crawl;
    while (pred[crawl] != -1)
    {
        path[count++] = pred[crawl];
        crawl = pred[crawl];
    }
    printf("Shortest path length is: %d\n", dist[dest]);
    printf("Path is:\n");
    for (int i = count - 1; i >= 0; i--)
    {
        printf("%d ", path[i]);
    }
    printf("\n");
}

int main()
{
    int v = 8;
    int adj[MAX_SIZE][MAX_SIZE] = {0};
    add_edge(adj, 0, 1);
    add_edge(adj, 0, 3);
    add_edge(adj, 1, 2);
    add_edge(adj, 3, 4);
    add_edge(adj, 3, 7);
    add_edge(adj, 4, 5);
    add_edge(adj, 4, 6);
    add_edge(adj, 4, 7);
    add_edge(adj, 5, 6);
    add_edge(adj, 6, 7);
    int source = 0, dest = 5;
    printShortestDistance(adj, source, dest, v);

    return 0;
}
