#include <stdio.h>
#include <stdbool.h>

#define MAX 100 // ukuran maksimum array

void fill_data(int data[], int *size)
{ // mengisi data
    printf("Input ukuran array (max 100): ");
    scanf("%d", size);
    printf("Input data (secara urut menaik/menurun): ");
    for (int i = 0; i < *size; i++)
    {
        scanf("%d", &data[i]);
    }
}

bool checkAscending(int data[], int size)
{
    if (size <= 1)
        return true;

    for (int i = 1; i < size; i++)
    {
        if (data[i - 1] > data[i])
            return false;
    }
    return true;
}

bool checkDescending(int data[], int size)
{
    if (size <= 1)
        return true;

    for (int i = 1; i < size; i++)
    {
        if (data[i - 1] > data[i])
            return false;
    }
    return true;
}

int seq_search(int data[], int size, int x)
{
    if (checkAscending(data, size))
    {
        for (int i = 0; i < size; i++)
        {
            if (data[i] > x)
                return -1;
            if (data[i] == x)
                return i;
        }
    }

    if (checkDescending(data, size))
    {
        for (int i = 0; i < size; i++)
        {
            if (data[i] < x)
                return -1;
            if (data[i] == x)
                return i;
        }
    }

    for (int i = 0; i < size; i++)
    {
        if (data[i] == x)
            return i;
    }

    return -1;
}

void main()
{
    int data[MAX];
    int size; // ukuran array
    int x;

    fill_data(data, &size);
    printf("nilai yang mau dicari: ");
    scanf("%d", &x);

    if (seq_search(data, size, x) == -1)
        printf("tidak ditemukan");
    else
        printf("ditemukan pada indeks ke-%d", seq_search(data, size, x));
}
