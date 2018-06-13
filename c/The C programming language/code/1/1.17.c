#include <stdio.h>

void print_long_line();

#define LIM 10

int main(void)
{
    print_long_line();

    return 0;
}

void print_long_line()
{
    int len, i, c;
    len = 0;
    char line[LIM];

    while((c = getchar()) != EOF)
    {
        if (c != '\n' && len < LIM)
            line[len] = c;

        ++len;

        if (len == LIM+1 && c != '\n') {
            for (i = 0; i < LIM; ++i)
                putchar(line[i]);
            putchar(c);
        }

        if (len > LIM+1)
            putchar(c);

        if ( c == '\n')
            len = 0;
    }
}

