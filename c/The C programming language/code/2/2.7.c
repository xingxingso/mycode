/******************************************************
"Write a function invert(x,p,n) 
that returns x with the n bits 
that begin at position p inverted 
(i.e., 1 changed into 0 and vice versa), 
leaving the others unchanged."

Author: Kant Chan (1126973789@qq.com) 
******************************************************/

#include <stdio.h>

int invert(int x, int p, int n);

int main(void)
{
    int x,s,p,n;
    x = 123456;
    p = 6;
    n = 3;

    s = invert(x, p, n);

    printf("%d\n", s);

    return 0;
}

int invert(int x, int p, int n)
{
    return x ^ (~0<<(p+1) ^ ~0<<(p+1-n));
    // others solution
    // return x ^ ((~(~0<<n))<< p+1-n)
    // return (x ^ (((1 << (n)) - 1) << (p - n + 1)));
}

