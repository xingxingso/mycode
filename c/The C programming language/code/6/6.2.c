/******************************************************
"Write a program that reads a C program and prints in alphabetical order 
each group of variable names that are identical in the first 6 characters 
but different somewhere thereafter. 
Don't count words within strings and comments. 
Make 6 a parameter that can be set from the command line."

Author: Kant Chan (1126973789@qq.com) 
******************************************************/

#include <stdio.h>

#define MAXWORD 1000

struct tnode 
{
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
    struct tnode *child;
};

struct tnode *addtree(struct tnode *, char *, int);
void treeprint(struct tnode *);
int getword(char *, int);

int main()
{
    struct tnode *root;
    char word[MAXWORD];
    int len = 6;

    root = NULL;
    while (getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0]))
            root = addtree(root, word, len);
    }
    treeprint(root);

    return 0;
}

struct tnode *talloc(void);
char *strdup(char *);
char *stringsplite(char *, char **, int);

struct tnode *addtree(struct tnode *p, char *w, int len)
{
    int cond;
    char *pw;
    char *cw = w;
    struct tnode *addchildtree(struct tnode *, char *);

    pw = stringsplite(w, &cw, len);

    printf("%s\n", pw);
    printf("%s\n", pw);

    if (p == NULL)
    {
        p = talloc();
        p->word = strdup(pw);
        p->count = 1;
        p->child = p->left = p->right = NULL;
        p->child = addchildtree(p->child, cw);
    }
    /*else if ((cond = strncmp(w, p->word, len)) == 0)
        p->count++;
    else if (cond < 0)
        p->left = addtree(p->left, w, len);
    else 
        p->right = addtree(p->right, w, len);*/
    return p;
}

struct tnode *addchildtree(struct tnode *p, char *w)
{
    int cond;

    if (p == NULL) {    /* a new word has arrived */
        p = talloc();   /* make a new node */
        p->word = strdup(w);
        p->count = 1;
        p->child = p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0)
        p->count++;     /* repeated word */
    else if (cond < 0)  /* less than into left subtree */
        p->left = addchildtree(p->left, w);
    else                /* greater than into right subtree */
        p->right = addchildtree(p->right, w);
    return p;
}

void treeprint(struct tnode *p)
{
    if (p != NULL)
    {
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}

#include <stdlib.h>

struct tnode *talloc(void)
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}

char *strdup(char *s)
{
    char *p;

    p = (char *) malloc(strlen(s)+1);

    if (p != NULL)
        strcpy(p, s);
    return p;
}

// split a word into two 
char *stringsplite(char *word, char **cw, int len)
{
    char *p;

    p = (char *) malloc(strlen(word)+1);

    char *strRth = p;

    for (; len-- > 0 && (*p = *word); p++, word++)
        ;
    *p = '\0';

    *cw = word;

    return strRth;
}

int getword(char *word, int lim)
{
    int c, getch(void);
    void ungetch(int);
    char *w = word;

    while (isspace(c = getch()))
        ;
    if (c != EOF)
        *w++ = c;
    if (!isalpha(c))
    {
        *w = '\0';
        return c;
    }

    for (; --lim > 0; w++)
        if (!isalnum(*w = getch()))
        {
            ungetch(*w);
            break;
        }
    *w = '\0';
    return word[0];
}

#define BUFSIZE 100
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

int getch(void) /* get a (possibly pushed-back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
