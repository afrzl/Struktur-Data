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

ptrnode head = NULL;
int jumnode; // jumlah node

ptrnode insert(int nim, char nama[])
{
    ptrnode p, q;
    p = (ptrnode)malloc(sizeof(struct node));
    p->nim = nim;
    strcpy(p->nama, nama);
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
    int nim;
    char nama[50];

    printf("Input ukuran array (max 100): ");
    scanf("%d", &jumnode);
    printf("Input data ascending: \n");
    for (int i = 0; i < jumnode; i++)
    {
        printf("[%d]\n", i + 1);
        printf(">> NIM: ");
        scanf("%d", &nim);
        printf(">> Nama: ");
        scanf("%s", &nama);

        head = insert(nim, nama);
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

ptrnode binary_search_nim(int x)
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
        if (mid->nim == x)
            return mid;
        // Jika nilai x lebih dari node tengah
        else if (mid->nim < x)
            start = mid->next;
        // Jika nilai x kurang dari node tengah
        else
            last = mid;
    } while (last == NULL || last != start);
    // jika tidak ditemukan
    return NULL;
}

ptrnode sequential_search_name(char x[])
{ // x adalah nilai yang dicari
    int j = 1;
    ptrnode tmp = head;
    while (tmp != NULL)
    {
        if (strcmp(tmp->nama, x) == 0)
        {
            return tmp;
        }
        else
        {
            tmp = tmp->next;
            j++;
        }
    }
    return NULL; // jika tidak ada yang dicari return -1
}

void display()
{
    printf("List of mahasiswa: \n");
    ptrnode tmp = head;
    int i = 1;
    while (tmp != NULL)
    {
        printf("No. [%d]\nNIM: %d\nName: %s\n", i + 1, tmp->nim, tmp->nama);
        i++;
        tmp = tmp->next;
    }
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
    char nama[50];
    int x, choice;

    do
    {
        ptrnode search;
        // system("@cls||clear");
        printf("--- BINARY SEARCH DATA MAHASISWA ---\n");
        printf("1. Search by NIM\n");
        printf("2. Search by name\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf(">> Menu : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf(">> Enter your NIM: ");
            scanf("%d", &x);
            search = binary_search_nim(x);
            if (search == NULL)
            {
                printf("Data not found.\n");
            }
            else
            {
                printf("Data found. Nama: %s\n", search->nama);
            }
            getchar();
            break;
        case 2:
            printf(">> Enter your name: ");
            scanf("%s", &nama);
            search = sequential_search_name(nama);
            if (search == NULL)
            {
                printf("Data not found.\n");
            }
            else
            {
                printf("Data found. NIM: %d\n", search->nim);
            }
            getchar();
            break;
        case 3:
            display();
            getchar();
            break;
        default:
            printf("Input error.\n");
            getchar();
            break;
        }
    } while (choice != 4);

    bersihkan_memori();
}
