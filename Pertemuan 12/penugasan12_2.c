#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#define MAX 100

void fill_data(int data[], int *size)
{
    printf("Input Jumlah Data = ");
    scanf("%d", size);
    printf("Input data: ");
    for (int i = 0; i < *size; i++)
    {
        scanf("%d", &data[i]);
    }
}

void insertionSort(int arr[], int n, bool ascending)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        if (ascending)
        {
            while (j >= 0 && arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
        }
        else
        {
            while (j >= 0 && arr[j] < key)
            {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
        }

        arr[j + 1] = key;
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int data[], int size, bool ascending)
{
    for (int step = 0; step < size - 1; step++)
    {
        int min_idx = step;
        for (int i = step + 1; i < size; i++)
            if (ascending)
            {
                if (data[i] < data[min_idx])
                    min_idx = i;
            }
            else
            {
                if (data[i] > data[min_idx])
                    min_idx = i;
            }

        swap(&data[min_idx], &data[step]);
    }
}

void bubbleSort(int arr[], int n, bool ascending)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
        {
            if (ascending)
            {
                if (arr[j] > arr[j + 1])
                    swap(&arr[j], &arr[j + 1]);
            }
            else
            {
                if (arr[j] < arr[j + 1])
                    swap(&arr[j], &arr[j + 1]);
            }
        }
}

void merge(int arr[], int l, int m, int r, bool ascending)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (ascending)
        {
            if (L[i] <= R[j])
            {
                arr[k] = L[i];
                i++;
            }
            else
            {
                arr[k] = R[j];
                j++;
            }
        }
        else
        {
            if (L[i] >= R[j])
            {
                arr[k] = L[i];
                i++;
            }
            else
            {
                arr[k] = R[j];
                j++;
            }
        }

        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r, bool ascending)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m, ascending);
        mergeSort(arr, m + 1, r, ascending);
        merge(arr, l, m, r, ascending);
    }
}

void tampil_data(int data[], int size)
{
    printf("Data setelah diurutkan: ");
    for (int i = 0; i < size; i++)
        printf("%d ", data[i]);
    printf("\n");
}

int main(int argc, char const *argv[])
{
    int data[MAX];
    int size, metode;
    char pengurutan = 'n';
    bool ascending = true;

    printf("###PROGRAM SORTING DATA###\n");
    fill_data(data, &size);

    printf("Metode Sorting yang tersedia\n"
           "1. Insertion Sort\n"
           "2. Selection Sort\n"
           "3. Merge Sort\n"
           "4. Bubble Sort\n");
    do
    {
        printf("Pilih Metode Sorting (1/2/3/4): ");
        scanf("%d", &metode);
    } while (metode > 4 || metode < 1);

    do
    {
        printf("Pilih pengurutan Naik/Turun (N/T): ");
        scanf(" %c", &pengurutan);
    } while ((tolower(pengurutan) != 'n') && (tolower(pengurutan) != 't'));

    if ((tolower(pengurutan) == 't'))
        ascending = false;

    switch (metode)
    {
    case 1:
        insertionSort(data, size, ascending);
        break;
    case 2:
        selectionSort(data, size, ascending);
        break;
    case 3:
        mergeSort(data, 0, size - 1, ascending);
        break;
    case 4:
        bubbleSort(data, size, ascending);
        break;
    default:
        break;
    }

    tampil_data(data, size);

    return 0;
}
