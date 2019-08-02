#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../../helper/mystrdup.h"

struct nlist {       /* table entry: */ 
    struct nlist *next;   /* next entry in chain */ 
    char *name;           /* defined name */ 
    char *defn;           /* replacement text */ 
};

#define HASHSIZE 101 
static struct nlist *hashtab[HASHSIZE];  /* pointer table */ 

/* hash:  form hash value for string s */ 
unsigned hash(char *s) 
{ 
    unsigned hashval; 

    for (hashval = 0; *s != '\0'; s++) 
        hashval = *s + 31 * hashval; 
    return hashval % HASHSIZE; 
} 

/* lookup:  look for s in hashtab */ 
struct nlist *lookup(char *s) 
{ 
    struct nlist *np; 

    for (np = hashtab[hash(s)]; np != NULL; np = np->next) 
        if (strcmp(s, np->name) == 0) 
            return np;     /* found */ 
    return NULL;           /* not found */ 
}

/* install:  put (name, defn) in hashtab */ 
struct nlist *install(char *name, char *defn) 
{   
    struct nlist *np; 
    unsigned hashval; 

    if ((np = lookup(name)) == NULL) { /* not found */ 
        np = (struct nlist *) malloc(sizeof(*np)); 
        if (np == NULL || (np->name = mystrdup(name)) == NULL) 
            return NULL; 
        hashval = hash(name); 
        np->next = hashtab[hashval]; 
        hashtab[hashval] = np; 
    } else       /* already there */ 
        free((void *) np->defn);   /*free previous defn */ 
    if ((np->defn = mystrdup(defn)) == NULL) 
        return NULL; 
    return np; 
}

void undef(char *s)
{
    struct nlist *np, *last; 

    for (last=NULL, np = hashtab[hash(s)]; np != NULL; last=np, np = np->next) {
        if (strcmp(s, np->name) == 0) {
            if (last != NULL)
                last->next = np->next;
            else
                hashtab[hash(s)] = last;
            free(np->name);
            free(np->defn);
            free(np);
        }
    }
}

void printHashTab()
{
    struct nlist *np;

    for (int i = 0; i < HASHSIZE; ++i) {
        for (np = hashtab[i]; np != NULL; np = np->next) 
            printf("%d:%s|%s\n", i, np->name, np->defn);
    }
}

int main(void)
{
    install("test", "definded");
    install("in", "1");
    install("out", "2");
    install("max", "420000000000");
    install("min", "0");
    install("in", "in");
    install("out", "getout");

    printHashTab();

    undef("in");

    printHashTab();
    return 0;
} 
