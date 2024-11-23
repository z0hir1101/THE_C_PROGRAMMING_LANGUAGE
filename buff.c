#include  <stdio.h>
#include <string.h>
#define BUFSIZE 100

static int buf[BUFSIZE];
static int bufp = 0;

int getch()
{
   return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
   if (bufp > BUFSIZE)
      printf("ungetch: so many characters");
   else { 
      int i;
      for (i = bufp++; i > 0; --i)
         buf[i] = buf[i-1];
      buf[0] = c;
   }
}

void ungets(char s[])
{
   for (int ln = strlen(s)-1; ln > 0; --ln) 
     ungetch(s[ln]); 
}
