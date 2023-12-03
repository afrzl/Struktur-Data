#include <stdio.h>
#define MAX 100 // ukuran maksimum array

void fill_data(int data[], int *size)
{ // mengisi data
    printf("Input ukuran array (max 100): ");
    scanf("%d", size);
    printf("Input data: ");
    for (int i = 0; i < *size; i++)
    {
        scanf("%d", &data[i]);
    }
}

void tampil_data(int data[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", data[i]);
    printf("\n");
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int data[], int size)
{
    for (int step = 0; step < size - 1; step++)
    {
        int min_idx = step;
        for (int i = step + 1; i < size; i++)
            if (data[i] < data[min_idx])
                min_idx = i;
        swap(&data[min_idx], &data[step]);
    }
}

void main()
{
    int data[MAX];
    int size; // ukuran array yang dipakai
    fill_data(data, &size);
    selection_sort(data, size);
    printf("data setelah diurutkan:\n");
    tampil_data(data, size);
}
