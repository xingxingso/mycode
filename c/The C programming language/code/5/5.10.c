/******************************************************
"Write the program expr , 
which evaluates a reverse Polish expression from the command line, 
where each operator or operand is a separate argument. 
For example, expr 2 3 4 + * 
evaluates 2 X (3 + 4)."

Author: Kant Chan (1126973789@qq.com) 
******************************************************/

#include <stdio.h>
#include <stdlib.h> /* for atof() */

#define MAXLINE 1000

void push(double);
double pop(void);

int main(int argc, char *argv[])
{
    double t;

    while (*++argv) {
        if (isdigit(**argv))
            push(atof(*argv));
        else         
            switch (**argv) {
                case '+':
                    push(pop()+pop());
                    break;
                case '-':
                    t = pop();
                    push(pop()-t);                   
                    break;
                case '*':
                    push(pop()*pop());
                    break;
                case '/':
                    t = pop();
                    push(pop()/t);
                    break;
                default:
                    break;
            }
    }

    if (argc > 1)
        printf("%f\n", pop());

    printf("%s\n", "close");    
    return 0;
}

#define MAXVAL 100

int sp;
double val[MAXVAL];

void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
    if (sp > 0) 
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}
