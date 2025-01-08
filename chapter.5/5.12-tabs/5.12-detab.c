#include  <stdio.h>
#include  <ctype.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int colmn, i, c, m, n;
  m = 0;
  n = 8;

  while (--argc>0 && (**++argv=='-' || **argv=='+'))
    if (isdigit((*argv)[1]) && **argv == '-') 
      m = abs(atoi(*argv));
    else if (isdigit((*argv)[1]) && **argv == '+')
      n = atoi(*argv);
    else printf("find: illegal option %s\n", *argv);

  colmn = 0;
  while ((c = getchar()) != EOF) {
    if (c != '\t') {
      colmn -= (c == '\n') ? colmn : -1;
      putchar(c);
      continue;
    }
    if (colmn < m) 
      for (i = 0; i < m; ++i) 
        putchar('-');
    else
      for (i = 0; i < n - (colmn - m) % n; ++i)
        putchar('-');
  }
  return 0;
}

