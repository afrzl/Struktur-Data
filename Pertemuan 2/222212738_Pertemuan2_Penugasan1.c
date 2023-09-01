#include <stdio.h>

int main(int argc, char const *argv[])
{
    printf("%lu\n", sizeof(char));
    printf("%lu\n", sizeof(int));
    printf("%lu\n", sizeof(float));
    printf("%lu", sizeof(double));

    return 0;
}
