/**
 * Write a program to copy its input to its output, 
 * replacing each string of one or more blanks by a single blank.
 */

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
