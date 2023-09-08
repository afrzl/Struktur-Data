#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *nim;
    char *nama;
} dataMhs;

int main(int argc, char const *argv[])
{
    dataMhs data_mhs;

    data_mhs.nim = malloc(sizeof(int));
    if (data_mhs.nim == NULL)
    {
        printf("FAIL TO ALLOCATED MEMORY.");
        return 0;
    }

    printf("Masukkan NIM: ");
    scanf("%d", data_mhs.nim);

    data_mhs.nama = malloc(255 * sizeof(char));
    if (data_mhs.nama == NULL)
    {
        printf("FAIL TO ALLOCATED MEMORY.");
        return 0;
    }

    printf("Masukkan Nama: ");
    scanf(" %[^\n]s", data_mhs.nama);

    printf("-- HASIL --\n");
    printf("NIM: %d\nNama: %s", *data_mhs.nim, data_mhs.nama);

    free(data_mhs.nim);
    free(data_mhs.nama);

    return 0;
}
