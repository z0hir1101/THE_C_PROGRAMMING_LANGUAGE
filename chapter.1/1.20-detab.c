#include <stdio.h>
#define TAB 8 

int main()
{
  int colmn, c, i;

  colmn = TAB;
  while ((c = getchar()) != EOF)
    if (c != '\t') {
      putchar(c);
      if (c == '\n') colmn = TAB;
      else if (colmn == 0) colmn = TAB - 1;
      else --colmn;
    }
    else {
      if (colmn == 0) colmn = 8;
      for (i = 0; i < colmn; ++i) 
        putchar('-');
      colmn = TAB;
    }
  return 0;
}

