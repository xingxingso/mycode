/******************************************************
"Write a cross-referencer that prints a list of all words in a document, 
and, for each word, a list of the line numbers on which it occurs. 
Remove noise words like "the", "and," and so on."

Author: Kant Chan (1126973789@qq.com) 
******************************************************/

#include <stdio.h>
#include <ctype.h>

// #include "../../helper/getword.h"
// #include "../../helper/getline.h"

#define MAX_BUFFER   1024

struct wordtree {
    char *word;
    int count;
    struct wordtree *left;
    struct wordtree *right;
};

int main(void) {
    int c;
    char  Buffer[MAX_BUFFER];
    char *word;
    int lines = 1;


    /*read file*/
    while((c=getchar()) != EOF) {
        printf("%c", c);
        break;
        if (c == '\n') {
            lines++;
            continue;
        }

        while (!isalpha(c)) {
            c = getchar();
        }

        while(isalpha(c)) {
            *word++=c;
        }

        *word = '\0';    
        printf("%s\n", word);
    }
    
    /*handle word*/
    /*print the tree*/
      
    return 0;
}
