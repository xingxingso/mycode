/******************************************************
"Write a program that reads a C program and prints in alphabetical order 
each group of variable names that are identical in the first 6 characters 
but different somewhere thereafter. 
Don't count words within strings and comments. 
Make 6 a parameter that can be set from the command line."
******************************************************/

#define _CRT_SECURE_NO_DEPRECATE 
#define _CRT_NONSTDC_NO_DEPRECATE 
 
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
 
struct tnode                //树的节点
{
    char *word;             //指向单词的指针
    int match;              //是否打印
    struct tnode *left;     //左子节点
    struct tnode *right;    //右子节点
};
 
#define MAXWORD 100
#define YES     1
#define NO      0
 
struct tnode *addtreex(struct tnode *, char *, int, int *);
void treexprint(struct tnode *);
int getword(char *, int);
 
int main(int argc,char *argv[])
{
    struct tnode *root;
    char word[MAXWORD];
    int found = NO;
    int num;
 
    num = (--argc && (*++argv)[0] == '-') ? atoi(argv[0] + 1) : 6;
    root = NULL;
 
    while (getword(word, MAXWORD) != EOF)
    {
        if (isalpha(word[0]) && strlen(word) >= num)
        {
            root = addtreex(root, word, num, &found);
        }
        found = NO;
    }
    treexprint(root);
    return 0;
}
 
//返回出来永远是返回头节点
struct tnode *addtreex(struct tnode *p, char *w, int num, int *found)
{
    int cond;
 
        if (p == NULL)      //该单词是一个新单词
    {
        //p = talloc(); //创建一个新节点
        p = (struct tnode *)malloc(sizeof(struct tnode));
        p->word = strdup(w);
        p->match = *found;
        p->left = p->right = NULL;
    }
    else if ((cond = compare(w, p, num, found)) < 0)    //首字母ASCALL比当前节点单词的首字母ASCALL的值小
    {
        p->left = addtreex(p->left, w, num, found);
    }
    else if (cond>0)    //首字母ASCALL比当前节点单词的首字母ASCALL的值大  或者 前六个字母相同的新单词
    {
        p->right = addtreex(p->right, w, num, found);
    }
    return p;
}
 
int compare(char *s, struct tnode *p, int num, int *found)
{
    int i;
    char *t = p->word;
 
    for (i = 0; *s == *t; i++, s++, t++)
    {
        if (*s == '\0')
        {
            //输入的单词和结构里的单词匹配
            return 0;
        }
    }
    //单词长度>num 默认为6
    if (i >= num)
    {
        *found = YES;
        p->match = YES;
    }
    //返回首字母ASCII码之差
    return *s - *t;
}
 
void treexprint(struct tnode *p)
{
    if (p != NULL)
    {
        treexprint(p->left);
        if (p->match)
        {
            printf("%s\n", p->word);
        }
        treexprint(p->right);
    }
}
 
int getch2(void);
void ungetch2(int);
 
int comment(void)
{
    int c;
    while ((c = getch2()) != EOF)
    {
        if (c == '*')
        {
            if ((c = getch2()) == '/')
            {
                break;
            }
            else
            {
                ungetch2(c);
            }
        }
    }
    return c;
}
 
//从输入中读取下一个单词或字符
//lim是限制最长的长度
int getword(char *word, int lim)
{
    int comment(void);
    int c, d;
    char *w = word;
 
    while (isspace(c = getch2()))
        ;
 
    if (c != EOF)
    {
        *w++ = c;
    }
    if (isalpha(c) || c == '_' || c == '#')
    {
        for (; --lim; w++)  //填充字符 
        {
            if (!isalnum(*w = getch2()) && *w != '_')
            {
                ungetch2(*w);
                break;
            }
        }
    }
    else if (c == '\'' || c == '"')
    {
        for (; --lim > 0; w++)
        {
            if ((*w = getch2()) == '\\')    //???
            {
                *++w = getch2();
            }
            else if (*w == c)   //碰到堆成的符号
            {
                w++;
                break;
            }
            else if (*w == EOF)
            {
                break;
            }
 
        }
    }
    else if (c == '/')
    {
        if ((d = getch2()) == '*')
        {
            c = comment();  //忽略注释的内容
        }
        else
        {
            ungetch2(d);
        }
    }
    *w = '\0';
    return c;
}
 
#define BUFSIZE 100
 
char buf[BUFSIZE];
int bufp = 0;
 
int getch2(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}
 
void ungetch2(int c)
{
    if (bufp >= BUFSIZE)
    {
        printf("ungetch:too many characters\n");
    }
    else
    {
        buf[bufp++] = c;
    }
}

char *strdup(char *s) /* make a duplicate of s */
{
    char *p;
    
    p = (char *) malloc(strlen(s)+1); /* +1 for '\0' */
    if (p != NULL)
        strcpy(p, s);
    return p;
}
