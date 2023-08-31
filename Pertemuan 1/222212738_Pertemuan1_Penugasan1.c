#include <stdio.h>

int main(int argc, char const *argv[])
{
    int nim, kuis, uts, uas;
    char nama[255];

    printf("--- Aplikasi Pengolah Data Mahasiswa ---\n");
    printf("NIM: ");
    scanf("%d", &nim);
    printf("Nama: ");
    scanf(" %[^\n]s", nama);
    printf("Nilai Kuis: ");
    scanf("%d", &kuis);
    printf("Nilai UTS: ");
    scanf("%d", &uts);
    printf("Nilai UAS: ");
    scanf("%d", &uas);

    printf("\n\n--- Aplikasi Pengolah Data Mahasiswa ---\n");
    printf("NIM: %d\nNama: %s\n", nim, nama);
    printf("Nilai Kuis: %d\nNilai UTS: %d\nNilai UAS: %d\n", kuis, uts, uas);
    printf("=> Nilai Akhir: %0.2f", 0.2 * kuis + 0.3 * uts + 0.5 * uas);

    return 0;
}
