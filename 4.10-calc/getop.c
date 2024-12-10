#include <stdio.h>
#include <ctype.h>
#include  "calc.h"
int p = 0;

int getop(char s[], char inp[])
{
   extern int p;
   int i, c, last;
   i = 0;

   while (inp[p]!='\0'&&(inp[p]==' '||inp[i]=='\t'))
      p++; 
   if (!isdigit(s[i++] = c = inp[p++]) && c != '-')
      return c;
   if (c == '-' && !isdigit(inp[p]))
      return c;
   if (isdigit(inp[p]))
      while (isdigit(s[i++] = c = inp[p++]))
         ;
   if (c == '.')
      while (isdigit(c = inp[p++]))
         s[i++] = c;
   s[i] = '\0';
   return NUMBER;
}

