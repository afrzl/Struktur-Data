#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100 // ukuran maksimum array

struct students
{
    int nim;
    char nama[50];
    int nilai;
};
typedef struct students data;

void fill_database(data database[], int *size)
{ // mengisi data
    printf("Input ukuran array (max 100): ");
    scanf("%d", size);
    for (int i = 0; i < *size; i++)
    {
        printf("Input data ke-%d: \n", i + 1);
        printf("NIM Students  : ");
        scanf("%d", &database[i].nim);
        printf("Nama Students : ");
        scanf("%s", database[i].nama);
        printf("Nilai Students: ");
        scanf("%d", &database[i].nilai);
        printf("\n");
    }
}

void pemilihan_naikturun()
{
    printf("Urutan yang Anda inginkan : \n");
    printf("1. Ascending (terurut naik) \n");
    printf("2. Descending (terurut turun) \n");
    printf("Pilihan anda : ");
}

void pemilihan_objek()
{
    printf("Urutkan berdasarkan : \n");
    printf("1. NIM \n");
    printf("2. Nama \n");
    printf("3. Nilai \n");
    printf("Pilihan anda : ");
}

void display(data stdnt[], int size)
{
    printf("Daftar siswa : \n");
    for (int i = 0; i < size; i++)
    {
        printf("Nama: %s \tNIM: %d \tNilai: %d\n", stdnt[i].nama, stdnt[i].nim, stdnt[i].nilai);
    }
}

void insertionSortAsc_nim(data stdnt[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = stdnt[i].nim;
        j = i - 1;
        while (j >= 0 && stdnt[j].nim > key)
        {
            stdnt[j + 1] = stdnt[j];
            j = j - 1;
        }
        stdnt[j + 1].nim = key;
    }
    display(stdnt, n);
}

void insertionSortDesc_nim(data stdnt[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = stdnt[i].nim;
        j = i - 1;
        while (j >= 0 && stdnt[j].nim < key)
        {
            stdnt[j + 1] = stdnt[j];
            j = j - 1;
        }
        stdnt[j + 1].nim = key;
    }
    display(stdnt, n);
}

void insertionSortAsc_nilai(data stdnt[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = stdnt[i].nilai;
        j = i - 1;
        while (j >= 0 && stdnt[j].nilai > key)
        {
            stdnt[j + 1] = stdnt[j];
            j = j - 1;
        }
        stdnt[j + 1].nilai = key;
    }
    display(stdnt, n);
}

void insertionSortDesc_nilai(data stdnt[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = stdnt[i].nilai;
        j = i - 1;
        while (j >= 0 && stdnt[j].nilai < key)
        {
            stdnt[j + 1] = stdnt[j];
            j = j - 1;
        }
        stdnt[j + 1].nilai = key;
    }
    display(stdnt, n);
}

void insertionSortAsc_nama(data stdnt[], int n)
{
    int i, j;
    char key[50];
    for (i = 1; i < n; i++)
    {
        strcpy(key, stdnt[i].nama);
        j = i - 1;
        while (j >= 0 && (strcasecmp(stdnt[i].nama, key) < 0))
        {
            stdnt[j + 1] = stdnt[j];
            j = j - 1;
        }
        strcpy(stdnt[j + 1].nama, key);
    }
    display(stdnt, n);
}

void insertionSortDesc_nama(data stdnt[], int n)
{
    int i, j;
    char key[50];
    for (i = 1; i < n; i++)
    {
        strcpy(key, stdnt[i].nama);
        j = i - 1;
        while (j >= 0 && (strcasecmp(stdnt[i].nama, key) > 0))
        {
            stdnt[j + 1] = stdnt[j];
            j = j - 1;
        }
        strcpy(stdnt[j + 1].nama, key);
    }
    display(stdnt, n);
}

int main()
{
    data data[MAX];
    int size, c; // ukuran array
    int pilihan_objek, pilihan_asc_desc, pilihan;
    fill_database(data, &size);
    display(data, size);
    do
    {
        pemilihan_objek();
        scanf("%d", &pilihan_objek);
        pemilihan_naikturun();
        scanf("%d", &pilihan_asc_desc);
        if (pilihan_asc_desc == 2)
            pilihan = pilihan_objek + 3;
        else
            pilihan = pilihan_objek;
        switch (pilihan)
        {
        case 1:
            insertionSortAsc_nim(data, size);
            break;
        case 2:
            insertionSortAsc_nama(data, size);
            break;
        case 3:
            insertionSortAsc_nilai(data, size);
            break;
        case 4:
            insertionSortDesc_nim(data, size);
            break;
        case 5:
            insertionSortDesc_nama(data, size);
            break;
        case 6:
            insertionSortDesc_nilai(data, size);
            break;
        default:
            break;
        }
        printf("\nDo you want to continue:(press 1 for yes)\t");
        scanf("%d", &c);
    } while (c == 1);
    return 0;
}