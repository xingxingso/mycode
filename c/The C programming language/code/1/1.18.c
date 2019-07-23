/**
 * Write a program to remove all trailing blanks and tabs from each line of input, 
 * and to delete entirely blank lines.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXQUEUE 10

int advance(int pointer)
{
  if (pointer < MAXQUEUE - 1)
    return pointer + 1;
  else
    return 0;
}

int main(void)
{
  char blank[MAXQUEUE];
  int head, tail;
  int nonspace;
  int retval;
  int c;

  retval = nonspace = head = tail = 0;
  while ((c = getchar()) != EOF) {
    if (c == '\n') {
      head = tail = 0;
      if (nonspace)
        putchar('\n');
      nonspace = 0;
    }
    else if (c == ' ' || c == '\t') {
      if (advance(head) == tail) {
        putchar(blank[tail]);
        tail = advance(tail);
        nonspace = 1;
        retval = EXIT_FAILURE;
      }

      blank[head] = c;
      head = advance(head);
    }
    else {
      while (head != tail) {
        putchar(blank[tail]);
        tail = advance(tail);
      }
      putchar(c);
      nonspace = 1;
    }
  }

  return retval;
}

/*#include <stdio.h>

#define MAXLENGTH 10

// void circle_print(char s[], int lim, int f, int end);

int main(void)
{
    int c, f, i, hasword;
    char s[MAXLENGTH];
    hasword = f = 0;

    while((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t')
        {            
            if (f >= MAXLENGTH)
            {
                f = 0;
            }
            s[f] = c; 
            ++f;
        } else if (c == '\n')
        {
            if (hasword != 0)
            {
                putchar('\n');
            }
            f = 0;
            hasword = 0;

        } else {
             hasword = 1;

            for (i = 0; i < f; ++i)
            {
                putchar(s[i]);
            }

            putchar(c);

            f = 0;
        }

    }

    return 0;
}*/
