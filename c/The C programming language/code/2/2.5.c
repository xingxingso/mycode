/******************************************************
"Write the function any(s1,s2) , 
which returns the first location in the string s1 
where any character from the string s2 occurs, 
or -1 if s1 contains no characters from s2 . 
(The standard library function strpbrk does the same job
 but returns a pointer to the location.)"

Author: Kant Chan (1126973789@qq.com) 
******************************************************/

#include <stdio.h>

int any(char s1[], char s2[]);

int main(void)
{
    char s1[] = "awerwer12312423424";
    char s2[] = "ssrw23423";
    int pos;
    pos = any(s1,s2);

    printf("%d\n", pos);
    return 0;
}

int any(char s1[], char s2[])
{
    int i,j;

    for (j = 0; s2[j] != '\0'; ++j)
    {
        for (i = 0; s1[i] != '\0'; ++i)
        {
            if (s2[j] == s1[i])
            {
                return i;
            }
        }
    }

    return -1;
}
