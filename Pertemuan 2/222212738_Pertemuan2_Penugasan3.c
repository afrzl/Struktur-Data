#include <stdio.h>

int main(int argc, char const *argv[])
{
    int matriks[3][4];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("Masukkan nilai element matriks ke %d, %d: ", i + 1, j + 1);
            scanf("%d", &matriks[i][j]);
        }
    }
    printf("\nHasil matriks:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", matriks[i][j]);
        }
        printf("\n");
    }

    return 0;
}
