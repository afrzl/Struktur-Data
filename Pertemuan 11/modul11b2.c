#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
};
typedef struct node *ptrnode;

ptrnode head, tail = NULL;
int jumnode;

ptrnode insert(int nilai)
{
    ptrnode p;
    p = (ptrnode)malloc(sizeof(struct node));
    p->value = nilai;
    p->next = NULL;
    if (head == NULL)
    {
        head = p;
        tail = head;
    }
    else
    {
        tail = head;
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        tail->next = p;
        tail = p;
    }
    return (head);
}

void isi_data()
{
    int j, k;
    printf("input jumlah node (data harus urut ascending) : ");
    scanf("%d", &jumnode);
    for (j = 1; j <= jumnode; j++)
    {
        printf("input data ke-%d :", j);
        scanf("%d", &k);
        head = insert(k);
    }
}

ptrnode middle(ptrnode start, ptrnode last)
{
    // untuk mendapatkan node tengah
    if (start == NULL)
        return NULL;
    ptrnode slow = start;
    ptrnode fast = start->next;
    while (fast != last)
    {
        fast = fast->next;
        if (fast != last)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    return slow;
}

ptrnode binarySearch(int x)
{
    ptrnode start = head;
    ptrnode last = NULL;
    do
    {
        // temukan node tengah
        ptrnode mid = middle(start, last);
        // jika node tengah NULL

        if (mid == NULL)
            return NULL;
        // Jika x ditemukan di node tengah
        if (mid->value == x)
            return mid;
        // Jika nilai x lebih dari node tengah
        else if (mid->value < x)
            start = mid->next;
        // Jika nilai x kurang dari node tengah
        else
            last = mid;
    } while (last == NULL || last != start);
    // jika tidak ditemukan
    return NULL;
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

    if (binarySearch(x) == NULL)
        printf("data tidak ditemukan");
    else
        printf("data ditemukan");

    bersihkan_memori();
}
