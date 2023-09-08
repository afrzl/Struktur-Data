#include <stdio.h>

struct dataMhs
{
    int nim;
    char nama[255];
    float nilai[3]; // index 0 : tugas, 1 : uts, 2 : uas
};

int main(int argc, char const *argv[])
{
    int jml_mhs;
    printf("Masukkan jumlah mahasiswa: ");
    scanf("%d", &jml_mhs);

    struct dataMhs data_mhs[jml_mhs];

    for (int i = 0; i < jml_mhs; i++)
    {
        printf("Mahasiswa ke-%d: \n", i + 1);
        printf("> NIM: ");
        scanf("%d", &data_mhs[i].nim);
        printf("> Nama: ");
        scanf(" %[^\n]s", data_mhs[i].nama);
        printf("> Nilai Tugas: ");
        scanf("%f", &data_mhs[i].nilai[0]);
        printf("> Nilai UTS: ");
        scanf("%f", &data_mhs[i].nilai[1]);
        printf("> Nilai UAS: ");
        scanf("%f", &data_mhs[i].nilai[2]);

        printf("\n");
    }

    printf("\n -- HASIL PENGOLAHAN NILAI AKHIR --\n\n  ");
    for (int i = 0; i < jml_mhs; i++)
    {
        printf("%d. %s\n", i + 1, data_mhs[i].nama);
        printf("Nilai Akhir: %.2f\n\n", data_mhs[i].nilai[0] * 0.3 + data_mhs[i].nilai[1] * 0.35 + data_mhs[i].nilai[2] * 0.35);
    }

    return 0;
}
