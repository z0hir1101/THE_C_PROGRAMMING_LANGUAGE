#include <stdio.h>
#include <math.h>

unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, unsigned y);
unsigned invertbits(unsigned x, int p, int n);
unsigned rightrot(unsigned x, int n);
unsigned bitcount(unsigned x);

int main()
{
   printf("%d\n", rightrot(13, 2));
   return 0;
}

unsigned getbits(unsigned x, int p, int n)
{
   return (x >> (p-n+1)) & ~(~0 << n);
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
   unsigned n1, n2;
   n1 = getbits(y, n-1, n) << (p-n+1);
   n1 = (n1 | ~(~0 << (p-n+1))) | (~0 << (p+1));
   n2 = ((~0 << (p-n+1)) & ~(~0 << p+1)) | x;
   return n2 & n1;
}

unsigned invertbits(unsigned x, int p, int n)
{
   int revbits = ~(getbits(x, p, n));
   setbits(x, p, n, revbits);
}

unsigned rightrot(unsigned x, int n)
{
   int p, integer;
   p = 0;
   while (pow(2, p) < x)
      ++p;
   --p;
   integer = getbits(x, p, p-n+1);
   return setbits(integer, p, p-n+1, x);
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
