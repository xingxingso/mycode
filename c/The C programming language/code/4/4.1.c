/******************************************************
"Write the function strrindex(s,t) , 
which returns the position of the rightmost occurrence of t in s , 
or -1 if there is none."

Author: Kant Chan (1126973789@qq.com) 
******************************************************/

#include <stdio.h>

int strindex(char s[], char t[]);

int main(void)
{
    char s[] = "This is a test, We can get some code from ithis";
    char t[] = "his";
    int x;

    x = strindex(s, t);

    printf("%d\n", x);

    return 0;
}

/*
desc
 */
int strindex(char s[], char t[])
{
    int i, j, k;
    for (i = strlen(s)-1; i >= 0; --i)
    {
        for (j = i, k = strlen(t)-1; k >= 0 && s[j] == t[k]; --k, --j)
            ;
        if (k == -1)
            return j+1;
    }

    return -1;
}

/*
order by ASC
 */
/*int strindex(char s[], char t[])
{
    int i, j, k, p;
    p = -1;
    for (i = 0; s[i] != '\0'; ++i)
    {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; ++k, ++j)
            ;
        if (k > 0 && t[k] == '\0')
            p = i;
    }

    return p;
}*/
