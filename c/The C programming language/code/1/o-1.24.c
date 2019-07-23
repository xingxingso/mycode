/**
 * Write a program to check a C program for rudimentary 
 * syntax errors like unbalanced parentheses, brackets and braces. 
 * Don't forget about quotes, both single and double, 
 * escape sequences, and comments. 
 * (This program is hard if you do it in full generality.)
 */

#include <stdio.h>

#define NOESC 3
#define YES 1
#define NO 0
#define ESC 2
#define MAX 2048
#define START 0

char cr;
int unbc, unbk, unpa, bk, pa, bc;

void sortar(char ar[], int end, int start);



int main(void)
{
  int c[2], bs = 0, eoc = 0, i = -1;
  extern int unbc, unbk, unpa, bk, pa, bc;
  char string, chr, comm[2], bap[MAX], owfl;
  extern char cr;

  unbc = unbk = unpa = bk = pa = bc = 0;
  c[1] = getchar();
  c[0] = '\0';
  string = chr = comm[0] = comm[1] = owfl = NO;
  cr = '\n';

  while (c[1] != EOF && owfl == NO)
  {
      if (string == YES || chr == YES || (comm[0] == NO && comm[1] == NO &&
         (c[1] == '\"' || c[1] == '\''))) {

          if (c[1] == '\\')
              ++bs;

          else if (bs > 0 && c[1] != '\"' && c[1] != '\'')
              bs = 0;

          if (c[1] == '\"' && string == NO && chr == NO)
              string = YES;

          else if (c[1] == '\'' && chr == NO && string == NO)
              chr = YES;

          else if ((c[1] == '\'' || c[1] == '\"') && bs - (bs / 2) * 2 == 0)
          {
              if (c[1] == '\"' && string == YES)
                  string = NO;

              else if (c[1] == '\'' && chr == YES)
                  chr = NO;
          }

          if ((c[1] == '\'' || c[1] == '\"') && bs > 0) {
              bs = 0;
          }
      }

      else if (comm[0] == YES || comm[1] == YES)
      {
          if (c[0] == '*' && c[1] == '/' && comm[0] == YES)
              comm[0] = NO;

          else if (c[1] == '\n' && comm[1] == YES)
              comm[1] = NO;
      }

      else {
          if (c[1] == '{' || c[1] == '}' || c[1] == '(' || c[1] == ')' ||
           c[1] == '[' || c[1] == ']')
          {
              if (i < MAX - 1) {
                  ++i;

              bap[i] = c[1];

              if (c[1] == '}')
                  ++bc;

              else if (c[1] == ']')
                  ++bk;

              else if (c[1] == ')')
                  ++pa;
              }

              else
                  owfl = YES;

          }

          else if (c[1] == '/')
          {
              if (c[0] == '*')
                  ++eoc;

              else {

                  c[0] = c[1];
                  c[1] = getchar();

                  if (c[1] != '*' && c[1] != '/')
                      comm[0] = NOESC;

                  else if (c[1] == '*')
                      comm[0] = ESC;

                  else
                      comm[1] = ESC;
              }
          }
      }

      if (comm[0] != ESC && comm[1] != ESC && comm[0] != NOESC && c[1] != EOF) {
          c[0] = c[1];
          c[1] = getchar();
      }

      else if (comm[0] == ESC)
          comm[0] = YES;

      else if (comm[1] == ESC)
          comm[1] = YES;

      else if (comm[0] == NOESC)
          comm[0] = NO;
  }

  if (i != -1 && owfl == NO)
      sortar(bap, i, START);


  if (unpa != 0)
      printf("\nYou have %d of unmatched parentheses pairs.\n", unpa);

  if (unbk != 0)
      printf("\nYou have %d of unmatched brackets pairs.\n", unbk);

  if (unbc != 0)
      printf("\nYou have %d of unmatched braces pairs.\n", unbc);

  if (eoc != 0)
      printf("\nYou have %d of unmatched comment tails.\n", eoc);

  if (comm[0] == YES)
      printf("\nNo comment tail.\n");

  if (string == YES)
      printf("\nNo string end.\n");

  if (chr == YES)
      printf("\nNo end of character constant.\n");

  if (owfl == YES)
      printf("\nNot enough memory, please increase the value of MAX.\n");

  else if (chr == NO && string == NO && comm[0] == NO && eoc == 0 && unbc == 0 &&
           unbk == 0 && unpa == 0)
      printf("\nNo problems spotted. Good job.\n");

  return 0;
}

void sortar(char ar[], int end, int start)
{
  int i = 0, k = 0, tls[3];
  extern int unbc, unbk, unpa, pa, bc, bk;
  extern char cr;

  for (; k < 3; ++k)
      tls[k] = end + 1;

  if (start == MAX)
      ;

  else if (cr != '\0')
  {
      for (k = start; bc > 0 && ar[k] != '}'; ++k)
          ;

      if (bc > 0)
          tls[0] = k;

      for (k = start; bk > 0 && ar[k] != ']'; ++k)
          ;

      if (bk > 0)
          tls[1] = k;

      for (k = start; pa > 0 && ar[k] != ')'; ++k)
          ;

      if (pa > 0)
          tls[2] = k;

      if (tls[0] + tls[1] > tls[1] + tls[2])
      {
          if (tls[1] > tls[2])
              i = tls[2];

          else
              i = tls[1];
      }

      else if (tls[0] > tls[1])
          i = tls[1];

      else
          i = tls[0];

      if (i == end + 1)
          cr = '\0';

      else {
          cr = ar[i];

          if (cr == '}')
              --bc;

          else if (cr == ']')
              --bk;

          else
              --pa;
      }

      if (cr != '\0')
      {
          if (cr == ')')
          {
              for (k = i - 1; k >= start && ar[k] != '('; --k)
              {
                  if (ar[k] == '{')
                      ++unbc;

                  else if (ar[k] == '[')
                      ++unbk;

                  ar[k] = '\0';
              }

              if (k >= start) {
                  ar[k] = '\0';

                  if (k > start)
                      ar[i] = '\0';

                  else
                      ar[i] = '\n';
              }

              else {
                  ar[i] = '\n';
                  ++unpa;
              }
          }

          if (cr == ']')
          {
              for (k = i - 1; k >= start && ar[k] != '['; --k)
              {
                  if (ar[k] == '{')
                      ++unbc;

                  else if (ar[k] == '(')
                      ++unpa;

                  ar[k] = '\0';
              }

              if (k >= start) {
                  ar[k] = '\0';

                  if (k > start)
                      ar[i] = '\0';

                  else
                      ar[i] = '\n';
              }

              else {
                  ar[i] = '\n';
                  ++unbk;
              }
          }

          if (cr == '}')
          {
              for (k = i - 1; k >= start && ar[k] != '{'; --k)
              {
                  if (ar[k] == '(')
                      ++unpa;

                  else if (ar[k] == '[')
                      ++unbk;

                  ar[k] = '\0';
              }

              if (k >= start) {
                  ar[k] = '\0';

                  if (k > start)
                      ar[i] = '\0';

                  else
                      ar[i] = '\n';
              }

              else {
                  ar[i] = '\n';
                  ++unbc;
              }
          }

          if (ar[i] == '\n')
              start = i + 1;
      }

      sortar(ar, end, start);
  }
  
  else
      for (; start <= end; ++start)

          if (ar[start] == '{')
              ++unbc;

          else if (ar[start] == '[')
              ++unbk;

          else if (ar[start] == '(')
              ++unpa;
}
