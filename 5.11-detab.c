#include  <stdio.h>
#include  <ctype.h>
#include <stdlib.h>
#define MAXLEN 1000

int main(int argc, char *argv[])
{
  int colmn, tab_stop[MAXLEN], *p, i, c;
  p = tab_stop;
  colmn = 1;

  while (--argc > 0 && p != NULL)
    if (!isdigit(**++argv)) 
      printf("find: illegal option %s\n", *argv);
    else 
      *p++ = atoi(*argv);

  p = tab_stop;
  while ((c = getchar()) != EOF)
    if (c == '\t') {
      for (; *p < colmn && p != NULL; p++)
        ;
      for (i = 0; i <= *p - colmn; ++i)
        putchar('#');
      colmn = *p + 1;
    } else { 
      colmn++;
      if (c == '\n') {
        p = tab_stop;
        colmn = 1;
      }
      putchar(c);
    }
  return 0;
}

