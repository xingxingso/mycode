/******************************************************
"Write a program to remove all comments from a C program. 
Don't forget to handle quoted strings and character 
constants properly. C comments do not nest."

Author: Kant Chan (1126973789@qq.com) 
******************************************************/

#include <stdio.h>

int main(void)
{
    int c, tmp;
    tmp = EOF;

    while((c=getchar()) != EOF)
    {
        if (c == '/' && ((tmp=getchar())=='/' || tmp=='*'))
        {
            if (tmp == '/')
            {
                while((c=getchar())!=EOF && c!='\n');
            }
            else{
                while((c=getchar())!=EOF && !(c=='*' && ((c=getchar())!=EOF && c=='/')));
            }
        }
        else {
            putchar(c);

            if (tmp!=EOF && tmp!='/' && tmp!='*')
            {
                putchar(tmp);
                tmp = EOF;
            }
        }
    }
}
