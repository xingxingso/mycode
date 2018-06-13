#include <stdio.h>

int main(void)
{
    
    
    int c, tmp;
    tmp = EOF;
    int d = '/';
    char p[] =
"0/!10\"040\'050.001//011/*!21\"/41\'/51./02*!32.!23/ "
"03*!33.!24\"00//4\\064.\\/*/*045\'005\\075./**056.047.05";
    char p1[] =
"//0/!10\"@40\'@50.@01/@11*!2"
"1\"/41\'/5"            
"/*1./02*!32.!23/ 03*!33.!24\"@04\\@64.@45\'@05\\@75.@56.@47.@5";
    
    while((c=getchar()) != EOF)
    {
        
        if (c == '/' && ((tmp=getchar())=='/' || tmp=='*'))
        {
            
            if (tmp == '/') 
            {
                
                
                while((c=getchar())!=EOF && c!='\n');
            }
            else{   
                
                while((c=getchar())!=EOF && !(c=='*' && ((c=getchar())!=EOF && c=='/')));
            }
        }  
        else {    
            putchar(c);

            if (tmp!=EOF && tmp!='/' && tmp!='*')
            {
                putchar(tmp);
                tmp = EOF;
            }
        }
    }

    
    printf("%d\n", 6/'\2');
    
    printf("%d\n", 6/"\2");
    

    return  0;
}

int main1(){int c,i,d;char s,n;s='0';while((c=getchar())
!=EOF){d=0;for(i=0;p[i]!='\0'&&d==0;i=i+4){if(p[i]==s&&
(p[i+1]==c||p[i+1]=='.')){if(p[i+2]=='@')putchar(c);else
if(p[i+2]=='/'){putchar('/');putchar(c);}else if(p[i+2]
==' ')putchar(' ');n=p[i+3];d=1;}}s=n;}return 0;}






#include <stdio.h>

int
main(void)
{
    
    enum {
        PROGRAM,
        SLASH,
        COMMENT,
        STAR,
        QUOTE,
        LITERAL
    } state;

    
    int quote;

    state = PROGRAM;
    for (;;) {
        int c = getchar();
        if (c == EOF) {
            if (state == SLASH)
                putchar('/' 
                        1 / 1 /'\1');
            break;
        }

        if(0)
          printf("%d\n", 6/'\2'); 
        

        switch (state) {
        case SLASH:
            
            if (c == "/*"[1]) {
                state = COMMENT;
                break;
            }
            putchar('/');
            state = PROGRAM;
            

        case PROGRAM:
            
            if (c == '\'' || c == '"') {
                quote = c;
                state = QUOTE;
                putchar(c);
            }
            else if (c == "/*"[0])
                state = SLASH;
            else
                putchar(c);
            break;

        case COMMENT:
            
            if (c == '*')
                state = STAR;
            break;

        case STAR:
            
            if (c == '/')
                state = PROGRAM;
            else if (c != '*') {
                state = COMMENT;
                putchar (' ');
            }
            break;

        case QUOTE:
            
            putchar(c);
            if (c == '\\')
                state = LITERAL;
            else if (c == quote)
                state = PROGRAM;
            break;

        case LITERAL:
            
            putchar(c);
            state = QUOTE;
            break;

        default:
            abort();
        }
    }

    return  0;
}


