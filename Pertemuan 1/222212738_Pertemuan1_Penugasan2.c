#include <stdio.h>

int getKeliling(int panjang, int lebar)
{
    return 2 * (panjang + lebar);
}

int getLuas(int panjang, int lebar)
{
    return panjang * lebar;
}

int main(int argc, char const *argv[])
{
    int panjang, lebar, keliling, luas;
    printf("--- Aplikasi Luas Persegi Panjang ---\n");
    printf("Panjang: ");
    scanf("%d", &panjang);
    printf("Lebar: ");
    scanf("%d", &lebar);

    keliling = getKeliling(panjang, lebar);
    luas = getLuas(panjang, lebar);

    printf("\n=> Luas: %d\n=> Keliling: %d", luas, keliling);

    return 0;
}
