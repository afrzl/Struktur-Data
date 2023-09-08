#include <stdio.h>

int main()
{
    int a = 5;
    int *p;
    p = &a;
    printf("%p\n", p);
}