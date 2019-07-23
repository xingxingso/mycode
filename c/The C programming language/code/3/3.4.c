/******************************************************
"In a two's complement number representation, 
our version of itoa does not handle the largest negative number, 
that is, the value of n equal to -(2 to the power (wordsize - 1)) . 
Explain why not. 
Modify it to print that 
value correctly regardless of the machine on which it runs."

Author: Kant Chan (1126973789@qq.com) 
******************************************************/

#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

void itoa(int n, char s[]);
void itoa2(int n, char s[]);
void reverse(char s[]);

int main(void)
{
    char s[MAXLINE];
    // int n = -32768;
    // int n = -2147483648;
    int n = 0;

    // itoa(n,s);
    itoa2(n,s);
    printf("%s\n", s);
    return 0;
}


void itoa2(int n, char s[])
{
    int i, sign;
    if ((sign = n) < 0) /* record sign */
        n = -n-1; /* make n positive */
    i = 0;
    do { /* generate digits in reverse order */
        s[i++] = n % 10 + '0'; /* get next digit */
    } while ((n /= 10) > 0); /* delete it */
    if (sign < 0){
        s[0] += 1;
        s[i++] = '-';
    }
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
