#include <string.h>

void reverse(char s[]) 
{
    static int i = 0, j = 0;
    char c;
    
    if (j == 0)
        j = strlen(s) - 1;

    if (i < j)
        {
            c = s[i];
            s[i++] = s[j];
            s[j--] = c;
            reverse(s);
        }

        i = 0;
        j = 0;
}
