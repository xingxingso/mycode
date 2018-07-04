/******************************************************
"Write a function expand(s1,s2) 
that expands shorthand notations like a-z 
in the string s1 into the equivalent complete list abc...xyz in s2 . 
Allow for letters of either case and digits, 
and be prepared to handle cases like a-b-c and a-z0-9 and -a-z . 
Arrange that a leading or trailing - is taken literally."

Author: Kant Chan (1126973789@qq.com) 
******************************************************/

#include <stdio.h>

#define MAXLINE 1000
void expand(char s1[], char s2[]);

int main(void)
{
    char s1[] = "a-b-z-0-9eees--we-";
    // char s2[] = ""; // eroor will cause memory problem
    char s2[MAXLINE];

    expand(s1, s2);
    printf("%s\n", s2);
    return 0;
}

void expand(char s1[], char s2[])
{
    int i, j;

    for (i=j=0; s1[i]!='\0'; ++i,++j)
    {
        if (i>0 
        && s1[i]=='-' 
        && s1[i+1]!='\0'
        && s1[i-1]+1<s1[i+1]
        && (
               (s1[i-1]>= 'a' && s1[i-1]<'z') && (s1[i+1]>'a' && s1[i+1]<='z')
            || (s1[i-1]>= 'A' && s1[i-1]<'Z') && (s1[i+1]>'A' && s1[i+1]<='Z')
            || (s1[i-1]>= '0' && s1[i-1]<'9') && (s1[i+1]>'0' && s1[i+1]<='9')
            )
        ) {
            for (i++, j--; s2[j] < s1[i];++j)
            {
                s2[j+1] = s2[j]+1;
            }
        }
        else {
            s2[j] = s1[i];
        }
    }

    s2[j+1] = '\0';
}

/*
失败案例一
 */
/*void expand(char s1[], char s2[])
{
    int i, j, k;

    for (i = 0, j=0; s1[i] != '\0'; ++i, ++j)
    {
        s2[j] = s1[i];
        if (s1[i+1] == '-' && s1[i+2] != '\0')
        {
            if (
                s1[i]<s1[i+2]
                && ( 
                       (s1[i]>= 'a' && s1[i]<='z') && (s1[i+2]>='a' && s1[i+2]<='z')
                    || (s1[i]>= 'A' && s1[i]<='Z') && (s1[i+2]>='A' && s1[i+2]<='Z')
                    || (s1[i]>= '0' && s1[i]<='9') && (s1[i+2]>='0' && s1[i+2]<='9')
                )
            ) {
                for (k = 1; s2[j] <= s1[i+2]; ++j, ++k)
                {
                    s2[j+1] = s1[i]+k;
                }
                i+=2;
            }
        }
    }

    s2[j+1] = '\0';
}*/
