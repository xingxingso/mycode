/******************************************************
"Add commands to print the top element of the stack without popping, 
to duplicate it, 
and to swap the top two elements. Add a command to clear the stack."

Author: Kant Chan (1126973789@qq.com) 
******************************************************/

#include <stdio.h>

int main(void)
{
    return 0;
}

#define MAXVAL 100 /* maximum depth of val stack */
int sp = 0; /* next free stack position */
double val[MAXVAL]; /* value stack */

/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

double printpop(void)
{
    if (sp > 0)
        printf("\t%.8g\n", val[sp-1]);
    else { 
        printf("error: stack empty\n");
        return 0.0;
    }
}

double copypop(void)
{
    if (sp > 0)
        return val[sp-1];
    else { 
        printf("error: stack empty\n");
        return 0.0;
    }
}

void swap(void)
{
    int tmp;

    if (sp < 2)
    {
        printf("error: stack don't have two number");
        return 0.0;
    }
    else {
        tmp = val[sp-1];
        val[sp-1] = val[sp-2];
        val[sp-2] = tmp;
    }
}

void clear(void)
{
    sp = 0;
}
