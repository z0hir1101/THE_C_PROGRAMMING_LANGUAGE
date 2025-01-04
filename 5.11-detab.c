#include  <stdio.h>
#include  <ctype.h>
#include <stdlib.h>
#include   <math.h>
#define TAB      8 

int main(int argc, char *argv[])
{
   int colmn, c, m, n;
   m = 5;
   n = 0;

   while (--argc > 0)
      if (isdigit((*++argv)[1]) && **argv == '-') 
         m = fabs(atoi(*argv));
      else if (isdigit((*++argv)[1]) && **argv == '+')
         n = atoi(*argv);
      else printf("find: illegal option %s\n", *argv);

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
         for (int i = 0; i < colmn; ++i) 
            putchar('-');
         colmn = TAB;
      }
   return 0;
}

