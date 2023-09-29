#include <stdio.h>

typedef struct
{
    int item[50];
    int jml_item;
} stack;

// menyiapkan tumpukan kosong
void initializestack(stack *s)
{
    s->jml_item = 0;
}

// jika tumpukan kosong maka nilai fungsinya 1 (true),
// jika tidak 0(false)
int isEmpty(stack *s)
{
    return (s->jml_item == 0);
}

// jika tumpukan sudah full(dlm deklarasi stack, field item // adalah array dg jumlah elemen sebanyak 50)maka nilai
// nilai fungsinya 1, jika tidak 0
int isFull(stack *s)
{
    return (s->jml_item == 50);
}

void push(int x, stack *s)
{
    if (isFull(&s))
        printf("Bilangan terlalu besar !\n");
    else
    {
        s->item[s->jml_item] = x;
        ++(s->jml_item);
    }
}

int pop(stack *s)
{
    if (isEmpty(&s))
        return (0);
    else
    {
        --(s->jml_item);
        return (s->item[s->jml_item]);
    }
}

void main()
{
    stack tumpukan;
    int bil_desimal;
    int sisa_bagi;

    printf("Program konversi Desimal ke Biner\n\n");

    initializestack(&tumpukan);

    printf("Masukkan bilangan desimal = ");
    scanf("%d", &bil_desimal);

    if (bil_desimal == 0)
        printf("Hasil konversi ke biner = 0");
    else
    {
        int n;
        for (n = bil_desimal; n > 0; n = n / 2)
        {
            sisa_bagi = n % 2;
            push(sisa_bagi, &tumpukan);
        }
        int i;
        printf("Hasil konversi ke biner = ");
        for (i = tumpukan.jml_item; i > 0; i--)
        {
            printf("%d", pop(&tumpukan));
        }
    }
}
