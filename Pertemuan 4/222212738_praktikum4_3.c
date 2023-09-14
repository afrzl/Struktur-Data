#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int nim;
    char nama[50];
    struct node *next;
};

typedef struct node *ptrnode;

ptrnode newNode(int nim, char nama[50])
{
    ptrnode new_node = (ptrnode)malloc(sizeof(struct node));

    new_node->nim = nim;
    strcpy(new_node->nama, nama);
    new_node->next = NULL;

    return new_node;
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
        printf("%d. %s\n", temp->nim, temp->nama);
        temp = temp->next;
    }
}

void insertNode(ptrnode *head, ptrnode new_node)
{
    ptrnode current;

    if (*head == NULL || (*head)->nim >= new_node->nim)
    {
        new_node->next = *head;
        *head = new_node;
    }
    else
    {
        current = *head;
        while (current->next != NULL && current->next->nim < new_node->nim)
        {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

int main()
{
    ptrnode head = NULL;
    int nim;
    char nama[50];
    char question;

    do
    {
        printf("Masukkan NIM: ");
        scanf("%d", &nim);

        printf("Masukkan Nama: ");
        scanf(" %[^\n]s", nama);

        ptrnode new_node = newNode(nim, nama);
        insertNode(&head, new_node);

        printf(">> Apakah anda akan memasukkan data lagi? (Y/N): ");
        scanf("%s", &question);
    } while (question != 'n');

    system("cls");
    printf("Print:\n");
    printNode(head);

    return 0;
}
