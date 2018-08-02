/******************************************************
"Write getfloat , 
the floating-point analog of getint . 
What type does getfloat return as its function value?"

Author: Kant Chan (1126973789@qq.com) 
******************************************************/

#include <stdio.h>
#include "../fun.c"

double getfloat(double *pn);

int main(void)
{
    double pn;
    int c;

    c = getfloat(&pn);
    printf("%c\n", c);
    printf("%f\n", pn);

    return 0;
}

double getfloat(double *pn)
{
    int c, sign;
    int pwo = 1;

    while (isspace(c=getch()))
        ;

    if (!isdigit(c) && c!=EOF && c!='+' && c!='-')
    {
        ungetch(c);
        return 0;
    }

    sign = c == '-' ? -1 : 1;

    if (c == '+' || c == '-')
        c = getch();

    for (*pn=0; isdigit(c); c=getch())
        *pn = 10* *pn + (c - '0');
        
    if (c == '.')
    {
        c = getch();
        for (; isdigit(c); c=getch())
        {
            pwo *= 10;
            *pn = 10* *pn + (c - '0');
        }
    }

    *pn /= pwo;

    *pn *= sign;

    if (c == EOF)
        ungetch(c);

    return 0;
}

