#include <stdio.h>

#define MAXQUEUE 11

void reverse(char s[], int end);

int main(void)
{
    int end, c;
    char s[MAXQUEUE];
    end = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == '\n') {
            --end;
            reverse(s, end);
            putchar('\n');
            end = 0;
        } else {
            if (end < MAXQUEUE)
            {
                s[end] = c;
                end++;
            }
        }
    }

    return 0;
}

void reverse(char s[], int end)
{
    for (; end >= 0; --end)
    {
        putchar(s[end]);
    }
}
