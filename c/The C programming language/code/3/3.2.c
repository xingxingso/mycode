/******************************************************
"Write a function escape(s,t) 
that converts characters like newline 
and tab into visible escape sequences like \n and \t 
as it copies the string t to s . Use a switch . 
Write a function for the other direction as well, 
converting escape sequences into the real characters."

Author: Kant Chan (1126973789@qq.com) 
******************************************************/

#include <stdio.h>

void escape(char s[], char t[]);
void unescape(char s[], char t[]);

int main(void)
{
    char s[] = "abewrres";
    char t[] = "wer <w></w>\twerw <wer>	</wer>	<escape> </escape> \nwerwe we123      werwrw   wer1  ww ewqqe,r'q'w;/wer.`";

    // escape(s, t);
    unescape(s, t);

    printf("%s\n", s);

    return 0;
}

void escape(char s[], char t[])
{
    int i, j;

    for (i = j = 0; t[i] != '\0'; ++i)
    {
        switch (t[i]){
            case '\n':
                s[j] = '\\';
                s[++j] = 'n';
                break;
            case '\t':
                s[j] = '\\';
                s[++j] = 't';
                break;
            /*case ' ':
                s[j] = '\\';
                s[++j] = 's';
                break;*/
            default:
                s[j] = t[i];
                break;
        }

    	// putchar(s[j]);
        ++j;
    }

    s[j] = '\0';
}


void unescape(char s[], char t[])
{
    int i, j;

    for (i = j = 0; t[i]!='\0'; ++i)
    {
        if (t[i] != '\\')
        {
            s[j] = t[i];
        }
        else {b
            switch(t[++i])
            {
                case '\0':
                    --i;
                    --j;
                    break;
                case 't':
                    s[j] = '\t';
                    break;
                case 'n':
                    s[j] = '\n';
                    break;
                default:
                    s[j] = '\\';
                    s[++j] = t[i];
                    break;
            }
        }
        ++j;
    }

    s[j] = '\0';
}
