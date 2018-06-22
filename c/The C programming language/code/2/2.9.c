/******************************************************
"In a two's complement number system, 
x &= (x-1) deletes the rightmost 1-bit in x . 
Explain why. 
Use this observation to write a faster version of bitcount ."

Author: Kant Chan (1126973789@qq.com) 
******************************************************/

#include <stdio.h>

int bitcount (unsigned x);

int main(void)
{
    unsigned int x, nums;
    x = 0;
    nums = bitcount(x);
    printf("%d\n", nums);
    return 0;
}
    
/* bitcount:  count 1 bits in x */
int bitcount(unsigned x)
{
    int b;

    for (b = 0; x != 0; x &= (x-1))
        b++;
    return b;
}

/* bitcount: count 1 bits in x */
/*int bitcount (unsigned x)
{
    int b;
    if (x == 0)
    {
        return 0;
    }

    while ((x&=(x-1)) != 0)
            b++;
    return b+1;
}*/

/* bitcount: count 1 bits in x */
/*int bitcount (unsigned x)
{
    int b;

    for (b = 0; x != 0; x >>= 1)
        if (x & 01)
            b++;
    return b;
}*/
