/******************************************************
"Write the function itob(n,s,b) 
that converts the integer n into a base b character 
representation in the string s . 
In particular, 
itob(n,s,16) formats n as a hexadecimal integer in s ."

Author: Kant Chan (1126973789@qq.com) 
******************************************************/

#include <stdio.h>
#include <string.h>

void itob(int n, char s[], int b);
void reverse(char s[]);

int main(void)
{
    int n, b;
    char s[100];
    n = -1000;
    // n = -2147483648;
    b = 16;

    itob(n, s, b);
    printf("%s\n", s);

    return 0;
}

void itob(int n, char s[], int b)
{
    int i, sign;
    unsigned int c;

    char p[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    if ((sign=n) < 0)
        c = -n;
    else
        c = n;

    i = 0;
    do{
        s[i++] = p[c%b]; 
    } while ((c/=b) > 0);

    if (sign < 0) {
        // s[0] += 1;
        s[i++] = '-';
    }

    s[i] = '\0';
    reverse(s);
}

/* reverse: reverse string s in place */
void reverse(char s[])
{
    int c, i, j;
    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
