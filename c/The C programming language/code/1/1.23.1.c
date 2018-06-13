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
