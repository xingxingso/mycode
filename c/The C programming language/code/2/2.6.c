/******************************************************
"Write a function setbits(x,p,n,y) 
that returns x with the n bits 
that begin at position p set to the rightmost n bits of y, 
leaving the other bits unchanged."

Author: Kant Chan (1126973789@qq.com) 
******************************************************/

#include <stdio.h>

int setbits(int x, int p, int n, int y);

int main(void)
{
    int x,y,s,p,n;
    x = 3432;
    y = 230;
    p = 5;
    n = 4;

    s = setbits(x, p, n, y);

    printf("%d\n", s);

    return 0;
}

int setbits(x, p, n, y)
{
    int tmp;
    tmp = ~0<<(p+1) ^ ~0<<(p+1-n);

    return (tmp|x) & (~tmp|(y<<(p+1-n)));    
}
