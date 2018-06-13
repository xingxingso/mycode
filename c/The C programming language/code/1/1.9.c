#include <stdio.h>

int main(void)
{
    int c, d;
    d = 0;
    while((c=getchar()) != EOF)
    {
        if (d != ' ' || c != ' ')
            putchar(c);
        d = c;
    }

    return 0;
}
