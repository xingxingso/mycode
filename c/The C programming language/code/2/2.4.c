/******************************************************
"Write an alternate version of squeeze(s1,s2) 
that deletes each character in the string s1 
that matches any character in the string s2 ."

Author: Kant Chan (1126973789@qq.com) 
******************************************************/
#include <stdio.h>

void squeeze(char s1[], char s2[]);

int main(void)
{
    char s1[] = "aserwerwr1231ewr[l[e,raw,e/aer'w.r";
    char s2[] = "1231sdwe";

    squeeze(s1, s2);
    printf("%s\n", s1);

    return 0;
}

void squeeze(char s1[], char s2[])
{
    int i, j, k;
    i = k = 0;

    while (s1[i]!='\0')
    {
        j = 0;
        while(s2[j]!='\0' && s1[i]!=s2[j] && ++j);
        if (s2[j] == '\0')
            s1[k++] = s1[i];
        ++i;
    }
    s1[k] = '\0';
}
