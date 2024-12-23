#include  <stdio.h>
#include <stdlib.h>
#include <string.h>

void itob(int, char[], int);
void reverse(char[]);

int main()
{
   char s[5] = "    ";
   itob(31, s, 16);
   printf("%s\n", s);

   return 0;
}

void itob(int nt, char s[], int bt)
{
   int i = 0;
   long sign, n, b;
   n = (long)nt;
   b = (long)bt;
   
   if ((sign = n) < 0) 
      n = -n;

   do {
      s[i++] = (n%b < 10) ? n%b+'0' : (n%b%10)+'A';
      n /= b;
   } while (n > 0);
   if (sign < 0)
      s[i++] = '-';
   s[i] = '\0';
   reverse(s);
}

void reverse(char s[])
{
   int c, i, j;

   for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
      c = s[i];
      s[i] = s[j];
      s[j] = c;
   }
}
