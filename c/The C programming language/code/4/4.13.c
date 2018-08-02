/******************************************************
"Write a recursive version of the function reverse(s) , 
which reverses the string s in place."

Author: Kant Chan (1126973789@qq.com) 
******************************************************/

#include <stdio.h>

void reverse1(char s[], int i, int j);
void reverse(char s[]);

int main(void)
{
    char s[] = "awer1231l24ke34";
    char s2[] = "xyz";

    // reverse1(s, 0, strlen(s)-1);
    reverse(s);
    printf("%s\n", s);
    
    reverse(s2);
    printf("%s\n", s2);
    return 0;
}

/* recursive version of the function reverse(s) */
void reverse1(char s[], int i, int j)
{
    int tmp;
    if (i < j)
    {
        tmp = s[j];
        s[j--] = s[i];
        s[i++] = tmp;
        reverse1(s, i, j);
    }
}

// others's solution
void reverse(char s[]) 
{
    static int i = 0, j = 0;
    char c;
    
    if (j == 0)
        j = strlen(s) - 1;

    if (i < j)
        {
            c = s[i];
            s[i++] = s[j];
            s[j--] = c;
            reverse(s);
        }

        i = 0;
        j = 0;
}

/* reverse: reverse string s in place */
/*void reverse(char s[])
{
    int c, i, j;
    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}*/
