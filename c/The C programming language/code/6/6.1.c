/******************************************************
"Our version of getword does not properly handle underscores, 
string constants, comments, 
or preprocessor control lines. Write a better version."

Author: Kant Chan (1126973789@qq.com) 
******************************************************/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100
#define NKEYS (sizeof keytab / sizeof(struct key))

struct key {
    char *word;
    int count;
};

struct key keytab[] = {
    "auto", 0,  
    "break", 0, 
    "case", 0,  
    "char", 0,
    "const", 0,
    "continue", 0,
    "default", 0,
    "define", 0,
    "if", 0,
    "unsigned", 0,
    "void", 0,
    "volatile", 0,
    "while", 0
};

int getword(char *, int);
int binsearch(char *, struct key *, int);

/* count C keywords */
main()
{
    int n;
    char word[MAXWORD];

    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            if ((n = binsearch(word, keytab, NKEYS)) >= 0)
                keytab[n].count++;
    for (n = 0; n < NKEYS; n++)
        if (keytab[n].count > 0)
            printf("%4d %s\n",
                keytab[n].count, keytab[n].word);
    return 0;
}

/* binsearch: find word in tab[0]...tab[n-1] */
int binsearch(char *word, struct key tab[], int n)
{
    int cond;
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low+high) / 2;
        if ((cond = strcmp(word, tab[mid].word)) < 0)
            high = mid - 1;
        else if (cond > 0)
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

#include "../getch.c"

getword(char *word, int lim)
{
    int c, getch(void);
    void ungetch(int);
    char *w = word;
    void readQuto(int);
    void readComment(int);

    while(isspace(c=getch()))
        ;

    if (c == '\'' || c == '"')
    {
        readQuto(c);
        *w++ = c;
        *w = '\0';
        return c;
    }
    else if (c == '/' && ((c=getch()) == '/' || c == '*'))
    {
        readComment(c);
        *w++ = c;
        *w = '\0';
        return c;
    }
    else if (c != EOF)
        *w++ = c;

    if (!(isalpha(c) || c == '_')) {
        *w = '\0';
        return c;
    }

    for ( ; --lim > 0; w++)
        if (!(isalnum(*w = getch()) || *w == '_')) {
            ungetch(*w);
            break;
        }
    *w = '\0';
    return word[0];

}   

void readQuto(int quto)
{
    int c;
    while ((c = getch()) != EOF)
        if (c == '\\')
            c = getch();
        else if ( c == quto)
            break;

}

void readComment(int type)
{
    int c;
    if (type == '/')
    {
        while ((c=getch()) != EOF && c!='\n')
            ;
    }
    else if (type == '*')
    {
        while ((c=getch()) != EOF)
            if (c == '*') {
                while ((c=getch()) == '*')
                    ;
                if (c == '/')
                    break;
            }
    }
}
