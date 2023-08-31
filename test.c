#include <stdio.h>

int main()
{
    int nim;
    char str[100];
    printf("Masukkan Formulir Data Mahasiswa ini\n");
    printf("NIM : ");
    scanf("%d", &nim);
    printf("Nama : ");
    scanf(" %[^\n]s", str);
    printf("%s", str);

    return 0;
}