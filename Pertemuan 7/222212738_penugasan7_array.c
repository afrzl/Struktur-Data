#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nama[20];
    int alpro;
    int kalkulus;
} Mahasiswa;

int count = 0;

void enqueue(Mahasiswa arr[], char nama[], int alpro, int kalkulus)
{
    if (count < 5)
    {
        strcpy(arr[count].nama, nama);
        arr[count].alpro = alpro;
        arr[count].kalkulus = kalkulus;
        (count)++;
    }
    else
    {
        int minIndex = 0;
        for (int i = 1; i < 5; i++)
        {
            if (arr[i].alpro < arr[minIndex].alpro ||
                (arr[i].alpro == arr[minIndex].alpro && arr[i].kalkulus < arr[minIndex].kalkulus))
            {
                minIndex = i;
            }
        }

        if (alpro > arr[minIndex].alpro || (alpro == arr[minIndex].alpro && kalkulus > arr[minIndex].kalkulus))
        {
            strcpy(arr[minIndex].nama, nama);
            arr[minIndex].alpro = alpro;
            arr[minIndex].kalkulus = kalkulus;
        }
    }
}

void tampilkanMahasiswa(Mahasiswa arr[], int count)
{
    if (count == 0)
    {
        printf("Belum ada yang daftar\n");
    }
    else
    {
        printf("Daftar 5 Mahasiswa Terbaik (urutan dari nilai terbaik):\n");
        for (int i = 0; i < count; i++)
        {
            printf("Nama: %s | Alpro: %d | Kalkulus: %d\n", arr[i].nama, arr[i].alpro, arr[i].kalkulus);
        }
    }
}

int main()
{
    Mahasiswa mahasiswa[5];

    enqueue(mahasiswa, "Budi", 50, 20);
    enqueue(mahasiswa, "Eko", 50, 20);
    enqueue(mahasiswa, "bambang", 60, 20);
    enqueue(mahasiswa, "Eka", 60, 20);
    enqueue(mahasiswa, "wawo", 60, 20);
    enqueue(mahasiswa, "Ame", 60, 30);

    tampilkanMahasiswa(mahasiswa, count);

    return 0;
}
