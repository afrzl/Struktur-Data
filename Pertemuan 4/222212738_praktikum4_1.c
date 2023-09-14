/*
    Buatlah fungsi untuk menghitung jumlah node dalam sebuah linked list! (looping sama seperti pada saat menampilkan nilai dari linked list).
*/

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

int countNode(struct node *head)
{
    struct node *temp;

    temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
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

    printf("\nJumlah node: %d", countNode(head));

    return 0;
}
