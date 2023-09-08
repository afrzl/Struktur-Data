#include <stdio.h>

struct data_tanggal
{
    int tahun;
    int bulan;
    int tanggal;
} ultah;

int main(int argc, char const *argv[])
{
    // menginisialisasi elemen-elemen struct ultah
    ultah.tanggal = 5;  // ganti dengan tanggal lahir Anda
    ultah.bulan = 6;    // ganti dengan bulan lahir Anda
    ultah.tahun = 2003; // ganti dengan tahun lahir Anda

    // mengakses elemen-elemen struct ultah
    printf("tanggal = %d, bulan = %d, tahun = %d", ultah.tanggal, ultah.bulan, ultah.tahun);

    return 0;
}
