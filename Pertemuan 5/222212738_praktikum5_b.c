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

    int i = 1;
    while (temp != NULL)
    {
        printf("node %d : %d\n", i, temp->value);
        i++;
        temp = temp->next;
    }
}

ptrnode addNode(ptrnode head, int value)
{
    ptrnode temp = head;

    ptrnode newNode = createNode(value);
    if (head == NULL)
    {
        head = (ptrnode)malloc(sizeof(struct node));
        head = newNode;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    return head;
}

ptrnode insert_head(ptrnode head, int nilai)
{
    ptrnode new_node = createNode(nilai);
    new_node->next = head;
    head->prev = new_node;
    head = new_node;

    return (head);
}

int main(int argc, char const *argv[])
{
    int n;
    int value;

    ptrnode head = NULL;
    ptrnode tail = NULL;
    tail = head;

    printf("Input the number of nodes: ");
    scanf("%d", &n);
    // n = 3;

    for (int i = 0; i < n; i++)
    {
        printf("Input data for node %d : ", i + 1);
        scanf("%d", &value);
        // value = 5;

        head = addNode(head, value);
    }

    printf("\nData entered in the list are : \n");
    printNode(head);

    printf("Input data for the first node : ");
    scanf("%d", &value);

    head = insert_head(head, value);
    printf("\nAfter insertion the new list are : \n");
    printNode(head);

    return 0;
}
