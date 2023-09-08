#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int nim;
    char nama[255];
} dataMhs;

int main(int argc, char const *argv[])
{
    dataMhs *data_mhs = malloc(sizeof(dataMhs));

    if (!data_mhs)
    {
        printf("FAIL TO ALLOCATED MEMORY.");
        return 0;
    }

    printf("Masukkan NIM: ");
    scanf("%d", &data_mhs->nim);
    printf("Masukkan Nama: ");
    scanf(" %[^\n]s", data_mhs->nama);

    printf("-- HASIL --\n");
    printf("NIM: %d\nNama: %s", data_mhs->nim, data_mhs->nama);

    free(data_mhs);

    return 0;
}
