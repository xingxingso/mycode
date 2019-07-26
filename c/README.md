# The C programming language

> [K&R2 solutions - clc-wiki](https://clc-wiki.net/wiki/K&R2_solutions)

- `Ctrl + D`: 结束输入 EOF 

```bash
$ gcc ../c/The\ C\ programming\ language/code/1/hello.c
$ clang ../c/The\ C\ programming\ language/code/1/hello.c
$ ./a.out
```

```bash
$ ./a.out < c_tcpl_code_6.3.txt
$ cat ./c_tcpl_code_6.3.txt | ./a.out
```

## func

```c
#include <stdio.h>

printf();
// printf("Blanks: %d\nTabs: %d\nLines: %d\n", blanks, tabs, newlines);
// printf("%s\n", s);
// printf("%f\n", val);
// double val[MAXVAL]; /* value stack */
// printf("\t%.8g\n", val[sp-1]);

getchar();
// while((c=getchar()) != EOF)...

putchar(c);

#include <string.h>

strlen(s);

strcmp(s1, s2);
//if ((cond = strcmp(word, tab[mid].word)) < 0)

strcpy(p, s);
// char *strcpy(char *dest, const char *src)

#include <ctype.h>

isspace(c);
isdigit(c);
isalpha(c);
isalnum(c);

#include <stdlib.h>

atof(s);

malloc(sizeof(struct tnode))
/*struct tnode *talloc(void)
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}*/

#include <time.h>

clock();
// time_taken = clock();
```
