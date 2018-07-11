/******************************************************
"Adapt the ideas of printd to write a recursive version of itoa ; 
that is, convert an integer into a string by calling a recursive routine."

Author: Kant Chan (1126973789@qq.com) 
******************************************************/

#include <stdio.h>

#define MAXLINE 1000

void itoa(int n, char s[]);

int main(void)
{
    int n;
    // static char s[MAXLINE];
    n = -5234;
    char s[] = "";

    itoa(n, s);
    printf("%s\n", s);

    return 0;
}

void itoa(int n, char s[])
{
    static int i;
    // i = 0;
    // i = strlen(s);

    if (n < 0) {
        s[strlen(s)] = '-'; 
        // s[i=0] = '-'; 
        n = -n;
    }
    
    if (n/10) 
        itoa(n/10, s); 

    s[strlen(s)] = n % 10 + '0';
    // s[i] = n % 10 + '0';

    
    s[strlen(s)+1] = '\0';
    
    printf("%d\n", n);
    printf("%s\n", s);
    // printf("%d\n", i);
    printf("%d\n", strlen(s));
}


/*
the default
 */
// void itoa(int n, char s[])
// {
//     int i, sign;

//     if ((sign = n) < 0) /* record sign */
//         n = -n; /* make n positive */

//     i = 0;
//     do { /* generate digits in reverse order */ 
//         s[i++] = n % 10 + '0'; /* get next digit */
//     } while ((n /= 10) > 0); /* delete it */

//     if (sign < 0)
//         s[i++] = '-';
    
//     s[i] = '\0';
//     reverse(s);
// }
