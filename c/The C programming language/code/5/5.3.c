/******************************************************
"Write a pointer version of the function strcat that we showed in Chapter 2: 
strcat(s,t) copies the string t to the end of s ."

Author: Kant Chan (1126973789@qq.com) 
******************************************************/

#include <stdio.h>

void strcat2(char *s, char *t);

int main(void)
{
    // char *s = "ae123er";
    char *s = "";
    char *t = " 0";

    strcat2(s, t);

    printf("%s\n", s);

    return 0;
}

void strcat2(char *s, char *t)
{
    // while (*s++ != '\0');    // error
    // while(*++s);  /* Get to the end of the string */
    /*This statement is fine when s is not empty, and when s ="", 
    it will not get the expected answer.*/
    for (; *s != '\0'; s++);

    while (*s++ = *t++);
}

/* strcat: concatenate t to end of s; s must be big enough */
void strcat(char s[], char t[])
{
    int i, j;
    i = j = 0;
    while (s[i] != '\0') /* find end of s */
        i++;
    while ((s[i++] = t[j++]) != '\0') /* copy t */
        ;
}
