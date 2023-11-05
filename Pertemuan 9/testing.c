#include <string.h>

int main(int argc, char const *argv[])
{
    char string1[] = "b";
    char string2[] = "a";

    printf("%d", strcasecmp(string1, string2));

    return 0;
}
