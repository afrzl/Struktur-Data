#include <stdio.h>

struct dataAnak
{
    char *Nama[255];
    int *umur;
    char *TKPend[255];
};

int main()
{
    int jumlah_anak;
    printf("Jumlah Anak kandung : ");
    scanf("%d", &jumlah_anak);

    struct dataAnak Data[jumlah_anak];

    for (int i = 0; i < jumlah_anak; i++)
    {
        printf("\nData Anak ke-%d : \n", i + 1);
        printf("=> Nama :  ");
        scanf(" %[^\n]s", Data[i].Nama);
        printf("=> umur :  ");
        scanf(" %d", &Data[i].umur);
        printf("=> Tingkat Pendidikan (SD/SMP/SMA/Belum) :  ");
        scanf(" %[^\n]s", Data[i].TKPend);

        printf("\n");
    }

    printf("\n -- DATA ANAK KANDUNG --\n\n  ");
    for (int i = 0; i < jumlah_anak; i++)
    {
        printf("%d. %s\n", i + 1, Data[i].Nama);
        printf("Umur : %d\n\n", Data[i].umur);
        printf("Tingkat Pendidikan : %s\n\n", Data[i].TKPend);
    }
    return 0;
}