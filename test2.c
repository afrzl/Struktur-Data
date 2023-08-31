#include <stdio.h>

int main()
{
    int nim;
    char nama[50];
    // float kuis, uts, uas, akhir;

    printf("Masukkan Formulir Data Mahasiswa ini\n");
    printf("NIM : ");
    scanf("%d", &nim);
    char str[100];
    scanf("%[^\n]s", str);
    printf("%s", str);
    // printf("Nama : ");
    // scanf("%[^\n]s", nama);
    // printf("Nilai Kuis : ");
    // scanf("%f", &kuis);

    return 0;
}