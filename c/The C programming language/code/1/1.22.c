#include <stdio.h>

#define RULES 80
// #define RULES 81

int get_nospace_line(char line[], int maxline);

int main(void)
{
    int p, nums, i, c;
    i = nums = 0;
    char s[RULES];

    while ((c=getchar()) != EOF)
    {
        if (c == '\n') {
            putchar(c);
            nums = 0;
            i = 0;
        }
        else if (c != ' ')
        {
            s[i] = '\0';
            printf("%s", s);
            i = 0;
            if (nums < RULES-1)
            {
                putchar(c);
                p = nums;
                ++nums;
            } else {
                putchar('\n');
                putchar(c);
                nums = 0;
            }
        }
        else {
            ++nums;
            if (i < RULES-2) {
                s[i] = c;
                ++i;
            } else {
                s[i] = '\0';
                printf("%s", s);
                i = 0;
                putchar('\n');
                nums = 0;
            }
        }
    }

    /*while(get_nospace_line(s, RULES) > 0)
    {
        printf("%s", s);
    }*/
}

int get_nospace_line(char line[], int lim)
{
    int i, m, c;
    m = 0;

    for (i=0; i < lim-2 && (c=getchar())!=EOF && c!='\n'; ++i) {
        line[i] = c;
        if (c != ' ')
            m = i;
    }

    if (c == '\n')
        ++i;

    line[m+1] = '\n';
    line[m+2] = '\0';

    return i;
}

