/******************************************************
"Write a version of itoa that accepts three arguments instead of two. 
The third argument is a minimum field width; 
the converted number must be padded with blanks 
on the left if necessary to make it wide enough."

Author: Kant Chan (1126973789@qq.com) 
******************************************************/

#include <stdio.h>

void itoa2(int n, char s[], int min);
void itoa(int n, char s[]);
void reverse(char s[]);

#define MAXLINE 1000

int main(void)
{
    char s[MAXLINE];
    // int n = -32768;
    // int n = -2147483648;
    int n = -123;
    int min = 12;

    // itoa(n,s);
    itoa2(n,s, min);
    printf("%s\n", s);
    return 0;
}

void itoa2(int n, char s[], int min)
{
    int i, sign;
    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0)
        s[i++] = '-';

    while(i < min)
        s[i++] = '*';

    s[i] = '\0';
    reverse(s);
}

/* itoa: convert n to characters in s */
void itoa(int n, char s[])
{
    int i, sign;
    if ((sign = n) < 0) /* record sign */
        n = -n; /* make n positive */
    i = 0;
    do { /* generate digits in reverse order */
        s[i++] = n % 10 + '0'; /* get next digit */
    } while ((n /= 10) > 0); /* delete it */
    if (sign < 0)
        s[i++] = '-';
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
