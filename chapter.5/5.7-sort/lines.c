#include  <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLEN 1000

int readlines(char *lineptr[], int ml)
{
  int ln, nlines, rdline(char *, int);
  char *p, line[MAXLEN], buf[MAXLEN * ml];

  nlines = 0;
  for (p = buf; (ln = rdline(line, MAXLEN)) > 0; p+=ln)
    if (nlines >= ml)
      return -1;
    else {
      line[ln-1] = '\0';
      strcpy(p, line);
      lineptr[nlines++] = p;
    }
  return nlines;
}

int rdline(char *s, int lim)
{
  char *fch = s;

  while (--lim>0 && (*s=getchar())!=EOF && *s++!='\n')
    ;
  *s = '\0'; 
  return s-fch;
}

void writelines(char *lineptr[], int nlines)
{
  while (nlines-- > 0)
    printf("%s\n", *lineptr++);
}
