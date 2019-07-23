/******************************************************
"Write a program that reads a C program and prints in alphabetical order 
each group of variable names that are identical in the first 6 characters 
but different somewhere thereafter. 
Don't count words within strings and comments. 
Make 6 a parameter that can be set from the command line."
******************************************************/

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
 
#define MAXWORD 100
 
extern int getword(char *word, int lim);
struct tnode *addtree(struct tnode *, char *);      /* 二叉树tnode，每个节点存放一个word以及其出现的次数 */
struct maketree *mtree(struct maketree *, char *);/*  二叉树maketree，每个节点指向一棵二叉树tnode */
void trreprint(struct tnode *);         /*  打印二叉树tnode */
void actreeprint(struct maketree *);    /*  打印二叉树maketree */
struct tnode *talloc(void);         /*  为树tnode申请储存空间 */
struct maketree *atalloc(void);     /*  为树maketree申请储存空间 */
char *strduper(char *s);            /*  word存放在一个安全的地方 */
int num;
struct tnode {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};
 
struct maketree {
    int count;              /*  每个节点出现的次数 */
    struct tnode *nroot;    /*  指向一棵tnode二叉树 */
    struct maketree *left;  /*  左子树 */
    struct maketree *right;/*   右子树 */
};
/*  编写程序，按字母顺序打印文本中的变量名，每一组内各变量前6个字符相同，其余字符不同，不考虑注释、字符常量等，6可在命令行中更改 */
main(int argc, char *argv[]) {
    struct maketree *root;
    char word[MAXWORD];
 
    root=NULL;
    num=(--argc>0&&(**(++argv)=='-'))?atoi(++(*argv)):6;
    while(getword(word,MAXWORD)!=EOF &&(sizeof word/sizeof(char)) >=num)
        if(isalpha(word[0])||word[0]=='_')
            root=mtree(root,word);
    actreeprint(root);
    return 0;
}
struct tnode *addtree(struct tnode *p, char *w) {
    int cond;
 
    if(p==NULL) {
        p=talloc();
        p->word=strduper(w);
        p->count=1;
        p->left=p->right=NULL;
 
    } else if ((cond= strcmp(w,p->word))==0)
        p->count++;
    else if (cond <0)
        p->left=addtree(p->left,w);
    else 
        p->right=addtree(p->right,w);
    return p;
}
 
struct maketree *mtree(struct maketree *aroot, char *w) {
    
    int cond;
 
    if(aroot==NULL) {
        aroot=atalloc();
        aroot->nroot=NULL;
        aroot->nroot=addtree(aroot->nroot,w);           /*  将word传递给二叉树tnode */
        aroot->left=aroot->right=NULL;
        aroot->count=1;
    } else if ((cond=strncmp(w,aroot->nroot->word,num))==0) {
        addtree(aroot->nroot,w);
        aroot->count++; 
    } else if (cond <0)
        aroot->left=mtree(aroot->left,w);
    else 
        aroot->right=mtree(aroot->right,w);
    return aroot;
 
}
 
struct tnode *talloc(void) {
    return (struct tnode *) malloc(sizeof(struct tnode));
 
}
struct maketree *atalloc(void) {
    return (struct maketree *) malloc(sizeof(struct maketree));
}
char *strduper(char *s) {
    char *p;
 
    p=(char *)malloc(strlen(s)+1);
    if(p!=NULL)
        strcpy(p,s);
    return p;   
}
 
void treeprint(struct tnode *p) {
    if(p!=NULL) {
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}
void actreeprint(struct maketree *p) {
    if(p!=NULL)
    {
        actreeprint(p->left);
        treeprint(p->nroot);
        printf("\n");
        actreeprint(p->right);
    }
}
