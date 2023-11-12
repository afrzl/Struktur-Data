#include <stdio.h>

int change(int array[][3])
{
    array[0][0] = 2;

    return 0;
}

int main(int argc, char const *argv[])
{
    int array[2][3] = {{1, 1, 1}, {2, 2, 2}};

    printf("%d\n", array[0][0]);
    change(array);

    printf("%d", array[0][0]);

    return 0;
}
