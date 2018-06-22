/* The following function, "getbits", is from K&R p 49 */ 
/* getbits: get n bits from position p */
unsigned getbits(unsigned x, int p, int n) 
{
  return (x >>(p+1-n) & ~(~0 << n));
}


/******************************************/ 
/* asbits - shows integers as bit strings.*/ 
/* Usage: */ /* asbits(x, sizeof(x), FLAG) */
/* FLAG = 1|0, showing if newline desired */
/******************************************/

void asbits(unsigned x, size_t s, int nl) 
{ 
    int i;

    for(i = s*8-1; i>=0; i--) { 
        getbits(x, i, 1)? putchar('1') : putchar('0'); 
        if(!(i%4))putchar(' '); 
    } 
    if(nl)putchar('\n'); 
}

unsigned setbits(unsigned x, int p, int n, unsigned y) 
{ 
    unsigned msk = ~(~0 << n); 
    return (x & ~(msk<< p+1-n)) | ((y & msk)<< p+1-n); 
}
