/******************************************************
"Write a program that converts upper case to lower or lower case to upper, 
depending on the name it is invoked with, as found in argv[0]."

Author: Kant Chan (1126973789@qq.com) 
******************************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main (int argc, char *argv[])
{
    int (*convert)(int c) = NULL;
    int c = 0;

    if (argc <= 0) {
        printf("need more arguments\n");
        return -1;
    }

    if(0 == strcmp(argv[0], "./lower")) 
        convert = tolower;
    else if(0 == strcmp(argv[0], "./upper"))
        convert = toupper;
    
    while((c = getchar()) != EOF) {
        if (convert != NULL) 
            putchar((*convert)(c));
        else
            putchar(c);
    }

    return 0;
}
