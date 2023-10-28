#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
    char string1[50], string2[50];
    strcpy(string1, "acb");
    strcpy(string2, "abc");

    int i = 0;

    while (string1[i] == string2[i] && string1[i] != '\0')
    {
        i++;
    }

    if (tolower(string1[i]) > tolower(string2[i]))
    {
        printf("%s %s", string2, string1);
    }
    else if (tolower(string1[i]) < tolower(string2[i]))
    {
        printf("%s %s", string1, string2);
    }
    else
        printf("Both strings are EQUAL\n");

    return 0;
}
