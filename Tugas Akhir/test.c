#include <stdio.h>
#include <string.h>

int main()
{
    char string[] = "Test,string1,Test,string2:Test:string3";
    char *p;

    printf("String \"%s\" is split into tokens:\n", string);

    p = strtok(string, ",:");
    while (p != NULL)
    {
        printf("%s\n", p);
        p = strtok(NULL, ",:");
    }

    return 0;
}