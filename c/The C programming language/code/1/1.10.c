/**
 * Write a program to copy its input to its output, 
 * replacing each tab by \t , each backspace by \b , and each backslash by \\ . 
 * This makes tabs and backspaces visible in an unambiguous way.
 */

#include <stdio.h>

int main(void) 
{
    int c, d;

    while((c=getchar()) != EOF)
    {
        d = 0;
        if(c == '\t' && (d=1))
            printf("\\t");
        if(c == '\b' && (d=1))
            printf("\\b");
        if(c == '\\' && (d=1))
            printf("\\\\");

        if (d==0)
            putchar(c);
    }

    return 0;
}
