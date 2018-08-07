/******************************************************
"Write the program tail, 
which prints the last n lines of its input. 
By default, n is 10, say, 
but it can be changed by an optional argument, 
so that 
    `tail -n`
prints the last n lines. 
The program should behave rationally no matter 
how unreasonable the input or the value of n. 
Write the program so it makes the best use of available storage; 
lines should be stored as in the sorting program of Section 5.6, 
not in a two-dimensional array of fixed size."

Author: Kant Chan (1126973789@qq.com) 
******************************************************/

#include <stdio.h>
#include <string.h>

#include "../alloc.c"

#define MAXLINES 5000

int atoint(char *);
int readlines(char *lineptr[], int nlines);
void tail(char *lineptr[], int n);

int main(int argc, char *argv[])
{
    char *lineptr[MAXLINES];

    char *p;

    int nlines;

    int n = 0;

    if(argc > 1 && (*++argv)[0] == '-') 
        n = atoint(++*argv);

    n = n ? n : 10;

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        n = n > nlines ? nlines : n;
        tail(lineptr, n);
        return 0;
    } else {
        printf("input too big to print\n");
        return 1;
    }
}

void tail(char *lineptr[], int n)
{
    while ((++lineptr)[0] != NULL)
        ;
    
    while (n-- > 0) 
        printf("%s\n", (lineptr-n-1)[0]);
}

int atoint(char *p)
{
    int sum = 0;

    while(*p >= '0' && *p <= '9') {
        sum = sum*10 + (*p - '0');
        ++p;
    }

    return sum;
}

#define MAXLEN 1000
int getline(char *, int);

int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;

    while ((len = getline(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else {
            line[len-1] = '\0'; /* delete newline */
            strcpy(p, line);
            lineptr[nlines++] = p;
        }

    return nlines;
}


/* getline: read a line, return length */
int getline(char *line, int max)
{
    char *p = line;
    // char *p;
    int c;
    // p = line;

    while (--max > 0 && (c=getchar()) != EOF && c != '\n')
        *line++ = c;

    if (c == '\n')
        *line++ = c;
    *line = '\0';

    return line - p;
}
