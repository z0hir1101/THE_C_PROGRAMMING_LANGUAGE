#include   <stdio.h>
#include   <ctype.h>
#include  <stdlib.h>
#define MAXLINE 1000

int readline(char line[], int maxlen);

int main(int argc, char *argv[])
{
  int ln, i, n, m;
  char line[MAXLINE];
  m = 0;
  n = 8;

  while (--argc>0 && (**++argv=='-' || **argv=='+'))
    if (isdigit((*argv)[1]) && **argv == '-') 
      m = abs(atoi(*argv));
    else if (isdigit((*argv)[1]) && **argv == '+')
      n = atoi(*argv);
    else printf("find: illegal option %s\n", *argv);

  while ((ln = readline(line, MAXLINE)) > 0) {
    if (--ln < m)
      while (ln-- > 0)
        putchar('#');
    else {
      ln -= m;
      for (i = 0; i < m; ++i)
        putchar('-');
      for (i = 0; i < ln - ln%n; ++i)
        putchar('-');
      for (; i < ln; ++i)
        putchar('#');
    }
    putchar('\n');
  }
  return 0;
}

int readline(char *s, int lim)
{
  char *fch = s;

  while (--lim>0 && (*s=getchar())!=EOF && *s++!='\n')
    ;
  *s = '\0'; 
  return s-fch;
}
