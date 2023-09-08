#include <stdio.h>
void main()
{
    printf("## Program Antrian CS ##\n");
    char no_antrian[5] = {'A', 'B', 'C', 'D', 'E'};
    // menggunakan pointer
    char *ptr_current = &no_antrian;
    for (int i = 0; i < 5; i++)
    {
        printf(" Pelanggan dengan no antrian %c silahkan ke loket!\n", *ptr_current);
        printf("Saat ini CS sedang melayani: %c\n", *ptr_current);
        printf("-------- Tekan Enter untuk Next --------");
        getchar();
        ptr_current++;
    }
    printf("✅ Selesai");
}