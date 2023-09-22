#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    struct Node *next;
    struct Node *prev;
};
typedef struct Node *ptrNode;

ptrNode createNode(int nilai)
{
    ptrNode p;
    p = (ptrNode)malloc(sizeof(struct Node));
    p->value = nilai;
    p->next = NULL;
    p->prev = NULL;
    return (p);
}

void reverse(ptrNode *head)
{
    ptrNode temp = NULL;
    ptrNode current = *head;

    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL)
        *head = temp->prev;
}

ptrNode push(ptrNode head, int value)
{
    ptrNode temp = head;

    ptrNode newNode = createNode(value);
    if (temp == NULL)
    {
        head = (ptrNode)malloc(sizeof(struct Node));
        head = newNode;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        newNode->prev = temp;
        newNode->next = NULL;

        temp->next = newNode;
    }

    return head;
}

void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->value);
        node = node->next;
    }
    printf("\n");
}

int main()
{
    ptrNode head = NULL;

    head = push(head, 1);
    head = push(head, 2);
    head = push(head, 3);
    head = push(head, 4);
    head = push(head, 5);

    printf("Double linked list awal: ");
    printList(head);

    reverse(&head);

    printf("Double linked list setelah direverse: ");
    printList(head);
}