#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int value;
    struct node *next;
};
typedef struct node *ptrnode;

ptrnode head = NULL;
int jumnode; // jumlah node

ptrnode insert(int nilai)
{
    ptrnode p, q;
    p = (ptrnode)malloc(sizeof(struct node));
    p->value = nilai;
    p->next = NULL;
    if (head == NULL)
    {
        head = p;
        q = head;
    }
    else
    {
        q = head;
        while (q->next != NULL)
        {
            q = q->next;
        }
        q->next = p;
    }
    return (head);
}

void isi_data()
{
    int k;
    printf("input jumlah node: ");
    scanf("%d", &jumnode);
    for (int j = 1; j <= jumnode; j++)
    {
        printf("input data ke-%d :", j);
        scanf("%d", &k);
        head = insert(k);
    }
}

bool checkAscending()
{
    if (jumnode <= 1)
        return true;

    ptrnode tmp = head;
    while (tmp != NULL)
    {
        if (tmp->value < tmp->next->value)
            return false;
    }

    return true;
}

bool checkDescending()
{
    if (jumnode <= 1)
        return true;

    ptrnode tmp = head;
    while (tmp != NULL)
    {
        if (tmp->value > tmp->next->value)
            return false;
    }

    return true;
}

int search(int x)
{ // x adalah nilai yang dicari
    int j = 1;
    ptrnode tmp = head;
    if (checkAscending)
    {
        while (tmp != NULL && j < jumnode && tmp->value <= x)
        {
            if (x == tmp->value)
            {
                return j;
            }
            else
            {
                tmp = tmp->next;
                j++;
            }
        }
    }
    else if (checkDescending)
    {
        while (tmp != NULL && j < jumnode && tmp->value >= x)
        {
            if (x == tmp->value)
            {
                return j;
            }
            else
            {
                tmp = tmp->next;
                j++;
            }
        }
    }
    else
    {
        while (tmp != NULL)
        {
            if (x == tmp->value)
            {
                return j;
            }
            else
            {
                tmp = tmp->next;
                j++;
            }
        }
    }

    return -1; // jika tidak ada yang dicari return -1
}

void bersihkan_memori()
{
    while (head != NULL)
    {
        ptrnode tmp = head;
        head = head->next;
        tmp->next = NULL;
        free(tmp);
    }
}

void main()
{
    isi_data();
    int x;

    printf("input nilai yang mau dicari: ");
    scanf("%d", &x);

    if (search(x) == -1)
        printf("data tidak ditemukan");
    else
        printf("data ditemukan di node ke-%d", search(x));

    bersihkan_memori();
}
