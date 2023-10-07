#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char nama[20];
    int alpro;
    int kalkulus;
    struct node *next;
} mhs;

int count = 0;

mhs *newmhs(char a[], int alp, int kal)
{
    mhs *temp = (mhs *)malloc(sizeof(mhs));
    strcpy(temp->nama, a);
    temp->alpro = alp;
    temp->kalkulus = kal;
    temp->next = NULL;
    return temp;
}

void dequeue(mhs **head)
{
    if ((*head) != NULL)
    {
        mhs *temp = *head;
        (*head) = (*head)->next;
        free(temp);
    }
}

void enqueue(mhs **head, char n[], int alp, int kal)
{
    mhs *temp = newmhs(n, alp, kal);
    if ((*head) == NULL || alp > (*head)->alpro || (alp == (*head)->alpro && kal > (*head)->kalkulus))
    {
        temp->next = *head;
        (*head) = temp;
    }
    else
    {
        mhs *current = *head;
        while (current->next != NULL &&
               (alp < current->next->alpro || (alp == current->next->alpro && kal < current->next->kalkulus)))
        {
            current = current->next;
        }
        temp->next = current->next;
        current->next = temp;
    }

    // Hapus mahasiswa dengan nilai terendah jika sudah ada lebih dari 5 mahasiswa dalam daftar
    if (count >= 5)
    {
        mhs *current = *head;
        while (current->next->next != NULL)
        {
            current = current->next;
        }
        dequeue(&(current->next));
    }
    else
    {
        count++;
    }
}

void display(mhs *head)
{
    if (head == NULL)
    {
        printf("Belum ada yang daftar\n");
    }
    else
    {
        printf("Daftar 5 Mahasiswa Terbaik (urutan dari nilai terbaik):\n");
        mhs *current = head;
        while (current != NULL)
        {
            printf("Nama: %s Alpro: %d Kalkulus: %d\n", current->nama, current->alpro, current->kalkulus);
            current = current->next;
        }
    }
}

int main()
{
    mhs *wakil = NULL;
    enqueue(&wakil, "Budi", 50, 20);
    enqueue(&wakil, "Eko", 50, 20);
    enqueue(&wakil, "bambang", 60, 20);
    enqueue(&wakil, "Eka", 60, 20);
    enqueue(&wakil, "wawo", 60, 20);
    enqueue(&wakil, "Ame", 60, 30);
    display(wakil);
    return 0;
}
