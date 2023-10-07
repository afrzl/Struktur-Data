#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node
typedef struct node
{
    char nama[20];
    int alpro;
    int kalkulus;
    struct node *next;
} mhs;

int count = 0;

// Function to Create A New Node
mhs *newmhs(char a[], int alp, int kal)
{
    mhs *temp = (mhs *)malloc(sizeof(mhs));
    strcpy(temp->nama, a);
    temp->alpro = alp;
    temp->kalkulus = kal;
    temp->next = NULL;

    return temp;
}

// menghapus pendaftar
void dequeue(mhs **head)
{
    if ((*head) != NULL)
    {

        mhs *temp = *head;

        (*head) = (*head)->next;

        free(temp);
    }
}

// Function to push according to priority
void enqueue(mhs **head, char n[], int alp, int kal)
{
    mhs *temp = newmhs(n, alp, kal);
    if ((*head) == NULL)
    {

        (*head) = temp;
    }
    else if ((*head)->alpro > alp)
    {
        temp->next = *head;
        (*head) = temp;
    }
    else if ((*head)->alpro == alp)
    {
        mhs *start = (*head);
        while (start->next != NULL && start->next->kalkulus < kal)
        {
            start = start->next;
        }
        temp->next = start->next;
        start->next = temp;
    }
    else
    {
        mhs *start = (*head);
        while (start->next != NULL && start->next->alpro < alp)
        {
            start = start->next;
        }

        while (start->next->alpro == alp && start->next != NULL && start->next->kalkulus < kal)
        {
            start = start->next;
        }

        temp->next = start->next;
        start->next = temp;
    }
    count++;
}

void display(mhs *head)
{
    if (head == NULL)
    {
        printf("Belum ada yang daftar\n");
    }
    else
    {
        printf("Nama:%s Alpro: %d Kalkulus: %d\n", head->nama, head->alpro, head->kalkulus);
        display(head->next);
    }
}
int main()
{
    mhs *wakil;
    enqueue(&wakil, "Eko", 50, 20);
    enqueue(&wakil, "Budi", 50, 20);

    enqueue(&wakil, "bambang", 60, 20);
    enqueue(&wakil, "Eka", 60, 20);
    enqueue(&wakil, "wawo", 60, 20);

    enqueue(&wakil, "Ame", 60, 30);
    display(wakil);
    return 0;
}