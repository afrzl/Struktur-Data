#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
    struct node *prev;
};
typedef struct node *ptrnode;

ptrnode createNode(int nilai)
{
    ptrnode p;
    p = (ptrnode)malloc(sizeof(struct node));
    p->value = nilai;
    p->next = NULL;
    p->prev = NULL;
    return (p);
}

void printNode(ptrnode head)
{
    ptrnode temp = head;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    while (temp != NULL)
    {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

ptrnode insert_tail(ptrnode head, int nilai, ptrnode *tail)
{
    ptrnode temp = head;
    ptrnode newNode = createNode(nilai);

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;

    *tail = newNode;

    return head;
}

ptrnode remove_last(ptrnode head, ptrnode *tail)
{
    if (head == NULL)
        return NULL;

    ptrnode last = head;
    while (last->next != NULL)
    {
        last = last->next;
    }
    *tail = last->prev;
    last->prev->next = NULL;
    last->prev = NULL;
    free(last);

    return (head);
}

int main(int argc, char const *argv[])
{
    ptrnode head = NULL;
    ptrnode tail = NULL;
    head = (ptrnode)malloc(sizeof(struct node));
    tail = head;

    head = createNode(5);
    tail = head;
    printf("Print setelah pembuatan simpul awal :\n");
    printf(">> Head: ");
    printNode(head);
    printf(">> Tail: ");
    printNode(tail);

    head = insert_tail(head, 10, &tail);
    printf("Print setelah insert kanan :\n");
    printf(">> Head: ");
    printNode(head);
    printf(">> Tail: ");
    printNode(tail);

    head = insert_tail(head, 25, &tail);
    printf("Print setelah insert kanan (2) :\n");
    printf(">> Head: ");
    printNode(head);
    printf(">> Tail: ");
    printNode(tail);

    head = remove_last(head, &tail);
    printf("Print setelah pembuatan delete kanan :\n");
    printf(">> Head: ");
    printNode(head);
    printf(">> Tail: ");
    printNode(tail);

    return 0;
}
