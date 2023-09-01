/* Aturan Scope pada Bahasa C */
#include <stdio.h>

int main(int argc, char const *argv[])
{
    {
        int x = 10, y = 20; //(1)
        {
            printf("x = %d, y = %d\n", x, y); // print var x pada (1) dan var y pada (1)
            {
                int y = 40;                       //(2)
                x++;                              // increment var x pada (1)
                y++;                              // increment var y pada (2)
                printf("x = %d, y = %d\n", x, y); // print var x pada (1) dan var y pada (2)
            }
            printf("y = %d, y = %d\n", x, y); // print var x pada (1) dan var y pada (1)
        }
    }

    return 0;
}
