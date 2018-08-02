/******************************************************
"Write the function strend(s,t) , 
which returns 1 if the string t occurs at the end of the string s , 
and zero otherwise."

Author: Kant Chan (1126973789@qq.com) 
******************************************************/

#include <stdio.h>

int strend(char *, char *);

int main(void)
{
    char *s = "aaerwera";

    char *t = "";

    int f = strend(s ,t);

    printf("%d\n", f);

    return 0;
}

// bad
/*int strend(char *s, char *t)
{
    char *p, *p;

    for (; *s; ++s) {
        for(p = s; *p == *t; ++p, ++t) 
            if(*p == '\0' && *t == '\0')
                return 1;
    }

    return 0; 
}*/

// my first answer
int strend(char *s, char *t)
{
    char *p, *q;
    p=t;
    q=s;

    while(*s++);
    while(*t++);

    for (; *s == *t ; s--, t--)
        if (p == t && q <= s)
            return 1;

    return 0;
}
