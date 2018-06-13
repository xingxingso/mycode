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
