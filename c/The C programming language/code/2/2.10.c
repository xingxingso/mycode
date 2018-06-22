#include <stdio.h>

int main(void)
{
    char c1, c2;
    c1 = 'C';

    c2 = (c1>='A' && c1<='Z') ? c1+'a'-'A' : c1;

    printf("%c\n", c2);

    return 0;
}


