/**
 * Write a function rightrot(x,n) that 
 * returns the value of the integer x rotated to the right by n bit positions.
 */

#include <stdio.h>
#include "pilcrow.h"

unsigned int rightrot(unsigned int x, int n)
{
    int m, i;

    for(i=0; i < n; i++) {
        m = getbits(x, 0, 1);
        m <<= (sizeof(m)*8-1);
        x >>= 1;
        x |= m;
    }
    return x;
}

int main(void)
{
    unsigned int x = 0xabcdef12;
    int n = 8;

    printf("rotate right %u bits\n", n);
    asbits(x,sizeof(x),1);
    asbits(rightrot(x,n),sizeof(x),1);
    return 0;
}
