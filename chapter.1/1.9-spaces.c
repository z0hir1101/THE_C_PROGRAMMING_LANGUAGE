#include <stdio.h>

int main()
{
  int c, is_space;

  is_space = 0;
  while ((c = getchar()) != EOF)
    if (!is_space) {
      putchar(c);
      if (c == ' ')
        is_space = 1;
    }
    else if (c != ' ') {
      putchar(c);
      is_space = 0;
    }
}
