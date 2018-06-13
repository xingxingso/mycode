/******************************************************
"Write a program to remove all comments from a C program. 
Don't forget to handle quoted strings and character 
constants properly. C comments do not nest."

Author: Kant Chan (1126973789@qq.com) 
******************************************************/

#include <stdio.h>

void put_in_quto(int type);
void delete_commments(int type);

int main(void)
{
    int one, two;
    /*//elseone*/
    while((one=getchar()) != EOF) 
    {
        if (one == '/')
        {
            two = getchar();
            if (two=='/' || two=='*')
            {
                delete_commments(two);
            }
            else if (two=='\'' || two=='"')
            {
                putchar(one);
                putchar(two);
                put_in_quto(two);
            }
            else
            {
                putchar(one);
                putchar(two);
            }
        }
        else if (one=='\'' || one=='"')
        {
            putchar(one);
            put_in_quto(one);
        }
        else
        {
            putchar(one);
        }
    }
}

// write the characters in quto
void put_in_quto(int type)
{
    int c, in_quto = 1;

    while (in_quto && (c=getchar())!=EOF)
    {
        if (c == type)
        {
            in_quto = 0;
            putchar(c);
        }
        else if(c == '\\') {
            putchar(c);
            if((c = getchar()) != EOF) {
                putchar(c);
            }
        }else {
            putchar(c);
        }
    }
}

// delete the comments
void delete_commments(int type)
{
    int c, in_comments=1;

    if (type == '/')
    {
        while((c=getchar())!=EOF && c!='\n');
        putchar('\n');
    }
    else if(type == '*')
    {        
        // while((c=getchar())!=EOF && !(c=='*' && ((c=getchar())!=EOF && c=='/')));
        // above cant't deal with **/ 
        // The next is corret to handle that
        while(in_comments && (c=getchar())!=EOF)
        {
            if (c == '*')
            {
                while((c=getchar()) == '*');
                if (c=='/')
                {
                    in_comments = 0;
                }
            }
        }
    }
}
