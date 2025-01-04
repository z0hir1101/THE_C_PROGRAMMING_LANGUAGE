#include   <stdio.h>
#include   <ctype.h>
#include  <stdlib.h>
#include    <math.h>

#define MAXLINE 1000
#define TAB 8

int readline(char line[], int maxlen);

int main(int argc, char *argv[])
{
  int len, n, m;
  char line[MAXLINE];
  m = 5;
  n = 0;

  while (--argc > 0)
    if (isdigit((*++argv)[1]) && **argv == '-') 
      m = fabs(atoi(*argv));
    else if (isdigit((*argv)[1]) && **argv == '+')
      n = atoi(*argv);
    else printf("find: illegal option %s\n", *argv);

  while ((len = readline(line, MAXLINE)) > 1) {
    --len; 
    while (len >= TAB) {
      len -= TAB;
      putchar('\t');
    }
    while (len > 0) {
      len -= 1;
      putchar('#');
    }
    putchar('\n');
  }

  return 0;
}

int readline(char s[], int max)
{
  int c, i;

  for (i = 0; i<max-1 && (c=getchar())!=EOF && c!='\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = '\n';
    ++i;
  }
  s[i] = '\0';
  return i;
}
