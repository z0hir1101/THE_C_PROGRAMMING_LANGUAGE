#include  <stdio.h>
#include <stdlib.h>
#include  <ctype.h>
#define MAXLINE 100
#define MAXARG 1000

int main(int argc, char *argv[])
{
  int tab_stop[MAXARG] = { 8, 16, 24, 32, 40, 48 };
  int readline(char *, int), *p, ln, i;
  char line[MAXLINE];
  p = tab_stop;

  while (--argc > 0 && p != NULL)
    if (!isdigit(**++argv)) 
      printf("find: illegal option %s\n", *argv);
    else 
      *p++ = atoi(*argv);

  p = tab_stop;
  while ((ln = readline(line, MAXLINE)) > 0) {
    ln--;
    if (*p > ln)
      while (ln-- > 0)
        putchar('#');
    else {
      for (; p+1 != NULL && *(p+1) < ln; p++)
        ; 
      for (i = 0; i < *p; ++i)
        putchar('-');
      for (; i < ln; ++i)
        putchar('#'); 
    }
    putchar('\n');
    p = tab_stop;
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
