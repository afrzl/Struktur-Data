#include <stdio.h>
#include <string.h>

struct Buku
{
    char judul[50];
    char pengarang[50];
    int id;
};

int main()
{
    struct Buku Buku1;
    struct Buku Buku2;

    /* Spesifikasi Buku 1 */
    strcpy(Buku1.judul, "C Programming");
    strcpy(Buku1.pengarang, "Nuha Ali");
    Buku1.id = 6495407;

    /* Spesifikasi Buku 2 */
    strcpy(Buku2.judul, "Telecom Billing");
    strcpy(Buku2.pengarang, "Zara Ali");
    Buku2.id = 6495700;

    /* Cetak informasi Buku 1 */
    printf("Judul Buku 1 : %s\n", Buku1.judul);
    printf("Pengarang Buku 1 : %s\n", Buku1.pengarang);
    printf("Id Buku 1 : %d\n\n", Buku1.id);

    /* Cetak informasi Buku 2 */
    printf("Judul Buku 2 : %s\n", Buku2.judul);
    printf("Pengarang Buku 2 : %s\n", Buku2.pengarang);
    printf("Id Buku 2 : %d\n", Buku2.id);

    return 0;
}
