#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 100 // ukuran maksimum array

typedef struct
{
    char nama[50];
    int nim;
} mhs;

void fill_data(mhs data[], int *size)
{ // mengisi data
    printf("Input ukuran array (max 100): ");
    scanf("%d", size);
    printf("Input data ascending: \n");
    for (int i = 0; i < *size; i++)
    {
        printf("[%d]\n", i + 1);
        printf(">> NIM: ");
        scanf("%d", &data[i].nim);
        printf(">> Nama: ");
        scanf("%s", &data[i].nama);
    }
}

int binary_search_name(mhs data[], int size, char x[])
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(data[i].nama, x) == 0)
            return i + 1;
    }

    return -1;
}

int binary_search_nim(mhs data[], int size, int x)
{
    int L = 0;
    int H = size - 1;
    int M = -1;
    int index = -1;
    while (L <= H)
    {
        M = (L + H) / 2;
        if (data[M].nim == x)
            return M + 1;
        else
        {
            if (data[M].nim < x)
                L = M + 1;
            else
                H = M - 1;
        }
    }

    return -1;
}

void display(mhs data[], int size)
{
    printf("List of mahasiswa: \n");
    for (int i = 0; i < size; i++)
    {
        printf("No. [%d]\nNIM: %d\nName: %s\n", i + 1, data[i].nim, data[i].nama);
    }
}

void main()
{
    mhs data[MAX];
    char nama[50];
    int size; // ukuran array
    int x, choice;

    fill_data(data, &size);

    do
    {
        int index;
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
            index = binary_search_nim(data, size, x);
            if (index == -1)
            {
                printf("Data not found.\n");
            }
            else
            {
                printf("Data found at index %d. Nama: %s\n", index, data[index - 1].nama);
            }
            getchar();
            break;
        case 2:
            printf(">> Enter your name: ");
            scanf("%s", &nama);
            index = binary_search_name(data, size, nama);
            if (index == -1)
            {
                printf("Data not found.\n");
            }
            else
            {
                printf("Data found at index %d. NIM: %s\n", index, data[index - 1].nim);
            }
            getchar();
            break;
        case 3:
            display(data, size);
            getchar();
            break;
        default:
            printf("Input error.\n");
            getchar();
            break;
        }
    } while (choice != 4);
}
