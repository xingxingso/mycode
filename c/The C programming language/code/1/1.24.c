/******************************************************
"Write a program to check a C program for rudimentary 
syntax errors like unbalanced parentheses, brackets and braces. 
Don't forget about quotes, both single and double, 
escape sequences, and comments. 
(This program is hard if you do it in full generality.)"

Author: Kant Chan (1126973789@qq.com) 
******************************************************/

#include <stdio.h>

#define MAXLINE 1000

int free_left_symbol(char s[], int c, int pos);

int main(void)
{
    int c, lin, i;
    char left[MAXLINE];
    char lines[MAXLINE];
    int lnums;
    int is_error = 0;
    int in_quto;
    char quto;
    int in_comment;
    char comment;

    lin = 1;
    lnums = 0;
    in_quto = in_comment = 0;
    left[0] = EOF;

    while (!is_error && (c=getchar()) != EOF)
    {
        // count line
        if (c == '\n')
        {
            ++lin;
        }

        if (!is_error && !in_quto && !in_comment) {
            if (c=='\'' || c=='"')
            {
                in_quto = 1;
                quto = c;
            }
            else if (c == '/')
            {
                if ((c=getchar())!=EOF && (c=='/' || c=='*'))
                {
                    in_comment = 1;
                    comment = c;
                }
                else if (c=='\'' || c=='"')
                {
                    in_quto = 1;
                    quto = c;
                }

               // count line
               if (c == '\n')
                   ++lin;
            }

            if (c == '{' || c == '[' || c== '(')
            {
                left[lnums] = c;
                lines[lnums] = lin;
                ++lnums;
            } 
            else if (c=='}' || c==']' || c==')')
            {
                if (lnums <= 0 || free_left_symbol(left, c, lnums-1) == -1)
                {
                    is_error = 1;
                }
                else {
                    lines[lnums] = 0;
                    --lnums;
                }
            }
        }

        while(in_quto && (c=getchar())!=EOF) {
            // count line
            if (c == '\n')
                ++lin;
    
            if (c == '\\')
            {
                c = getchar();
                // count line
                if (c == '\n')
                    ++lin;
            }
            else if (c == quto){
                in_quto = 0;
            }
        }

        while(in_comment && (c=getchar())!=EOF)
        {
            // count line
            if (c == '\n')
                ++lin;
            if (comment == '/')
            {
                if ( c == '\n')
                    in_comment = 0;
            }
            else if (comment == '*')
            {
                if (c == '*')
                {
                    while ((c=getchar())=='*');
                    // count line
                    if (c == '\n')
                        ++lin;
                    if (c == '/')
                    {
                        in_comment = 0;
                    }
                }
            }
        }
    }

    if (is_error)
    {
        printf("The error line is %d\n", lin);
    } 
    else if (lnums != 0)
    {
        printf("The miss line is the %d, on the line %d\n", lnums, lines[lnums-1]);
    }

    return 0;
}


int free_left_symbol(char s[], int c, int pos)
{
    int lc;
    if (c == '}')
        lc = '{';
    else if (c == ']')
        lc = '[';
    else if (c == ')')
        lc = '(';

    if (s[pos] != lc)
    {
        return -1;
    }

    s[pos] = EOF;

    return 0;
}
