/******************************************************
"Write a version of itoa that accepts three arguments instead of two. 
The third argument is a minimum field width; 
the converted number must be padded with blanks 
on the left if necessary to make it wide enough."

Author: Kant Chan (1126973789@qq.com) 
******************************************************/

#include <stdio.h>

int main(void)
{
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
