#include <stdio.h>
#define tablen 8 

int main()
{
  int colmn, c, i;

  colmn = tablen;
  while ((c = getchar()) != '@') {
    if (c != '\t') {
      putchar(c);
      if (c == '\n') colmn = tablen;
      else if (colmn == 0) colmn = tablen - 1;
      else --colmn;
    }
    else {
      if (colmn == 0) colmn = 8;
      for (i = 0; i < colmn; ++i) 
        putchar('-');
      colmn = tablen;
    }
  } 
  return 0;
}

