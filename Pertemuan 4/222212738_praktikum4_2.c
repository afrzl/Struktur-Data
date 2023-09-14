#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
};
typedef struct node *ptrnode;

ptrnode addNote(int value)
{
    ptrnode p;
    p = (ptrnode)malloc(sizeof(ptrnode));
    p->value = value;
    p->next = NULL;

    return (p);
}

ptrnode addTail(ptrnode head, int value)
{
    ptrnode tail = head;
    ptrnode newNode = addNote(value);

    if (head == NULL)
    {
        head = (ptrnode)malloc(sizeof(struct node));
        head = newNode;
    }
    else
    {
        while (tail->next != NULL)
            tail = tail->next;
        tail->next = newNode;
    }

    return head;
}

void printNode(struct node *head)
{
    struct node *temp;

    if (head == NULL)
    {
        printf("Node is empty.\n");
        return;
    }

    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->value);
        temp = temp->next;
    }
}

ptrnode reverseNode(ptrnode *head)
{
    ptrnode prev = NULL;
    ptrnode current = *head;
    ptrnode next = NULL;

    while (current != NULL)
    {
        next = current->next;

        current->next = prev;

        prev = current;
        current = next;
    }
    *head = prev;
}

int main()
{
    ptrnode head = NULL;
    int value;
    char question;

    do
    {
        printf("Masukkan node value: ");
        scanf("%d", &value);

        head = addTail(head, value);

        printf(">> Apakah anda akan memasukkan node lagi? (Y/N): ");
        scanf("%s", &question);
    } while (question != 'n');

    printf("\nSebelum dibalik:\n");
    printNode(head);

    reverseNode(&head);
    printf("\nSetelah dibalik:\n");
    printNode(head);

    return 0;
}
