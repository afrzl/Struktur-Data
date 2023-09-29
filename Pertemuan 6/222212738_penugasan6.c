#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int num;
    struct Node *next;
};
typedef struct Node *ptrNode;

int isEmpty(ptrNode s)
{
    return (s == NULL);
}

ptrNode createNode(int nilai)
{
    ptrNode p;
    p = (ptrNode)malloc(sizeof(struct Node));
    p->num = nilai;
    p->next = NULL;
    return (p);
}

ptrNode push(int x, ptrNode head)
{
    ptrNode new_node = createNode(x);
    new_node->next = head;
    head = new_node;
    return (head);
}

ptrNode pop(ptrNode head)
{
    if (head == NULL)
        return NULL;
    ptrNode first = head;
    head = head->next;
    first->next = NULL;
    free(first);
    return (head);
}

void displayBinary(ptrNode head)
{
    ptrNode temp;

    if (head == NULL)
    {
        printf("Node is empty.\n");
        return;
    }

    temp = head;
    printf("List of node:\n");
    while (temp != NULL)
    {
        printf("%d ", temp->num);
        temp = temp->next;
    }
}

ptrNode addNode(int n, ptrNode *node)
{
    ptrNode temp;
    temp = (ptrNode)malloc(sizeof(struct Node));
    temp->num = n;
    temp->next = *node;

    return temp;
}

void decToBinary(int n, ptrNode *head)
{
    int sisa_bagi;
    for (int i = n; i > 0; i = i / 2)
    {
        sisa_bagi = i % 2;
        *head = addNode(sisa_bagi, head);
    }
    printf("Hasil konversi ke biner = ");
    ptrNode temp = *head;
    while (temp != NULL)
    {
        printf("%d", temp->num);
        temp = temp->next;
    }
}

void decToOctal(int n, ptrNode *head)
{
    int sisa_bagi;
    for (int i = n; i > 0; i = i / 8)
    {
        sisa_bagi = i % 8;
        *head = addNode(sisa_bagi, head);
    }
    printf("Hasil konversi ke biner = ");
    ptrNode temp = *head;
    while (temp != NULL)
    {
        printf("%d", temp->num);
        temp = temp->next;
    }
}

int main()
{
    ptrNode head = NULL;
    int bil_desimal;

    printf("Program konversi Desimal ke Biner\n\n");

    printf("Masukkan bilangan desimal = ");
    scanf("%d", &bil_desimal);
    // bil_desimal = 20;
    int choice;
    printf("Masukkan pilihan\n1: Biner\n2: Octal\n=> ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        if (bil_desimal == 0)
            printf("Hasil konversi ke biner = 0");
        else if (bil_desimal < 0)
        {
            int bil_sama = 1;
            while (bil_sama < (bil_desimal * -1))
            {
                bil_sama *= 2;
            }
            printf("%d", bil_sama);

            decToBinary(bil_sama - (bil_desimal * -1), &head);
        }
        else
        {
            decToBinary(bil_desimal, &head);
            // decToBinary(bil_desimal, &tumpukan);
        }
        break;

    case 2:
        decToOctal(bil_desimal, &head);
        break;

    default:
        printf("Pilihan salah");
        break;
    }

    return 0;
}