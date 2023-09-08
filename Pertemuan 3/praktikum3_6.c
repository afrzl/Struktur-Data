#include <stdio.h>

struct complex
{
    int imag;
    float real;
};

struct number
{
    struct complex comp;
    int integers;
} num1, num2;

int main(int argc, char const *argv[])
{
    num1.integers = 12;
    num1.comp.real = 44.12;
    num2.comp.imag = 11;

    printf("num integers = %d, comp real = %.2f, comp imag = %d\n", num1.integers, num1.comp.real, num2.comp.imag);

    return 0;
}
