#include <stdio.h>
#include <ctype.h>
#include  "calc.h"

int getch(void);
void ungetch(int);

int getop(char s[])
{
  int i, c, tmp;

  while ((s[0]=c=getch()) == ' ' || c=='\t')
    ;
  s[1] = '\0';
  if (!isdigit(c) && c != '.' && c != '-')
    return c;
  tmp = getch();
  ungetch(tmp);
  if (c == '-' && !isdigit(tmp)) 
    return c;

  i = 0;
  if (isdigit(c) || c == '-')
    while (isdigit(s[++i] = c = getch()))
      ;
  if (c == '.')
    while (isdigit(s[++i] = c = getch()))
      ;
  s[i] = '\0';
  ungetch(c);
  return NUMBER;
}


