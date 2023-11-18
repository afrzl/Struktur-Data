#include <stdio.h>
#define MAX 100 // ukuran maksimum array

void fill_data(int data[], int *size)
{ // mengisi data
    printf("Input ukuran array (max 100): ");
    scanf("%d", size);
    printf("Input data ascending: ");
    for (int i = 0; i < *size; i++)
    {
        scanf("%d", &data[i]);
    }
}

int binary_search(int data[], int size, int x)
{
    int L = 0;
    int H = size - 1;
    int M = -1;
    int index = -1;
    while (L <= H)
    {
        M = (L + H) / 2;
        if (data[M] == x)
            return M;
        else
        {
            if (data[M] < x)
                L = M + 1;
            else
                H = M - 1;
        }
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

    if (binary_search(data, size, x) == -1)
        printf("tidak ditemukan");
    else
        printf("ditemukan pada indeks ke-%d", binary_search(data, size, x));
}
