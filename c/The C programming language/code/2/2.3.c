#include <stdio.h>
#include <string.h>

int htos(char s[]);

int main(void)
{
    char test[] = "0x1aeef2";

    printf("%d\n",htos(test));
    

    return 0;
}

int htos(char s[])
{
    int len = strlen(s), i;
    int sum = 0;
    if (len>2 && s[0]=='0' && (s[1]=='x' || s[1]=='X'))
    {
        for (i=2; i < len; ++i){
            if (s[i] >= '0' && s[i] <= '9')
            {
                sum = sum*16 + s[i]-'0';
            }
            else if (s[i] >= 'a' && s[i] <= 'f')
            {
                sum = sum*16 + s[i] - 'a' + 10;
            }
            else if (s[i] >= 'A' && s[i] <= 'f')
            {
                sum = sum*16 + s[i] - 'A' + 10;
            }
            else {
                i = len;
                sum = 0;
            }
        }
    }

    return sum;
}
