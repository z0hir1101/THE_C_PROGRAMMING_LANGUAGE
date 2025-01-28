#include <stdio.h>

int main()
{
  int c, tb, sp, nl;

  tb = sp = nl = 0;
  while ((c = getchar()) != EOF)
    if (c == ' ') sp++;
    else if (c == '\t') tb++;
    else if (c == '\n') nl++;
    else putchar(c);
  printf("sp: %d, tb: %d, nl: %d\n", sp, tb, nl);
}
