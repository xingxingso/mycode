/******************************************************
"Write a cross-referencer that prints a list of all words in a document, 
and, for each word, a list of the line numbers on which it occurs. 
Remove noise words like "the", "and," and so on."

Author: Kant Chan (1126973789@qq.com) 
******************************************************/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

// #include "../../helper/getword.h"
// #include "../../helper/getline.h"
#include "../../helper/getch.h"
// #include "../../helper/talloc.h"
#include "../../helper/mystrdup.h"


#define MAX_BUFFER   1024
#define MAXWORD 100

struct linelist {
  struct linelist *next;
  int line;
};

struct wordtree {
    char *word;
    int count;
    struct linelist *firstline;
    struct wordtree *left;
    struct wordtree *right;
};

/* wordtalloc:  make a wordtree */ 
struct wordtree *wordtalloc(void) 
{ 
    return (struct wordtree *) malloc(sizeof(struct wordtree)); 
} 

struct linelist *linelalloc(void)
{
    return (struct linelist *) malloc(sizeof(struct linelist));
}

/*count word with lines*/
int getWordWithLine(char *word, int lim, int *line) {
    int c;
    char *w = word;

    while (isspace(c = getch())) 
        if (c == '\n')
            (*line)++;

    if (c != EOF) 
        *w++ = c; 
    if (!isalpha(c)) { 
        if (c == '\n')
            (*line)++;
        *w = '\0';
        return c;
    } 
    for ( ; --lim > 0; w++) 
        if (!isalnum(*w = getch())) { 
            if (c == '\n')
                (*line)++;
            ungetch(*w); 
            break; 
        } 
    *w = '\0'; 
    return word[0]; 
}

struct linelist *addlink(int line)
{
    struct linelist *new = linelalloc();
    if(new != NULL) {
        new->line = line;
        new->next = NULL;
    }

    return new;
}

struct wordtree *addword(struct wordtree *p, char *w, int line) {
    int cond; 
    struct linelist *newline;

    if (p == NULL) {     /* a new word has arrived */ 
        p = wordtalloc();    /* make a new node */ 
        p->word = mystrdup(w); 
        p->count = 1; 
        p->left = p->right = NULL; 
        p->firstline = addlink(line);
    } else if ((cond = strcmp(w, p->word)) == 0) {
        p->count++;      /* repeated word */ 
        newline = addlink(line);
        newline->next = p->firstline;
        p->firstline = newline;
    } else if (cond < 0)   /* less than into left subtree */
        p->left = addword(p->left, w, line);
    else             /* greater than into right subtree */ 
        p->right = addword(p->right, w, line);

    return p; 
}

void printlist(struct linelist *list)
{
    if(list != NULL) {
        printlist(list->next);
        printf("%6d ", list->line);
    }
}

/* printtree:  in-order print of tree p */ 
void printtree(struct wordtree *p) 
{ 
    if (p != NULL) { 
        printtree(p->left);
        printf("%4d %s", p->count, p->word);
        printlist(p->firstline);
        printf("\n");
        printtree(p->right);
    }
} 

int main(void) {
    int line = 1;
    struct wordtree *root=NULL; 
    char word[MAXWORD];

    while (getWordWithLine(word, MAXWORD, &line) != EOF) {
        if (isalpha(*word)) 
            root = addword(root, word, line);
    }
    printtree(root);  
    return 0;
}
