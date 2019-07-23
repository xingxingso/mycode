/******************************************************
"Write a program to remove all comments from a C program. 
Don't forget to handle quoted strings and character 
constants properly. C comments do not nest."

Author: Kant Chan (1126973789@qq.com) 
******************************************************/

#include <stdio.h>

int main(void)
{
    int c, tmp, in_quto;
    tmp = EOF;
    while((c=getchar()) != EOF)
    {
        if (c == '/' && ((tmp=getchar())=='/' || tmp=='*')) {
            if (tmp == '/')
            {
                while((c=getchar())!=EOF && c!='\n');
            }

            if (tmp == '*')
            {
                while((c=getchar())!=EOF && !(c=='*' && (c=getchar())!=EOF && c=='/'));
            }
        } 
        else if(c=='\'' || c=='"') {
            putchar(c);
            in_quto = 1;
            
            while(in_quto && (tmp=getchar())!=EOF) {
                if (tmp == c)
                {
                    in_quto = 0;
                    putchar(tmp);
                }
                else if(tmp == '\\') {
                    putchar(tmp);
                    if((tmp = getchar()) != EOF) {
                        putchar(tmp);
                    }
                }else {
                    putchar(tmp);
                }
            }
            tmp = EOF;
        }
        else {
            putchar(c);
            if (tmp != EOF)
            {
                putchar(tmp);
            }
        }
        tmp = EOF;
    }
}
