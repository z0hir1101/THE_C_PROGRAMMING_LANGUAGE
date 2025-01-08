#include  <stdio.h>
#include  <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 5000
#define MAXLEN 1000

int main(int argc, char *argv[])
{
  int rdline(char *, int), ln, nlines = 0, n = 10;
  char *lineptr[MAXLINES], line[MAXLEN], *p;

  while (--argc > 0 && **++argv != '-')
    ;

  if (argc > 0)
    if (!isdigit((*argv)[1]))
      printf("find: illegal option %s\n", *argv);
    else 
      n = abs(atoi(*argv));
 
  while ((ln = rdline(line, MAXLEN)) > 0)
    if (nlines >= MAXLINES || (p=malloc(ln)) == NULL)
      return -1;
    else {
      line[ln-1] = '\0';
      strcpy(p, line);
      lineptr[nlines++] = p;
    }

  while (--nlines > 0 && n-- > 0)
    printf("%s\n", lineptr[nlines]);
  return 0;
}

int rdline(char *s, int lim)
{
  char *fch = s;

  while (--lim>0 && (*s=getchar())!=EOF && *s++!='\n')
    ;
  *s = '\0'; 
  return s-fch;
}

