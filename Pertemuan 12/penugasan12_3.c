#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct
{
    int nim;
    char nama[50];
    int nilai;
} mhs;

void fill_data(mhs data[], int *size)
{
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
        printf(">> Nilai: ");
        scanf("%d", &data[i].nilai);
    }
}

void sortedByNim(mhs data[], int n)
{
    mhs key;
    int i, j;
    for (i = 1; i < n; i++)
    {
        key = data[i];
        j = i - 1;
        while (j >= 0 && data[j].nim > key.nim)
        {
            data[j + 1] = data[j];
            j = j - 1;
        }

        data[j + 1] = key;
    }
}

void merge(mhs data[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    mhs L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = data[l + i];
    for (j = 0; j < n2; j++)
        R[j] = data[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i].nilai >= R[j].nilai)
        {
            data[k] = L[i];
            i++;
        }
        else
        {
            data[k] = R[j];
            j++;
        }

        k++;
    }
    while (i < n1)
    {
        data[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        data[k] = R[j];
        j++;
        k++;
    }
}

void sortedByNilai(mhs data[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        sortedByNilai(data, l, m);
        sortedByNilai(data, m + 1, r);
        merge(data, l, m, r);
    }
}

void swap(mhs *a, mhs *b)
{
    mhs temp = *a;
    *a = *b;
    *b = temp;
}

void sortedByNama(mhs data[], int size)
{
    for (int step = 0; step < size - 1; step++)
    {
        int min_idx = step;
        for (int i = step + 1; i < size; i++)
            if (strcmp(data[i].nama, data[min_idx].nama) < 0)
                min_idx = i;

        swap(&data[min_idx], &data[step]);
    }
}

void display(mhs data[], int size)
{
    printf("List of mahasiswa: \n");
    for (int i = 0; i < size; i++)
    {
        printf("[%d]\nNIM: %d\nName: %s\nNilai: %d\n", i + 1, data[i].nim, data[i].nama, data[i].nilai);
    }
}

void main()
{
    mhs data[MAX];
    int size, choice;

    printf("### PROGRAM NILAI DATA MAHASISWA ###\n");
    fill_data(data, &size);

    do
    {
        printf("Urutkan berdasarkan (4 untuk keluar): \n"
               "1. NIM\n"
               "2. Nama\n"
               "3. Nilai\n");
        printf("Pilih Preferensi Pengurutan (1/2/3/4): ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            sortedByNim(data, size);
            break;
        case 2:
            sortedByNama(data, size);
            break;
        case 3:
            sortedByNilai(data, 0, size - 1);
            break;
        default:
            break;
        }
        display(data, size);
    } while (choice != 4);
}