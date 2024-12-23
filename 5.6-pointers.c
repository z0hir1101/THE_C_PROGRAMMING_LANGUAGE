#include  <stdio.h>
#include <string.h>
#include  <ctype.h>

int readline(char *, int);
void itoa(int, char *);
int atoi(char *);
void reverse(char *);
int strindex(char *s, char *t);

int main()
{
   char s[] = "hy are you norm?";
   char t[] = "norm";
   printf("%d\n", strindex(s, t));
}

int readline(char *s, int lim)
{
   char *fch = s;

   while (--lim>0 && (*s=getchar())!=EOF && *s++!='\n')
      ;
   *s = '\0'; 
   return s-fch;
}

void itoa(int n, char *s)
{
   void reverse(char *);

   char *ps = s;
   int sign;
   
   if ((sign = n) < 0) 
      n = -n;
   do {
      *ps++ = n % 10 + '0';
      n /= 10;
   } while (n > 0);
   if (sign < 0)
      *ps++ = '-';
   *ps = '\0';
   reverse(s);
}

int atoi(char *s)
{
   int n, sign;

   for (; isspace(*s); s++)
      ;

   sign = (*s == '-') ? -1 : 1;
   if (*s == '+' || *s == '-')
      s++;

   for (n = 0; isdigit(*s); s++)
      n = 10 * n + (*s - '0');

   return sign * n;
}

void reverse(char *s)
{
   char *lch, c; 
   lch = s + strlen(s) - 1;

   for (; s < lch; lch--, s++) {
      c = *s;
      *s = *lch;
      *lch = c;
   }
}

int strindex(char *s, char *t)
{
   char *ps, *pt;
   for (int i = 0; *s != '\0'; s++, i++) {
      for (ps=s, pt=t; *pt!='\0' && *pt==*ps; pt++, ps++)
         ;
      if (pt - t > 0 && *pt == '\0')
         return i;
   }
   return -1;
}
