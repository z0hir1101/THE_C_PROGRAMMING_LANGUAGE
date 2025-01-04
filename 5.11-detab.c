#include  <stdio.h>
#include <stdlib.h>

#define MAXLEN 1000
#define TAB 8 

int main(int argc, char *argv[])
{
  int colmn, pos_array[MAXLEN], i, j, l;
  colmn = 0;

  for (i = 0; --argc > 0 && i < MAXLEN; ++i)
    if (!isdigit(**++argv)) 
      pos_array[i] = atoi(*argv);
    else 
      printf("find: illegal option %s\n", *argv);

  for (j = 0; j < i; j++) {
    for (l = 0; l < pos_array[j] - colmn; ++l, ++colmn)
      putchar(' ');
    for (l = 0; l < TAB-pos_array[j]%TAB; ++l, ++colmn)
      putchar('-');
  }
  return 0;
}
