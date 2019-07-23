/******************************************************
"Write a cross-referencer that prints a list of all words in a document, 
and, for each word, a list of the line numbers on which it occurs. 
Remove noise words like "the", "and," and so on."

Author: Kant Chan (1126973789@qq.com) 
******************************************************/

#include <stdio.h>


struct wordtree {
    char *word;
    struct wordtree *left;
    struct wordtree *right;
}

int main(void) {
    // read file
    while((c=getchar()) != EOF)
    {
        if (d != ' ' || c != ' ')
            putchar(c);
        d = c;
    }
    // handle word
    // print the tree
    
    return 0;
}
