#include <string.h>
#include <stdio.h>

typedef struct
{
    char nama[50];
    int nim;
} mhs;

int binary_search_name(mhs data[], int size, char x[])
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(data[i].nama, x) == 0)
            return i;
    }

    return -1;
}

void display(mhs data[], int size)
{
    printf("List of mahasiswa: \n");
    for (int i = 0; i < size; i++)
    {
        printf("No. [%d]\nNIM: %d\nName: %s\n", i + 1, data[i].nim, data[i].nama);
    }
}

int main()
{
    mhs array[3];
    array[0].nim = 222212738;
    strcpy(array[0].nama, "afrizal");
    array[1].nim = 222212739;
    strcpy(array[1].nama, "rizal");
    array[2].nim = 222212740;
    strcpy(array[2].nama, "ijal");

    // display(array, 3);

    char x[50];
    strcpy(x, "ijal");

    printf("%d\n", binary_search_name(array, 3, x));
}