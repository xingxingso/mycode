/******************************************************
"Define a macro swap(t,x,y) that interchanges two arguments of type t . 
(Block structure will help.)"

Author: Kant Chan (1126973789@qq.com) 
******************************************************/

#include <stdio.h>

// #define swap(t, x, y) t tmp; tmp=x; x=y; y=tmp; // live a tmp variable
#define swap(t, x, y) {t tmp; tmp=x; x=y; y=tmp;} // tmp will be null
#define dprinf(expr) printf(#expr " = %g\n", expr)

int main(void)
{
    // int x = 123;
    // int y = 34;

    double x = 123.124;
    double y = 34.34;

    swap(double, x, y);

    dprinf(x);
    dprinf(y);
    // printf("%g\n", tmp);

    return 0;
}
