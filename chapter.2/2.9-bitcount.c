#include <stdio.h>
#include  <math.h>

int bitcount(unsigned x);

int main()
{
  printf("%d\n", bitcount(13, 2));
  return 0;
}

int bitcount(unsigned x)
{
  int cntr = 0;

  while (x != 0) {
    cntr += 1;
    x &= x-1;
  }
  return cntr;
}
